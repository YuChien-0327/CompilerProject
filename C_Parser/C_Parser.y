%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef struct {
	int type; // 0: bool, 1: int, 2: char, 3: float, 4: double, 5: string
    char* name;

	bool	val_bool;
	int		val_int;
	char	val_char;
	float	val_float;
	double	val_double;
    char*	val_string;
} Variable;

Variable variables[100];
int numVariables = 0, numFunction = 3;

const char strtokSymbol[2] = "\"";
enum TYPE {
	// 0: bool, 1: int, 2: char, 3: float, 4: double, 5: string
    _BOOL,
    _INT,
    _CHAR,
    _FLOAT,
	_DOUBLE,
	_STRING
};

int yylex();
void yyerror(const char *s);
void print_endl(Variable var);
void print(Variable var);
int findVariable(char* name);
%}

%union {
    char* identifier;
    char* str;
    int integer;
    float floating;
    double doulbes;
    bool boolean;
	char character;
}

%token <identifier> IDENTIFIER
%token <str> STRING
%token <integer> INTEGER
%token <floating> FLOAT
%token <doulbes> DOUBLE
%token <boolean> BOOL
%token <character> CHAR

%token STRING_TYPE INT_TYPE FLOAT_TYPE CHAR_TYPE BOOL_TYPE DOUBLE_TYPE
%token EQUALS SEMICOLON
%token COUT CIN
%token INSERTION_OP EXTRACTION_OP
%token ENDL
%token LOG ABS SQRT

%left '+' '-'
%left '*' '/'
%left '%'
%left '(' ')'


%%

program: statement
       | program statement
       ;

statement: declaration
         | cout_statement
		 | cin_statement
		 | assignment
         ;

declaration: declare_str
           | declare_char
           | declare_int
           | declare_float
           | declare_double
           | declare_bool
		   ;

cout_statement: COUT INSERTION_OP IDENTIFIER INSERTION_OP ENDL SEMICOLON
			{
				int i;
				for (i = 0; i < numVariables; i++) {
					if (strcmp(variables[i].name, $3) == 0){
						print_endl(variables[i]);
						break;
					}
				}
				if (i == numVariables) {
					printf(".. Variable %s not found\n", $3);
				}
			}
			| 
			COUT INSERTION_OP IDENTIFIER SEMICOLON
			{
				int i;
				for (i = 0; i < numVariables; i++) {
					if (strcmp(variables[i].name, $3) == 0){
						print(variables[i]);
						break;
					}
				}
				if (i == numVariables) {
					printf(".. Variable %s not found\n", $3);
				}
			}
			;
cin_statement: CIN EXTRACTION_OP IDENTIFIER SEMICOLON
			{
				int i;
				for (i = 0; i < numVariables; i++) {
				 if (strcmp(variables[i].name, $3) == 0) {
					if(variables[i].type == _BOOL){ //bool
					
					}else if(variables[i].type == _INT){
						int input;
						scanf("%d", &input);
						variables[i].val_int = input;
					}else if(variables[i].type == _CHAR){ //char
						
					}else if(variables[i].type == _FLOAT){
						float input;
						scanf("%f", &input);
						variables[i].val_float = input;
					}else if(variables[i].type == _DOUBLE){
						double input;
						scanf("%lf", &input);
						variables[i].val_double = input;
					}else if(variables[i].type == _STRING){
						char input[100];
						scanf("%s", input);
						variables[i].val_string = strdup(input);
					}else { 
						printf("Variable %s is not a type\n", variables[i].name);
					}
					break;
					}
				}
				if (i == numVariables) {
					printf("Variable %s not found\n", $3);
				}
			}
			;

assignment: assignSingle
			| operation
			;

assignSingle: IDENTIFIER EQUALS INTEGER SEMICOLON
			{
				int idx;
				for (idx = 0; idx < numVariables; idx++) 
					if (strcmp(variables[idx].name, $1) == 0) break; 
				if (idx == numVariables) printf(".. Variable %s not found\n", $1);
				else if(variables[idx].type == _INT){
					variables[idx].val_int = $3;
					printf(".. Variable %s is assigned to be %d\n", variables[idx].name, variables[idx].val_int);
				}
				else if(variables[idx].type == _FLOAT){
					variables[idx].val_float = $3 / 1.0;
					printf(".. Variable %s is assigned to be %f\n", variables[idx].name, variables[idx].val_float);
				}
				else if(variables[idx].type == _DOUBLE){
					variables[idx].val_double = (double)$3;
					printf(".. Variable %s is assigned to be %lf\n", variables[idx].name, variables[idx].val_double);
				}
				else printf(".. TypeError: Type of variable %s is not an integer\n", $1);
			}
			| IDENTIFIER EQUALS FLOAT SEMICOLON
			{
				int idx;
				for (idx = 0; idx < numVariables; idx++) 
					if (strcmp(variables[idx].name, $1) == 0) break; 
				if (idx == numVariables) printf(".. Variable %s not found\n", $1);
				else if(variables[idx].type == _FLOAT){
					variables[idx].val_float = $3;
					printf(".. Variable %s is assigned to be %f\n", variables[idx].name, variables[idx].val_float);
				}
				else if(variables[idx].type == _DOUBLE){
					variables[idx].val_double = (double)$3;
					printf(".. Variable %s is assigned to be %lf\n", variables[idx].name, variables[idx].val_double);
				}
				else printf(".. TypeError: Type of variable %s is not a floating or double\n", $1);
			}
			| IDENTIFIER EQUALS DOUBLE SEMICOLON
			{
				int idx;
				for (idx = 0; idx < numVariables; idx++) 
					if (strcmp(variables[idx].name, $1) == 0) break; 
				if (idx == numVariables) printf(".. Variable %s not found\n", $1);
				else if(variables[idx].type == _DOUBLE){
					variables[idx].val_double = $3;
					printf(".. Variable %s is assigned to be %lf\n", variables[idx].name, variables[idx].val_double);
				}
				else printf(".. TypeError: Type of variable %s is not a double\n", $1);
			}
			| IDENTIFIER EQUALS STRING SEMICOLON
			{
				int idx;
				for (idx = 0; idx < numVariables; idx++) 
					if (strcmp(variables[idx].name, $1) == 0) break; 
				if (idx == numVariables) printf(".. Variable %s not found\n", $1);
				else if(variables[idx].type == _STRING){
					variables[idx].val_string = $3;
					printf(".. Variable %s is assigned to be %d\n", variables[idx].name, variables[idx].val_string);
				}
				else printf(".. TypeError: Type of variable %s is not a string\n", $1);
			}
			;
	
operation: add
		| sub	
		| mul
		| div
		| mod
		| function
		;

