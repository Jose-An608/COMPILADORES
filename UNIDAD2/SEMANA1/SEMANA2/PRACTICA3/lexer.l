%{
#include "parser.tab.h"
#include <stdio.h>
%}

%%

[a-zA-Z][a-zA-Z0-9]*   { printf("  [TOKEN] ID: %s\n", yytext); return ID; }
"+"                     { printf("  [TOKEN] +\n"); return '+'; }
"*"                     { printf("  [TOKEN] *\n"); return '*'; }
"("                     { printf("  [TOKEN] (\n"); return '('; }
")"                     { printf("  [TOKEN] )\n"); return ')'; }
"\n"                    { return '\n'; }
"\r"                    { /* ignorar carriage return de Windows */ }
[ \t]                   { /* ignorar espacios */ }
.                       { printf("  [LEXICO] caracter desconocido: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}