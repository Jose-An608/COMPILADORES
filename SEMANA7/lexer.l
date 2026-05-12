%{
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}

%%

[0-9]+\.[0-9]+  { yylval.dval = atof(yytext); return NUM; }
[0-9]+          { yylval.dval = atoi(yytext); return NUM; }
[a-zA-Z]+       { yylval.sval = strdup(yytext); return VAR; }

"+"             { return MAS; }
"-"             { return MENOS; }
"*"             { return MULT; }
"/"             { return DIV; }
"%"             { return MOD; }
"="             { return IGUAL; }
"("             { return PARI; }
")"             { return PARD; }
[ \t\r]         ;
\n              { return '\n'; }
.               { printf("Caracter invalido: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}