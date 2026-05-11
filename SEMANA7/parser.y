%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex();

%}

%token NUM
%token MAS MENOS MULT DIV
%token PARI PARD

%%

input:
input line
|
;

line:
expr '\n' { printf("Resultado válido\n"); }
;

expr:
expr MAS term
| expr MENOS term
| term
;

term:
term MULT factor
| term DIV factor
| factor
;

factor:
NUM
| PARI expr PARD
;

%%

void yyerror(const char *s) {
printf("Error sintactico: %s\n", s);
}

int main() {
printf("Ingrese expresiones:\n");
yyparse();
return 0;
}