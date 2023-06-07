%{
	#include<string.h>
	int yywrap();
    #define YYSTYPE double
	void yyerror(char*);
	#include "calculater.tab.h"
%}

%%

[a-z]	{
            yylval = *yytext - 'a';
            return VARIABLE;
    	}
		

0x\.?[a-f0-9]+|0x[a-f0-9]+\.[a-f0-9]* {
	        yylval=atof(yytext);
		    return HEXADECIMAL;
        }

\.?[0-9]+|[0-9]+\.[0-9]*	{
            yylval = atof(yytext);
            return INTEGER;
    	}

[-+()=/*&|~!^@\n]	{return *yytext;}

pi		{return PI; }

sin 	{ return SIN; }
cos 	{ return COS; }
tan 	{ return TAN; }

log 	{return LOG; }
ln		{return LN;  }
exp 	{return EXP; }
ceil	{return UGU; }
uGuass  {return UGU; }
floor	{return LGU; }
lGuass	{return LGU; }
abs		{return ABS; }

[ \t]   ;

.    	yyerror("無效的輸入字符");

%%

int yywrap() {return 1;}