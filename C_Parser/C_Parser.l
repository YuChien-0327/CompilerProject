%{
#include<string.h>
#include <stdbool.h>
#include "C_Parser.tab.h"
void yyerror(const char *s);
%}

%%

"string"        { return STRING_TYPE; }
"int"           { return INT_TYPE; }
"float"         { return FLOAT_TYPE; }
"char"          { return CHAR_TYPE; }
"bool"          { return BOOL_TYPE; }
"double"        { return DOUBLE_TYPE; }
"="             { return EQUALS; }
";"             { return SEMICOLON; }
"cout"          { return COUT; }
"cin"           { return CIN; }
"<<"            { return INSERTION_OP; }
">>"            { return EXTRACTION_OP; }
"endl"          { return ENDL; }

"log"			{ return LOG; }
"abs"			{ return ABS; }
"sqrt"    		{ return SQRT; }

\"[^\"]*\"      { yylval.str = strdup(yytext); return STRING; }
\'[^\']\'       { yylval.str = strdup(yytext); return CHAR; }

[-+%/*()]       {return yytext[0];}

[a-zA-Z_][a-zA-Z0-9_]* { yylval.identifier = strdup(yytext); return IDENTIFIER; }
[+-]*[0-9]+          { yylval.integer = atoi(yytext); return INTEGER; }
[0-9]+\.[0-9]+  { yylval.floating = atof(yytext); return FLOAT; }
[ \t\n]         { /* 忽略空格、制表符和换行符 */ }
.               { yyerror("Invalid token"); }
%%

int yywrap() {
    return 1;
}