add:IDENTIFIER EQUALS IDENTIFIER '+' IDENTIFIER SEMICOLON
	{
		int id1 = findVariable($1);
		int id3 = findVariable($3);
		int id5 = findVariable($5);

		if(id1 >= 0 && id3 >= 0 && id5 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _INT:
					if((variables[id3].type == _INT) && (variables[id5].type == _INT)){
						variables[id1].val_int = variables[id3].val_int + variables[id5].val_int;
						printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _FLOAT:
					if(	(variables[id3].type == _INT || variables[id3].type == _FLOAT) && 
						(variables[id5].type == _INT || variables[id5].type == _FLOAT)){
						
						float f3, f5;
						if(variables[id3].type == _INT) f3 = variables[id3].val_int / 1.0;
						else if(variables[id3].type == _FLOAT) f3 = variables[id3].val_float;
						
						if(variables[id5].type == _INT) f5 = variables[id5].val_int / 1.0;
						else if(variables[id5].type == _FLOAT) f5 = variables[id5].val_float;
						
						variables[id1].val_float = f3 + f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(	(variables[id3].type == _INT || variables[id3].type == _FLOAT || variables[id3].type == _DOUBLE) && 
						(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE)){
						
						double f3, f5;
						if(variables[id3].type == _INT) f3 = (double)variables[id3].val_int;
						else if(variables[id3].type == _FLOAT) f3 = (double)variables[id3].val_float;
						else if(variables[id3].type == _DOUBLE) f3 = variables[id3].val_double;
						
						if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
						else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
						else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
						
						variables[id1].val_double = f3 + f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _STRING:
					if((variables[id3].type == _STRING) && (variables[id5].type == _STRING)){
						variables[id1].val_string = strcat(variables[id3].val_string, variables[id5].val_string);
						printf(".. Variable %s is changed to be %s\n", variables[id1].name, variables[id1].val_string);
					}
					else printf(".. TypeError: cannot change var to string\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS IDENTIFIER '+' INTEGER SEMICOLON
	{
		int id1 = findVariable($1);
		int id3 = findVariable($3);

		if(id1 >= 0 && id3 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _INT:
					if(variables[id3].type == _INT){
						variables[id1].val_int = variables[id3].val_int + $5;
						printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _FLOAT:
					if(variables[id3].type == _INT || variables[id3].type == _FLOAT){
						
						float f3, f5 = $5 / 1.0;
						if(variables[id3].type == _INT) f3 = variables[id3].val_int / 1.0;
						else if(variables[id3].type == _FLOAT) f3 = variables[id3].val_float;
						
						variables[id1].val_float = f3 + f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(variables[id3].type == _INT || variables[id3].type == _FLOAT || variables[id3].type == _DOUBLE){
						
						double f3, f5 = (double) $5;
						if(variables[id3].type == _INT) f3 = (double)variables[id3].val_int;
						else if(variables[id3].type == _FLOAT) f3 = (double)variables[id3].val_float;
						else if(variables[id3].type == _DOUBLE) f3 = variables[id3].val_double;
						
						variables[id1].val_double = f3 + f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS IDENTIFIER '+' FLOAT SEMICOLON
	{
		int id1 = findVariable($1);
		int id3 = findVariable($3);

		if(id1 >= 0 && id3 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _FLOAT:
					if(variables[id3].type == _INT){
						variables[id1].val_float = variables[id3].val_int / 1.0 + $5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else if(variables[id3].type == _FLOAT){
						variables[id1].val_float = variables[id3].val_float + $5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to float\n\n");
					break;
				case _DOUBLE:
					if(variables[id3].type == _INT){
						variables[id1].val_double = (double)variables[id3].val_int + $5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else if(variables[id3].type == _FLOAT){
						variables[id1].val_double = (double)variables[id3].val_float + $5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else if(variables[id3].type == _DOUBLE){
						variables[id1].val_double = variables[id3].val_double + $5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to double\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS IDENTIFIER '+' DOUBLE SEMICOLON
	{
		int id1 = findVariable($1);
		int id3 = findVariable($3);

		if(id1 >= 0 && id3 >= 0){
			// all variables are found
			if(variables[id1].type == _DOUBLE){
				if(variables[id3].type == _DOUBLE){
					variables[id1].val_double = variables[id3].val_double + $5;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
				}
				else printf(".. TypeError: cannot change var to double\n\n");
			}
			else printf(".. TypeError: cannot change var to double\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS IDENTIFIER '+' STRING SEMICOLON
	{
		int id1 = findVariable($1);
		int id3 = findVariable($3);

		if(id1 >= 0 && id3 >= 0){
			if(variables[id3].type == _STRING){
				char *st = strtok($5, strtokSymbol);
				variables[id1].val_string = strcat(variables[id3].val_string, st);
				printf(".. Variable %s is changed to be %s\n", variables[id1].name, variables[id1].val_string);
			}
			else printf(".. TypeError: cannot change var to string\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	}	
	// -----------------------------------------------------------
	| IDENTIFIER EQUALS INTEGER '+' IDENTIFIER SEMICOLON
	{
		int id1 = findVariable($1);
		int id5 = findVariable($5);

		if(id1 >= 0 && id5 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _INT:
					if(variables[id5].type == _INT){
						variables[id1].val_int = variables[id5].val_int + $3;
						printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _FLOAT:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT){
						
						float f3 = $3 / 1.0, f5;
						if(variables[id5].type == _INT) f5 = variables[id5].val_int / 1.0;
						else if(variables[id5].type == _FLOAT) f5 = variables[id5].val_float;
						
						variables[id1].val_float = f3 + f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE){
						
						double f3 = (double) $3, f5;
						if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
						else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
						else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
						
						variables[id1].val_double = f3 + f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS INTEGER '+' INTEGER SEMICOLON
	{
		int id1 = findVariable($1);

		if(id1 >= 0){
			switch(variables[id1].type){
				case _INT:
					variables[id1].val_int = $3 + $5;
					printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					break;
				case _FLOAT:
					variables[id1].val_float = $3 / 1.0 + $5 / 1.0;
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)$3 + (double)$5;;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS INTEGER '+' FLOAT SEMICOLON
	{
		int id1 = findVariable($1);

		if(id1 >= 0){
			switch(variables[id1].type){
				case _FLOAT:
					variables[id1].val_float = $3 / 1.0 + $5;
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)$3 + (double)$5;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS INTEGER '+' DOUBLE SEMICOLON
	{
		int id1 = findVariable($1);

		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = (double)$3 + $5;
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to double\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	// -----------------------------------------------------------
	| IDENTIFIER EQUALS FLOAT '+' IDENTIFIER SEMICOLON
	{
		int id1 = findVariable($1);
		int id5 = findVariable($5);

		if(id1 >= 0 && id5 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _FLOAT:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT){
						float  f5;
						if(variables[id5].type == _INT) f5 = variables[id5].val_int / 1.0;
						else if(variables[id5].type == _FLOAT) f5 = variables[id5].val_float;
						
						variables[id1].val_float = $3 + f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE){
						
						double f5;
						if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
						else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
						else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
						
						variables[id1].val_double = (double)$3 + f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS FLOAT '+' INTEGER SEMICOLON
	{
		int id1 = findVariable($1);

		if(id1 >= 0){
			switch(variables[id1].type){
				case _FLOAT:
					variables[id1].val_float = $3 + $5 / 1.0;
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)$3 + (double)$5;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS FLOAT '+' FLOAT SEMICOLON
	{
		int id1 = findVariable($1);

		if(id1 >= 0){
			switch(variables[id1].type){
				case _FLOAT:
					variables[id1].val_float = $3 + $5;
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)$3 + (double)$5;;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS FLOAT '+' DOUBLE SEMICOLON
	{
		int id1 = findVariable($1);

		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = (double)$3 + $5;
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to double\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	// -----------------------------------------------------------
	| IDENTIFIER EQUALS DOUBLE '+' IDENTIFIER SEMICOLON
	{
		int id1 = findVariable($1);
		int id5 = findVariable($5);

		if(id1 >= 0 && id5 >= 0){
			// all variables are found
			if(variables[id1].type == _DOUBLE){

				if(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE){
					double f5;
					if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
					else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
					else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
					
					variables[id1].val_double = $3 + f5;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
				}
				else printf(".. TypeError: cannot change var to target type\n\n");
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS DOUBLE '+' INTEGER SEMICOLON
	{
		int id1 = findVariable($1);
		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = $3 + (double)$5;
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS DOUBLE '+' FLOAT SEMICOLON
	{
		int id1 = findVariable($1);
		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = $3 + (double)$5;
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS DOUBLE '+' DOUBLE SEMICOLON
	{
		int id1 = findVariable($1);
		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = $3 + $5;
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	// -----------------------------------------------------------
	| IDENTIFIER EQUALS STRING '+' STRING SEMICOLON
	{
		int id1 = findVariable($1);

		if(id1 >= 0){
			char *st3 = strtok($3, strtokSymbol);
			char *st5 = strtok($5, strtokSymbol);
			variables[id1].val_string = strcat(st3, st5);
			printf(".. Variable %s is changed to be %s\n", variables[id1].name, variables[id1].val_string);
		}
		else printf(".. VariableError: cannot find the variables\n");
	}	
	;
sub:IDENTIFIER EQUALS IDENTIFIER '-' IDENTIFIER SEMICOLON
	{
		int id1 = findVariable($1);
		int id3 = findVariable($3);
		int id5 = findVariable($5);

		if(id1 >= 0 && id3 >= 0 && id5 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _INT:
					if((variables[id3].type == _INT) && (variables[id5].type == _INT)){
						variables[id1].val_int = variables[id3].val_int - variables[id5].val_int;
						printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _FLOAT:
					if(	(variables[id3].type == _INT || variables[id3].type == _FLOAT) && 
						(variables[id5].type == _INT || variables[id5].type == _FLOAT)){
						
						float f3, f5;
						if(variables[id3].type == _INT) f3 = variables[id3].val_int / 1.0;
						else if(variables[id3].type == _FLOAT) f3 = variables[id3].val_float;
						
						if(variables[id5].type == _INT) f5 = variables[id5].val_int / 1.0;
						else if(variables[id5].type == _FLOAT) f5 = variables[id5].val_float;
						
						variables[id1].val_float = f3 - f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(	(variables[id3].type == _INT || variables[id3].type == _FLOAT || variables[id3].type == _DOUBLE) && 
						(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE)){
						
						double f3, f5;
						if(variables[id3].type == _INT) f3 = (double)variables[id3].val_int;
						else if(variables[id3].type == _FLOAT) f3 = (double)variables[id3].val_float;
						else if(variables[id3].type == _DOUBLE) f3 = variables[id3].val_double;
						
						if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
						else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
						else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
						
						variables[id1].val_double = f3 - f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _STRING:
					printf("..TypeError: string type cannot be subtracted\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS IDENTIFIER '-' INTEGER SEMICOLON
	{
		int id1 = findVariable($1);
		int id3 = findVariable($3);

		if(id1 >= 0 && id3 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _INT:
					if(variables[id3].type == _INT){
						variables[id1].val_int = variables[id3].val_int - $5;
						printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _FLOAT:
					if(variables[id3].type == _INT || variables[id3].type == _FLOAT){
						
						float f3, f5 = $5 / 1.0;
						if(variables[id3].type == _INT) f3 = variables[id3].val_int / 1.0;
						else if(variables[id3].type == _FLOAT) f3 = variables[id3].val_float;
						
						variables[id1].val_float = f3 - f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(variables[id3].type == _INT || variables[id3].type == _FLOAT || variables[id3].type == _DOUBLE){
						
						double f3, f5 = (double) $5;
						if(variables[id3].type == _INT) f3 = (double)variables[id3].val_int;
						else if(variables[id3].type == _FLOAT) f3 = (double)variables[id3].val_float;
						else if(variables[id3].type == _DOUBLE) f3 = variables[id3].val_double;
						
						variables[id1].val_double = f3 - f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS IDENTIFIER '-' FLOAT SEMICOLON
	{
		int id1 = findVariable($1);
		int id3 = findVariable($3);

		if(id1 >= 0 && id3 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _FLOAT:
					if(variables[id3].type == _INT){
						variables[id1].val_float = variables[id3].val_int / 1.0 - $5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else if(variables[id3].type == _FLOAT){
						variables[id1].val_float = variables[id3].val_float - $5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to float\n\n");
					break;
				case _DOUBLE:
					if(variables[id3].type == _INT){
						variables[id1].val_double = (double)variables[id3].val_int - $5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else if(variables[id3].type == _FLOAT){
						variables[id1].val_double = (double)variables[id3].val_float - $5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else if(variables[id3].type == _DOUBLE){
						variables[id1].val_double = variables[id3].val_double - $5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to double\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS IDENTIFIER '-' DOUBLE SEMICOLON
	{
		int id1 = findVariable($1);
		int id3 = findVariable($3);

		if(id1 >= 0 && id3 >= 0){
			// all variables are found
			if(variables[id1].type == _DOUBLE){
				if(variables[id3].type == _DOUBLE){
					variables[id1].val_double = variables[id3].val_double - $5;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
				}
				else printf(".. TypeError: cannot change var to double\n\n");
			}
			else printf(".. TypeError: cannot change var to double\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	// -----------------------------------------------------------
	| IDENTIFIER EQUALS INTEGER '-' IDENTIFIER SEMICOLON
	{
		int id1 = findVariable($1);
		int id5 = findVariable($5);

		if(id1 >= 0 && id5 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _INT:
					if(variables[id5].type == _INT){
						variables[id1].val_int = variables[id5].val_int - $3;
						printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _FLOAT:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT){
						
						float f3 = $3 / 1.0, f5;
						if(variables[id5].type == _INT) f5 = variables[id5].val_int / 1.0;
						else if(variables[id5].type == _FLOAT) f5 = variables[id5].val_float;
						
						variables[id1].val_float = f3 - f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE){
						
						double f3 = (double) $3, f5;
						if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
						else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
						else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
						
						variables[id1].val_double = f3 - f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS INTEGER '-' INTEGER SEMICOLON
	{
		int id1 = findVariable($1);

		if(id1 >= 0){
			switch(variables[id1].type){
				case _INT:
					variables[id1].val_int = $3 - $5;
					printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					break;
				case _FLOAT:
					variables[id1].val_float = $3 / 1.0 - $5 / 1.0;
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)$3 - (double)$5;;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS INTEGER '-' FLOAT SEMICOLON
	{
		int id1 = findVariable($1);

		if(id1 >= 0){
			switch(variables[id1].type){
				case _FLOAT:
					variables[id1].val_float = $3 / 1.0 - $5;
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)$3 - (double)$5;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS INTEGER '-' DOUBLE SEMICOLON
	{
		int id1 = findVariable($1);

		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = (double)$3 - $5;
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to double\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	// -----------------------------------------------------------
	| IDENTIFIER EQUALS FLOAT '-' IDENTIFIER SEMICOLON
	{
		int id1 = findVariable($1);
		int id5 = findVariable($5);

		if(id1 >= 0 && id5 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _FLOAT:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT){
						float  f5;
						if(variables[id5].type == _INT) f5 = variables[id5].val_int / 1.0;
						else if(variables[id5].type == _FLOAT) f5 = variables[id5].val_float;
						
						variables[id1].val_float = $3 - f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE){
						
						double f5;
						if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
						else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
						else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
						
						variables[id1].val_double = (double)$3 - f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS FLOAT '-' INTEGER SEMICOLON
	{
		int id1 = findVariable($1);

		if(id1 >= 0){
			switch(variables[id1].type){
				case _FLOAT:
					variables[id1].val_float = $3 - $5 / 1.0;
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)$3 - (double)$5;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS FLOAT '-' FLOAT SEMICOLON
	{
		int id1 = findVariable($1);

		if(id1 >= 0){
			switch(variables[id1].type){
				case _FLOAT:
					variables[id1].val_float = $3 - $5;
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)$3 - (double)$5;;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS FLOAT '-' DOUBLE SEMICOLON
	{
		int id1 = findVariable($1);

		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = (double)$3 - $5;
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to double\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	// -----------------------------------------------------------
	| IDENTIFIER EQUALS DOUBLE '-' IDENTIFIER SEMICOLON
	{
		int id1 = findVariable($1);
		int id5 = findVariable($5);

		if(id1 >= 0 && id5 >= 0){
			// all variables are found
			if(variables[id1].type == _DOUBLE){

				if(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE){
					double f5;
					if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
					else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
					else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
					
					variables[id1].val_double = $3 - f5;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
				}
				else printf(".. TypeError: cannot change var to target type\n\n");
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS DOUBLE '-' INTEGER SEMICOLON
	{
		int id1 = findVariable($1);
		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = $3 - (double)$5;
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS DOUBLE '-' FLOAT SEMICOLON
	{
		int id1 = findVariable($1);
		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = $3 - (double)$5;
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS DOUBLE '-' DOUBLE SEMICOLON
	{
		int id1 = findVariable($1);
		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = $3 - $5;
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	;
mul:IDENTIFIER EQUALS IDENTIFIER '*' IDENTIFIER SEMICOLON
	{
		int id1 = findVariable($1);
		int id3 = findVariable($3);
		int id5 = findVariable($5);

		if(id1 >= 0 && id3 >= 0 && id5 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _INT:
					if((variables[id3].type == _INT) && (variables[id5].type == _INT)){
						variables[id1].val_int = variables[id3].val_int * variables[id5].val_int;
						printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _FLOAT:
					if(	(variables[id3].type == _INT || variables[id3].type == _FLOAT) && 
						(variables[id5].type == _INT || variables[id5].type == _FLOAT)){
						
						float f3, f5;
						if(variables[id3].type == _INT) f3 = variables[id3].val_int / 1.0;
						else if(variables[id3].type == _FLOAT) f3 = variables[id3].val_float;
						
						if(variables[id5].type == _INT) f5 = variables[id5].val_int / 1.0;
						else if(variables[id5].type == _FLOAT) f5 = variables[id5].val_float;
						
						variables[id1].val_float = f3 * f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(	(variables[id3].type == _INT || variables[id3].type == _FLOAT || variables[id3].type == _DOUBLE) && 
						(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE)){
						
						double f3, f5;
						if(variables[id3].type == _INT) f3 = (double)variables[id3].val_int;
						else if(variables[id3].type == _FLOAT) f3 = (double)variables[id3].val_float;
						else if(variables[id3].type == _DOUBLE) f3 = variables[id3].val_double;
						
						if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
						else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
						else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
						
						variables[id1].val_double = f3 * f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _STRING:
					printf("..TypeError: string type cannot be multided");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS IDENTIFIER '*' INTEGER SEMICOLON
	{
		int id1 = findVariable($1);
		int id3 = findVariable($3);

		if(id1 >= 0 && id3 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _INT:
					if(variables[id3].type == _INT){
						variables[id1].val_int = variables[id3].val_int * $5;
						printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _FLOAT:
					if(variables[id3].type == _INT || variables[id3].type == _FLOAT){
						
						float f3, f5 = $5 / 1.0;
						if(variables[id3].type == _INT) f3 = variables[id3].val_int / 1.0;
						else if(variables[id3].type == _FLOAT) f3 = variables[id3].val_float;
						
						variables[id1].val_float = f3 * f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(variables[id3].type == _INT || variables[id3].type == _FLOAT || variables[id3].type == _DOUBLE){
						
						double f3, f5 = (double) $5;
						if(variables[id3].type == _INT) f3 = (double)variables[id3].val_int;
						else if(variables[id3].type == _FLOAT) f3 = (double)variables[id3].val_float;
						else if(variables[id3].type == _DOUBLE) f3 = variables[id3].val_double;
						
						variables[id1].val_double = f3 * f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS IDENTIFIER '*' FLOAT SEMICOLON
	{
		int id1 = findVariable($1);
		int id3 = findVariable($3);

		if(id1 >= 0 && id3 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _FLOAT:
					if(variables[id3].type == _INT){
						variables[id1].val_float = variables[id3].val_int / 1.0 * $5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else if(variables[id3].type == _FLOAT){
						variables[id1].val_float = variables[id3].val_float * $5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to float\n\n");
					break;
				case _DOUBLE:
					if(variables[id3].type == _INT){
						variables[id1].val_double = (double)variables[id3].val_int * $5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else if(variables[id3].type == _FLOAT){
						variables[id1].val_double = (double)variables[id3].val_float * $5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else if(variables[id3].type == _DOUBLE){
						variables[id1].val_double = variables[id3].val_double * $5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to double\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS IDENTIFIER '*' DOUBLE SEMICOLON
	{
		int id1 = findVariable($1);
		int id3 = findVariable($3);

		if(id1 >= 0 && id3 >= 0){
			// all variables are found
			if(variables[id1].type == _DOUBLE){
				if(variables[id3].type == _DOUBLE){
					variables[id1].val_double = variables[id3].val_double * $5;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
				}
				else printf(".. TypeError: cannot change var to double\n\n");
			}
			else printf(".. TypeError: cannot change var to double\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	// -----------------------------------------------------------
	| IDENTIFIER EQUALS INTEGER '*' IDENTIFIER SEMICOLON
	{
		int id1 = findVariable($1);
		int id5 = findVariable($5);

		if(id1 >= 0 && id5 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _INT:
					if(variables[id5].type == _INT){
						variables[id1].val_int = variables[id5].val_int * $3;
						printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _FLOAT:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT){
						
						float f3 = $3 / 1.0, f5;
						if(variables[id5].type == _INT) f5 = variables[id5].val_int / 1.0;
						else if(variables[id5].type == _FLOAT) f5 = variables[id5].val_float;
						
						variables[id1].val_float = f3 * f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE){
						
						double f3 = (double) $3, f5;
						if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
						else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
						else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
						
						variables[id1].val_double = f3 * f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS INTEGER '*' INTEGER SEMICOLON
	{
		int id1 = findVariable($1);

		if(id1 >= 0){
			switch(variables[id1].type){
				case _INT:
					variables[id1].val_int = $3 * $5;
					printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					break;
				case _FLOAT:
					variables[id1].val_float = $3 / 1.0 * $5 / 1.0;
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)$3 * (double)$5;;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS INTEGER '*' FLOAT SEMICOLON
	{
		int id1 = findVariable($1);

		if(id1 >= 0){
			switch(variables[id1].type){
				case _FLOAT:
					variables[id1].val_float = $3 / 1.0 * $5;
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)$3 * (double)$5;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS INTEGER '*' DOUBLE SEMICOLON
	{
		int id1 = findVariable($1);

		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = (double)$3 * $5;
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to double\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	// -----------------------------------------------------------
	| IDENTIFIER EQUALS FLOAT '*' IDENTIFIER SEMICOLON
	{
		int id1 = findVariable($1);
		int id5 = findVariable($5);

		if(id1 >= 0 && id5 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _FLOAT:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT){
						float  f5;
						if(variables[id5].type == _INT) f5 = variables[id5].val_int / 1.0;
						else if(variables[id5].type == _FLOAT) f5 = variables[id5].val_float;
						
						variables[id1].val_float = $3 * f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE){
						
						double f5;
						if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
						else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
						else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
						
						variables[id1].val_double = (double)$3 * f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS FLOAT '*' INTEGER SEMICOLON
	{
		int id1 = findVariable($1);

		if(id1 >= 0){
			switch(variables[id1].type){
				case _FLOAT:
					variables[id1].val_float = $3 * $5 / 1.0;
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)$3 * (double)$5;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS FLOAT '*' FLOAT SEMICOLON
	{
		int id1 = findVariable($1);

		if(id1 >= 0){
			switch(variables[id1].type){
				case _FLOAT:
					variables[id1].val_float = $3 * $5;
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)$3 * (double)$5;;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS FLOAT '*' DOUBLE SEMICOLON
	{
		int id1 = findVariable($1);

		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = (double)$3 * $5;
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to double\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	// -----------------------------------------------------------
	| IDENTIFIER EQUALS DOUBLE '*' IDENTIFIER SEMICOLON
	{
		int id1 = findVariable($1);
		int id5 = findVariable($5);

		if(id1 >= 0 && id5 >= 0){
			// all variables are found
			if(variables[id1].type == _DOUBLE){

				if(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE){
					double f5;
					if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
					else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
					else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
					
					variables[id1].val_double = $3 * f5;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
				}
				else printf(".. TypeError: cannot change var to target type\n\n");
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS DOUBLE '*' INTEGER SEMICOLON
	{
		int id1 = findVariable($1);
		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = $3 * (double)$5;
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS DOUBLE '*' FLOAT SEMICOLON
	{
		int id1 = findVariable($1);
		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = $3 * (double)$5;
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS DOUBLE '*' DOUBLE SEMICOLON
	{
		int id1 = findVariable($1);
		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = $3 * $5;
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	;	
div:IDENTIFIER EQUALS IDENTIFIER '/' IDENTIFIER SEMICOLON
	{
		int id1 = findVariable($1);
		int id3 = findVariable($3);
		int id5 = findVariable($5);

		if(id1 >= 0 && id3 >= 0 && id5 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _INT:
					if((variables[id3].type == _INT) && (variables[id5].type == _INT)){
						variables[id1].val_int = variables[id3].val_int / variables[id5].val_int;
						printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _FLOAT:
					if(	(variables[id3].type == _INT || variables[id3].type == _FLOAT) && 
						(variables[id5].type == _INT || variables[id5].type == _FLOAT)){
						
						float f3, f5;
						if(variables[id3].type == _INT) f3 = variables[id3].val_int / 1.0;
						else if(variables[id3].type == _FLOAT) f3 = variables[id3].val_float;
						
						if(variables[id5].type == _INT) f5 = variables[id5].val_int / 1.0;
						else if(variables[id5].type == _FLOAT) f5 = variables[id5].val_float;
						
						variables[id1].val_float = f3 / f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(	(variables[id3].type == _INT || variables[id3].type == _FLOAT || variables[id3].type == _DOUBLE) && 
						(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE)){
						
						double f3, f5;
						if(variables[id3].type == _INT) f3 = (double)variables[id3].val_int;
						else if(variables[id3].type == _FLOAT) f3 = (double)variables[id3].val_float;
						else if(variables[id3].type == _DOUBLE) f3 = variables[id3].val_double;
						
						if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
						else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
						else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
						
						variables[id1].val_double = f3 / f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _STRING:
					printf("..TypeError: string type cannot be multided");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS IDENTIFIER '/' INTEGER SEMICOLON
	{
		int id1 = findVariable($1);
		int id3 = findVariable($3);

		if(id1 >= 0 && id3 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _INT:
					if(variables[id3].type == _INT){
						variables[id1].val_int = variables[id3].val_int / $5;
						printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _FLOAT:
					if(variables[id3].type == _INT || variables[id3].type == _FLOAT){
						
						float f3, f5 = $5 / 1.0;
						if(variables[id3].type == _INT) f3 = variables[id3].val_int / 1.0;
						else if(variables[id3].type == _FLOAT) f3 = variables[id3].val_float;
						
						variables[id1].val_float = f3 / f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(variables[id3].type == _INT || variables[id3].type == _FLOAT || variables[id3].type == _DOUBLE){
						
						double f3, f5 = (double) $5;
						if(variables[id3].type == _INT) f3 = (double)variables[id3].val_int;
						else if(variables[id3].type == _FLOAT) f3 = (double)variables[id3].val_float;
						else if(variables[id3].type == _DOUBLE) f3 = variables[id3].val_double;
						
						variables[id1].val_double = f3 / f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS IDENTIFIER '/' FLOAT SEMICOLON
	{
		int id1 = findVariable($1);
		int id3 = findVariable($3);

		if(id1 >= 0 && id3 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _FLOAT:
					if(variables[id3].type == _INT){
						variables[id1].val_float = variables[id3].val_int / 1.0 / $5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else if(variables[id3].type == _FLOAT){
						variables[id1].val_float = variables[id3].val_float / $5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to float\n\n");
					break;
				case _DOUBLE:
					if(variables[id3].type == _INT){
						variables[id1].val_double = (double)variables[id3].val_int / $5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else if(variables[id3].type == _FLOAT){
						variables[id1].val_double = (double)variables[id3].val_float / $5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else if(variables[id3].type == _DOUBLE){
						variables[id1].val_double = variables[id3].val_double / $5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to double\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS IDENTIFIER '/' DOUBLE SEMICOLON
	{
		int id1 = findVariable($1);
		int id3 = findVariable($3);

		if(id1 >= 0 && id3 >= 0){
			// all variables are found
			if(variables[id1].type == _DOUBLE){
				if(variables[id3].type == _DOUBLE){
					variables[id1].val_double = variables[id3].val_double / $5;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
				}
				else printf(".. TypeError: cannot change var to double\n\n");
			}
			else printf(".. TypeError: cannot change var to double\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	// -----------------------------------------------------------
	| IDENTIFIER EQUALS INTEGER '/' IDENTIFIER SEMICOLON
	{
		int id1 = findVariable($1);
		int id5 = findVariable($5);

		if(id1 >= 0 && id5 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _INT:
					if(variables[id5].type == _INT){
						variables[id1].val_int = variables[id5].val_int / $3;
						printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _FLOAT:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT){
						
						float f3 = $3 / 1.0, f5;
						if(variables[id5].type == _INT) f5 = variables[id5].val_int / 1.0;
						else if(variables[id5].type == _FLOAT) f5 = variables[id5].val_float;
						
						variables[id1].val_float = f3 / f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE){
						
						double f3 = (double) $3, f5;
						if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
						else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
						else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
						
						variables[id1].val_double = f3 / f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS INTEGER '/' INTEGER SEMICOLON
	{
		int id1 = findVariable($1);

		if(id1 >= 0){
			switch(variables[id1].type){
				case _INT:
					variables[id1].val_int = $3 / $5;
					printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
					break;
				case _FLOAT:
					variables[id1].val_float = $3 / 1.0 / $5 / 1.0;
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)$3 / (double)$5;;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS INTEGER '/' FLOAT SEMICOLON
	{
		int id1 = findVariable($1);

		if(id1 >= 0){
			switch(variables[id1].type){
				case _FLOAT:
					variables[id1].val_float = $3 / 1.0 / $5;
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)$3 / (double)$5;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS INTEGER '/' DOUBLE SEMICOLON
	{
		int id1 = findVariable($1);

		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = (double)$3 / $5;
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to double\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	// -----------------------------------------------------------
	| IDENTIFIER EQUALS FLOAT '/' IDENTIFIER SEMICOLON
	{
		int id1 = findVariable($1);
		int id5 = findVariable($5);

		if(id1 >= 0 && id5 >= 0){
			// all variables are found
			switch(variables[id1].type){
				case _FLOAT:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT){
						float  f5;
						if(variables[id5].type == _INT) f5 = variables[id5].val_int / 1.0;
						else if(variables[id5].type == _FLOAT) f5 = variables[id5].val_float;
						
						variables[id1].val_float = $3 / f5;
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				case _DOUBLE:
					if(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE){
						
						double f5;
						if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
						else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
						else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
						
						variables[id1].val_double = (double)$3 / f5;
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					}
					else printf(".. TypeError: cannot change var to target type\n\n");
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS FLOAT '/' INTEGER SEMICOLON
	{
		int id1 = findVariable($1);

		if(id1 >= 0){
			switch(variables[id1].type){
				case _FLOAT:
					variables[id1].val_float = $3 / $5 / 1.0;
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)$3 / (double)$5;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS FLOAT '/' FLOAT SEMICOLON
	{
		int id1 = findVariable($1);

		if(id1 >= 0){
			switch(variables[id1].type){
				case _FLOAT:
					variables[id1].val_float = $3 / $5;
					printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
					break;
				case _DOUBLE:
					variables[id1].val_double = (double)$3 / (double)$5;;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
					break;
				default:
					printf(".. TypeError: cannot change var to target type\n\n");
			}
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS FLOAT '/' DOUBLE SEMICOLON
	{
		int id1 = findVariable($1);

		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = (double)$3 / $5;
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to double\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	// -----------------------------------------------------------
	| IDENTIFIER EQUALS DOUBLE '/' IDENTIFIER SEMICOLON
	{
		int id1 = findVariable($1);
		int id5 = findVariable($5);

		if(id1 >= 0 && id5 >= 0){
			// all variables are found
			if(variables[id1].type == _DOUBLE){

				if(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE){
					double f5;
					if(variables[id5].type == _INT) f5 = (double)variables[id5].val_int;
					else if(variables[id5].type == _FLOAT) f5 = (double)variables[id5].val_float;
					else if(variables[id5].type == _DOUBLE) f5 = variables[id5].val_double;
					
					variables[id1].val_double = $3 / f5;
					printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
				}
				else printf(".. TypeError: cannot change var to target type\n\n");
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS DOUBLE '/' INTEGER SEMICOLON
	{
		int id1 = findVariable($1);
		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = $3 / (double)$5;
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS DOUBLE '/' FLOAT SEMICOLON
	{
		int id1 = findVariable($1);
		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = $3 / (double)$5;
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS DOUBLE '/' DOUBLE SEMICOLON
	{
		int id1 = findVariable($1);
		if(id1 >= 0){
			if(variables[id1].type == _DOUBLE){
				variables[id1].val_double = $3 / $5;
				printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
			}
			else printf(".. TypeError: cannot change var to target type\n\n");
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	;
mod:IDENTIFIER EQUALS IDENTIFIER '%' IDENTIFIER SEMICOLON
	{
		int id1 = findVariable($1);
		int id3 = findVariable($3);
		int id5 = findVariable($5);

		if(id1 >= 0 && id3 >= 0 && id5 >= 0){
			// all variables are found
			if(variables[id1].type == _INT && variables[id3].type == _INT && variables[id5].type == _INT){
				variables[id1].val_int = variables[id3].val_int % variables[id5].val_int;
				printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
			}
			else printf(".. TypeError: cannot change var to integer\n\n"); 
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS IDENTIFIER '%' INTEGER SEMICOLON
	{
		int id1 = findVariable($1);
		int id3 = findVariable($3);

		if(id1 >= 0 && id3 >= 0){
			// all variables are found
			if(variables[id1].type == _INT && variables[id3].type == _INT){
				variables[id1].val_int = variables[id3].val_int % $5;
				printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
			}
			else printf(".. TypeError: cannot change var to integer\n\n"); 
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS INTEGER '%' IDENTIFIER SEMICOLON
	{
		int id1 = findVariable($1);
		int id5 = findVariable($5);

		if(id1 >= 0 && id5 >= 0){
			// all variables are found
			if(variables[id1].type == _INT && variables[id5].type == _INT){
				variables[id1].val_int = $3 % variables[id5].val_int;
				printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
			}
			else printf(".. TypeError: cannot change var to integer\n\n"); 
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	| IDENTIFIER EQUALS INTEGER '%' INTEGER SEMICOLON
	{
		int id1 = findVariable($1);

		if(id1 >= 0){
			if(variables[id1].type == _INT){
				variables[id1].val_int = $3 % $5;
				printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
			}
			else printf(".. TypeError: cannot change var to integer\n\n"); 
		}
		else printf(".. VariableError: cannot find the variables\n");
	}
	;

function: IDENTIFIER EQUALS LOG '(' IDENTIFIER ')' SEMICOLON
		{
			int id1 = findVariable($1);
			int id5 = findVariable($5);
			
			if(id1 >= 0 && id5 >= 0){
				switch(variables[id1].type){
					case _INT:
						if(variables[id5].type == _INT) {
							variables[id1].val_int = log10(variables[id5].val_int);
							printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
						}
						else printf(".. TypeError: function int log10(x) can only put in int\n");
						break;
					case _FLOAT:
						if(variables[id5].type == _INT || variables[id5].type == _FLOAT){
							if(variables[id5].type == _INT) variables[id1].val_float = log10(variables[id5].val_int / 1.0);
							else if(variables[id5].type == _FLOAT) variables[id1].val_float = log10(variables[id5].val_float);
							printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
						}
						else printf(".. TypeError: float function log10(x) can only put in int/float\n");
						break;
					case _DOUBLE:
						if(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE){
							if(variables[id5].type == _INT) variables[id1].val_double = log10((double)variables[id5].val_int);
							else if(variables[id5].type == _FLOAT) variables[id1].val_double = log10((double)variables[id5].val_float);
							else if(variables[id5].type == _DOUBLE) variables[id1].val_double = log10(variables[id5].val_double);
							printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
						}
						else printf(".. TypeError: function double log10(x) can only put in int/float/double\n");
						break;
					default:
						printf(".. TypeError: function log10(x) can only put out int/float/double\n");
				};
			}
			else printf(".. VariableError: cannot find the variables\n");
		}
		| IDENTIFIER EQUALS SQRT '(' IDENTIFIER ')' SEMICOLON
		{
			int id1 = findVariable($1);
			int id5 = findVariable($5);
			
			if(id1 >= 0 && id5 >= 0){
				switch(variables[id1].type){
					case _INT:
						if(variables[id5].type == _INT) {
							variables[id1].val_int = sqrt(variables[id5].val_int);
							printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
						}
						else printf(".. TypeError: function int sqrt(x) can only put in int\n");
						break;
					case _FLOAT:
						if(variables[id5].type == _INT || variables[id5].type == _FLOAT){
							if(variables[id5].type == _INT) variables[id1].val_float = sqrt(variables[id5].val_int / 1.0);
							else if(variables[id5].type == _FLOAT) variables[id1].val_float = sqrt(variables[id5].val_float);
							printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
						}
						else printf(".. TypeError: float function sqrt(x) can only put in int/float\n");
						break;
					case _DOUBLE:
						if(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE){
							if(variables[id5].type == _INT) variables[id1].val_double = sqrt((double)variables[id5].val_int);
							else if(variables[id5].type == _FLOAT) variables[id1].val_double = sqrt((double)variables[id5].val_float);
							else if(variables[id5].type == _DOUBLE) variables[id1].val_double = sqrt(variables[id5].val_double);
							printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
						}
						else printf(".. TypeError: function double sqrt(x) can only put in int/float/double\n");
						break;
					default:
						printf(".. TypeError: function sqrt(x) can only put out int/float/double\n");
				};
			}
			else printf(".. VariableError: cannot find the variables\n");
		}
		| IDENTIFIER EQUALS ABS '(' IDENTIFIER ')' SEMICOLON
		{
			int id1 = findVariable($1);
			int id5 = findVariable($5);
			
			if(id1 >= 0 && id5 >= 0){
				switch(variables[id1].type){
					case _INT:
						if(variables[id5].type == _INT) {
							variables[id1].val_int = fabs(variables[id5].val_int);
							printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
						}
						else printf(".. TypeError: function int fabs(x) can only put in int\n");
						break;
					case _FLOAT:
						if(variables[id5].type == _INT || variables[id5].type == _FLOAT){
							if(variables[id5].type == _INT) variables[id1].val_float = fabs(variables[id5].val_int / 1.0);
							else if(variables[id5].type == _FLOAT) variables[id1].val_float = fabs(variables[id5].val_float);
							printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
						}
						else printf(".. TypeError: float function fabs(x) can only put in int/float\n");
						break;
					case _DOUBLE:
						if(variables[id5].type == _INT || variables[id5].type == _FLOAT || variables[id5].type == _DOUBLE){
							if(variables[id5].type == _INT) variables[id1].val_double = fabs((double)variables[id5].val_int);
							else if(variables[id5].type == _FLOAT) variables[id1].val_double = fabs((double)variables[id5].val_float);
							else if(variables[id5].type == _DOUBLE) variables[id1].val_double = fabs(variables[id5].val_double);
							printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
						}
						else printf(".. TypeError: function double fabs(x) can only put in int/float/double\n");
						break;
					default:
						printf(".. TypeError: function fabs(x) can only put out int/float/double\n");
				};
			}
			else printf(".. VariableError: cannot find the variables\n");
			
		}
		| IDENTIFIER EQUALS LOG '(' INTEGER ')' SEMICOLON
		{
			int id1 = findVariable($1);
			
			if(id1 >= 0){
				switch(variables[id1].type){
					case _INT:
						variables[id1].val_int = log10($5);
						printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
						break;
					case _FLOAT:
						variables[id1].val_float = log10($5 / 1.0);
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
						break;
					case _DOUBLE:
						variables[id1].val_double = log10((double)$5);
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
						break;
					default:
						printf(".. TypeError: function log10(x) can only put out int/float/double\n");
				};
			}
			else printf(".. VariableError: cannot find the variables\n");
		}
		| IDENTIFIER EQUALS SQRT '(' INTEGER ')' SEMICOLON
		{
			int id1 = findVariable($1);
			
			if(id1 >= 0){
				switch(variables[id1].type){
					case _INT:
						variables[id1].val_int = sqrt($5);
						printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
						break;
					case _FLOAT:
						variables[id1].val_float = sqrt($5 / 1.0);
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
						break;
					case _DOUBLE:
						variables[id1].val_double = sqrt((double)$5);
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
						break;
					default:
						printf(".. TypeError: function sqrt(x) can only put out int/float/double\n");
				};
			}
			else printf(".. VariableError: cannot find the variables\n");
		}
		| IDENTIFIER EQUALS ABS '(' INTEGER ')' SEMICOLON
		{
			int id1 = findVariable($1);

			if(id1 >= 0){
				switch(variables[id1].type){
					case _INT:
						variables[id1].val_int = fabs($5);
						printf(".. Variable %s is changed to be %d\n", variables[id1].name, variables[id1].val_int);
						break;
					case _FLOAT:
						variables[id1].val_float = fabs($5 / 1.0);
						printf(".. Variable %s is changed to be %f\n", variables[id1].name, variables[id1].val_float);
						break;
					case _DOUBLE:
						variables[id1].val_double = fabs((double)$5);
						printf(".. Variable %s is changed to be %lf\n", variables[id1].name, variables[id1].val_double);
						break;
					default:
						printf(".. TypeError: function fabs(x) can only put out int/float/double\n");
				};
			}
			else printf(".. VariableError: cannot find the variables\n");
			
		}
		;

declare_int: INT_TYPE IDENTIFIER EQUALS INTEGER SEMICOLON
			{
				if(findVariable($2) >= 0) printf(".. DefinedError: This variable has been defined\n");
				else{
					Variable var;
					var.type = _INT;
					var.name = $2;
					var.val_int = $4;
					variables[numVariables++] = var;
					printf(".. Variable %s is declared with value %d\n", var.name, var.val_int);
				}
			}
			| INT_TYPE IDENTIFIER SEMICOLON
			{
				if(findVariable($2) >= 0) printf(".. DefinedError: This variable has been defined\n");
				else{
					Variable var;
					var.type = _INT;
					var.name = $2;
					var.val_int = 0;
					variables[numVariables++] = var;
					printf(".. Variable %s is declared with value 0(default)\n", var.name);
				}
			}
			;
declare_str: STRING_TYPE IDENTIFIER EQUALS STRING SEMICOLON
           {
               	if(findVariable($2) >= 0) printf(".. DefinedError: This variable has been defined\n");
				else{
					Variable var;
					var.type = _STRING;
					var.name = $2;
					char *st = strtok($4, strtokSymbol);
					var.val_string = st;
					variables[numVariables++] = var;
					printf(".. Variable %s is declared with value %s\n", var.name, var.val_string);
				}
           }
		   | STRING_TYPE IDENTIFIER SEMICOLON
           {
               	if(findVariable($2) >= 0) printf(".. DefinedError: This variable has been defined\n");
				else{
					Variable var;
					var.type = _STRING;
					var.name = $2;
					var.val_string = strdup("");
					variables[numVariables++] = var;
					printf(".. Variable %s is declared with value \'\\0\'\n", var.name);
				}
           }
		   ;
declare_char: CHAR_TYPE IDENTIFIER EQUALS CHAR SEMICOLON
           {
				if(findVariable($2) >= 0) printf(".. DefinedError: This variable has been defined\n");
				else{
					Variable var;
					var.type = _CHAR;
					var.name = $2;
					var.val_char = $4;
					variables[numVariables++] = var;
					printf(".. Variable %s is declared with value ", var.name);
					putchar($4);
					printf("\n");
				}
           }
		   ;
declare_float: FLOAT_TYPE IDENTIFIER EQUALS FLOAT SEMICOLON
           {
				if(findVariable($2) >= 0) printf(".. DefinedError: This variable has been defined\n");
				else{
					Variable var;
					var.type = _FLOAT;
					var.name = $2;
					var.val_float = $4;
					variables[numVariables++] = var;
					printf(".. Variable %s is declared with value %f\n", var.name, var.val_float);
				}
           }
		   | FLOAT_TYPE IDENTIFIER EQUALS INTEGER SEMICOLON
           {
				if(findVariable($2) >= 0) printf(".. DefinedError: This variable has been defined\n");
				else{
					Variable var;
					var.type = _FLOAT;
					var.name = $2;
					var.val_float = $4 / 1.0;
					variables[numVariables++] = var;
					printf(".. Variable %s is declared with value %f\n", var.name, var.val_float);
				}
           }
		   | FLOAT_TYPE IDENTIFIER SEMICOLON
           {
				if(findVariable($2) >= 0) printf(".. DefinedError: This variable has been defined\n");
				else{
					Variable var;
					var.type = _FLOAT;
					var.name = $2;
					var.val_float = 0.0;
					variables[numVariables++] = var;
					printf(".. Variable %s is declared with value %f(default)\n", var.name, var.val_float);
				}
           }
		   ;
declare_double: DOUBLE_TYPE IDENTIFIER EQUALS DOUBLE SEMICOLON
           {
				if(findVariable($2) >= 0) printf(".. DefinedError: This variable has been defined\n");
				else{
					Variable var;
					var.type = _DOUBLE;
					var.name = $2;
					var.val_double = $4;
					variables[numVariables++] = var;
					printf(".. Variable %s is declared with value %lf\n", var.name, var.val_double);
				}
           }
           | DOUBLE_TYPE IDENTIFIER EQUALS FLOAT SEMICOLON
           {
				if(findVariable($2) >= 0) printf(".. DefinedError: This variable has been defined\n");
				else{
					Variable var;
					var.type = _DOUBLE;
					var.name = $2;
					var.val_double = $4;
					variables[numVariables++] = var;
					printf(".. Variable %s is declared with value %f\n", var.name, var.val_double);
				}
           }
           | DOUBLE_TYPE IDENTIFIER SEMICOLON
           {
				if(findVariable($2) >= 0) printf(".. DefinedError: This variable has been defined\n");
				else{
					Variable var;
					var.type = _DOUBLE;
					var.name = $2;
					var.val_double = (double)0.0;
					variables[numVariables++] = var;
					printf(".. Variable %s is declared with value %lf(default)\n", var.name, var.val_double);
				}
           }
		   ;
declare_bool: BOOL_TYPE IDENTIFIER EQUALS BOOL SEMICOLON
           {
				if(findVariable($2) >= 0) printf(".. DefinedError: This variable has been defined\n");
				else{
					Variable var;
					var.type = _BOOL;
					var.name = $2;
					var.val_bool = $4;
					variables[numVariables++] = var;
					printf(".. Variable %s is declared with value %d\n", var.name, $4);
				}
           }
           ;

%%

int main() {
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    printf(".. TypeError: %s\n", s);
}

void print_endl(Variable var){
	if(var.type == _BOOL)	// bool
		printf("%b\n", var.val_bool);
	else if(var.type == _INT)	// int
		printf("%d\n", var.val_int);
	else if(var.type == _CHAR)	// char
		printf("%c\n", var.val_char);
	else if(var.type == _FLOAT)	// float
		printf("%f\n", var.val_float);
	else if(var.type == _DOUBLE)	// double
		printf("%lf\n", var.val_double);
	else if(var.type == _STRING)	// string
		printf("%s\n", var.val_string);
}

void print(Variable var){
	if(var.type == _BOOL)	// bool
		printf("%b", var.val_bool);
	else if(var.type == _INT)	// int
		printf("%d", var.val_int);
	else if(var.type == _CHAR)	// char
		putchar(var.val_char);
	else if(var.type == _FLOAT)	// float
		printf("%f", var.val_float);
	else if(var.type == _DOUBLE)	// double
		printf("%lf", var.val_double);
	else if(var.type == _STRING)	// string0
		printf("%s", var.val_string);
}

int findVariable(char* name){	// no find return -1
	int id = -1;
	int i = 0;
	for (i=0; i < numVariables; i++) {
		if (strcmp(variables[i].name, name) == 0) {
			id = i; 
			break;
		} 
	}
	return id;
}