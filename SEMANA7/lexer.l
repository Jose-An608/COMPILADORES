%{
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
%}

%%

[0-9]+ { yylval = atoi(yytext); return NUM; }

"+" { return MAS; }
"-" { return MENOS; }
"*" { return MULT; }
"/" { return DIV; }

"(" { return PARI; }

")" { return PARD; }

[ \t\r] ;
\n { return '\n'; }

. { printf("Caracter invalido: %s\n", yytext); }

%%

int yywrap() {
return 1;
}