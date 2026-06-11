%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char* msg);
%}

%token ID

%left '+'
%left '*'

%%

input:
      /* vacio */
    | input expr '\n'   { printf("  >> ACEPTADA\n\n"); }
    | input '\n'
    | input error '\n'  { printf("  >> RECHAZADA\n\n"); yyerrok; }
    ;

expr:
      expr '+' expr
    | expr '*' expr
    | '(' expr ')'
    | ID
    ;

%%

void yyerror(const char* msg) {
    printf("  [ERROR] %s\n", msg);
}

int main() {
    printf("=== Analizador LR con Bison - Practica 3 ===\n");
    printf("Ingresa expresiones (Ctrl+Z para salir):\n\n");
    yyparse();
    return 0;
}