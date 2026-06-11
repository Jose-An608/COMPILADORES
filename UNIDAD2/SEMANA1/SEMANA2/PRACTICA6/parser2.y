%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char* msg);
%}

%token TOK_C TOK_D

%%

input:
      /* vacio */
    | input S '\n'      { printf("  >> ACEPTADA\n\n"); }
    | input '\n'
    | input error '\n'  { printf("  >> RECHAZADA\n\n"); yyerrok; }
    ;

S:  C C
    ;

C:  TOK_C C     { }
  | TOK_D       { }
  ;

%%

void yyerror(const char* msg) {
    printf("  [ERROR] %s\n", msg);
}

int main() {
    printf("=== Analizador LR - Ejercicio 7 ===\n");
    printf("Gramatica: S->CC | C->cC | C->d\n");
    printf("Ingresa cadenas (Ctrl+Z para salir):\n\n");
    yyparse();
    return 0;
}
