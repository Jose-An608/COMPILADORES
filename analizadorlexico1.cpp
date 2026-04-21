#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Tipos de token
typedef enum{
    KEYWORD,
    IDENTIFIER,
    NUMBER,
    OPERATOR,
    DELIMITER,
    STRING,
    UNKNOWN
} TokenType;

// Verifica si es letra
int isLetter(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Verifica si es dígito
int isDigit(char c){
    return (c >= '0' && c <= '9');
}

// Verifica palabras reservadas
int isKeyword(char *str){
    const char *keywords[] = {"int", "float", "if", "else", "while", "return"};
    int n = 6;

    for(int i = 0; i < n; i++){
        if(strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

// Analizador léxico
void lexer(FILE *file){
    char c;

    while((c = fgetc(file)) != EOF){

        // Ignorar espacios
        if(isspace(c))
            continue;

        // Identificadores o keywords
        if(isLetter(c)){
            char buffer[100];
            int i = 0;

            do{
                buffer[i++] = c;
                c = fgetc(file);
            }while(isLetter(c) || isDigit(c));

            buffer[i] = '\0';
            ungetc(c, file);

            if(isKeyword(buffer))
                printf("[KEYWORD: %s]\n", buffer);
            else
                printf("[IDENTIFIER: %s]\n", buffer);
        }

        // Números
        else if(isDigit(c)){
            char buffer[100];
            int i = 0;

            do{
                buffer[i++] = c;
                c = fgetc(file);
            }while(isDigit(c));

            buffer[i] = '\0';
            ungetc(c, file);

            printf("[NUMBER: %s]\n", buffer);
        }

        // Operadores
        else if(c == '+' || c == '-' || c == '*' || c == '='){
            printf("[OPERATOR: %c]\n", c);
        }

        // Delimitadores
        else if(c == ';' || c == ',' || c == '(' || c == ')'){
            printf("[DELIMITER: %c]\n", c);
        }

        // Desconocido
        else{
            printf("[UNKNOWN: %c]\n", c);
        }
    }
}

int main(){
    FILE *file = fopen("input.c", "r");

    if(!file){
        printf("Error al abrir archivo\n");
        return 1;
    }

    lexer(file);
    fclose(file);

    return 0;
}
