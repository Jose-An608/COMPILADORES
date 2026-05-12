%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex();

// Tabla de variables
typedef struct {
    char nombre[32];
    double valor;
} Variable;

Variable tabla[100];
int numVars = 0;

double obtenerVar(char *nombre) {
    for (int i = 0; i < numVars; i++)
        if (strcmp(tabla[i].nombre, nombre) == 0)
            return tabla[i].valor;
    printf("Variable no definida: %s\n", nombre);
    return 0;
}

void guardarVar(char *nombre, double valor) {
    for (int i = 0; i < numVars; i++) {
        if (strcmp(tabla[i].nombre, nombre) == 0) {
            tabla[i].valor = valor;
            return;
        }
    }
    strcpy(tabla[numVars].nombre, nombre);
    tabla[numVars].valor = valor;
    numVars++;
}
%}

%union {
    double dval;
    char *sval;
}

%token <dval> NUM
%token <sval> VAR
%token MAS MENOS MULT DIV MOD IGUAL
%token PARI PARD

%type <dval> expr term factor

%%

input:
input line
|
;

line:
    VAR IGUAL expr '\n'  { guardarVar($1, $3); printf("Variable %s = %.2f\n", $1, $3); }
    | expr '\n'          { printf("Resultado: %.2f\n", $1); }
;

expr:
    expr MAS term        { $$ = $1 + $3; }
    | expr MENOS term    { $$ = $1 - $3; }
    | term               { $$ = $1; }
;

term:
    term MULT factor     { $$ = $1 * $3; }
    | term DIV factor    { $$ = $1 / $3; }
    | term MOD factor    { $$ = (int)$1 % (int)$3; }
    | factor             { $$ = $1; }
;


factor:
    NUM                  { $$ = $1; }
    | VAR                { $$ = obtenerVar($1); }
    | PARI expr PARD     { $$ = $2; }
;

%%

void yyerror(const char *s) {
printf("Error sintactico: %s\n", s);
}

int main() {
    printf("=== Calculadora Flex+Bison ===\n");
    printf("Operadores: + - * / %% y variables\n\n");
    yyparse();
    return 0;
}