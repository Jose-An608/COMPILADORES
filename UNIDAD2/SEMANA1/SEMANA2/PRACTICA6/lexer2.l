%{
#include "parser2.tab.h"
#include <stdio.h>
%}

%%

"c"     { printf("  [TOKEN] c\n"); return TOK_C; }
"d"     { printf("  [TOKEN] d\n"); return TOK_D; }
"\n"    { return '\n'; }
"\r"    { /* ignorar Windows CR */ }
[ \t]   { /* ignorar espacios */ }
.       { printf("  [LEXICO] simbolo desconocido: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}
