%{
	#include <stdio.h>   
    #include <math.h>
    #define YYSTYPE double
    #define pi 3.1415926 
	void yyerror(char*);
    int yylex(void);
	
    double sym[26];
	int is_int(float value) { return ((int)value);}
%}

%token   HEXADECIMAL INTEGER VARIABLE 
%token   PI SIN COS TAN LOG LN EXP UGU LGU ABS

%left    '+' '-'
%left    '*' '/'
%left    '&'
%left    '|'
%left    '^'
%right   '@''~'
%left    '!'

%%
program:
    program statement '\n'
    |
    ;
	
		   
statement:
	expr                 					{ printf("ans = %lf\n", $1); }
    |VARIABLE '=' expr    					{ sym[(int)$1] = $3; }
    ;
	
expr:
    INTEGER			  	{ $$ = $1; }
	|HEXADECIMAL	  	{ $$ = $1; }
    |VARIABLE		  	{ $$ = sym[(int)$1]; }
	|'-' expr		  	{ $$ = -$2; }
    |expr '+' expr    	{ $$ = $1 + $3; }
    |expr '-' expr    	{ $$ = $1 - $3; }
    |expr '*' expr    	{ $$ = $1 * $3; }
    |expr '/' expr    	{ $$ = $1 / $3; }
    |expr '&' expr    	{ $$ = (int)$1 & (int)$3; }
    |expr '|' expr    	{ $$ = (int)$1 | (int)$3; }
    |'~' expr         	{ $$ = ~(int)$2; } //取補數
    |'@' expr         	{ $$ = sqrt($2); } //平方根
    |expr '@' expr    	{ $$ = $1*sqrt($3); } 
    |expr '!'         	{ int i=1,s=1; for(;i<=$2;i++) s*=i; $$=s; }
    |expr '^' expr    	{ $$ = pow($1,$3); }
    |'('expr')'       	{ $$ = $2; }
	|PI				  	{ $$ = pi; }
    |SIN'('expr')'    	{ $$ = sin($3*pi/180.0); }
    |COS'('expr')'    	{ $$ = cos($3*pi/180.0); }
    |TAN'('expr')'    	{ $$ = tan($3*pi/180.0); }
	|LOG'('expr')'		{ $$ = log10($3); } //x的常用對數（以10為底）
	|LN'('expr')'		{ $$ = log($3); } //x的自然對數（基-E對數）
	|EXP'(' expr ')'	{ $$ = exp($3); } //值e的第x次方
	|LGU '(' expr ')'	{ $$ = floor($3); } //最大整數值小於或等於x
	|UGU '(' expr ')'	{ $$ = ceil($3); } //大於或等於x的最小整數值
	|ABS '(' expr ')'	{ $$ = fabs($3); } //絕對值
    ;
	
%%

void yyerror(char* s){
    fprintf(stderr, "%s\n", s);
}

int main(void){
    yyparse();
    return 0;
}