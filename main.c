#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* keyw[] =
{
    "int", "char", "float", "double", "void",
    "if", "else", "while", "for", "return"
};

int isKeyword(char* str) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(keyw[i], str) == 0) {
            return 1;
        }
    }
    return 0;
}

int checkVariable(char* var) {
    if (!isalpha(var[0]) && var[0] != '_') {
        return 0;
    }
    for (int i = 1; var[i] != '\0'; i++) {
        if (!isalnum(var[i]) && var[i] != '_') {
            return 0;
        }
    }
    return 1;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '=' || c == '%');
}

int isNumber(char* str) {
    int i = 0, dotCount = 0;

    if (str[i] == '-' || str[i] == '+') i++;

    while (str[i] != '\0') {
        if (str[i] == '.') {
            dotCount++;
            if (dotCount > 1) return 0;
        } else if (!isdigit(str[i])) {
            return 0;
        }
        i++;
    }
    return i > 0;
}

int isPunctuation(char c) {
    return (c == ';' || c == ',' || c == '(' || c == ')' || c == '{' || c == '}');
}

void lex(char* input) {
    char word[50];
    int index = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (isspace(input[i])) {
            if (index > 0) {
                word[index] = '\0';
                if (isKeyword(word)) {
                    printf("Keyword: %s\n", word);
                } else if (isNumber(word)) {
                    printf("Number: %s\n", word);
                } else if (checkVariable(word)) {
                    printf("Variable: %s\n", word);
                } else {
                    printf("Invalid token: %s\n", word);
                }
                index = 0;
            }
            continue;
        }

        if (isOperator(input[i])) {
            if (index > 0) {
                word[index] = '\0';
                if (isKeyword(word)) {
                    printf("Keyword: %s\n", word);
                } else if (isNumber(word)) {
                    printf("Number: %s\n", word);
                } else if (checkVariable(word)) {
                    printf("Variable: %s\n", word);
                } else {
                    printf("Invalid token: %s\n", word);
                }
                index = 0;
            }
            printf("Operator: %c\n", input[i]);
            continue;
        }

        if (isPunctuation(input[i])) {
            if (index > 0) {
                word[index] = '\0';
                if (isKeyword(word)) {
                    printf("Keyword: %s\n", word);
                } else if (isNumber(word)) {
                    printf("Number: %s\n", word);
                } else if (checkVariable(word)) {
                    printf("Variable: %s\n", word);
                } else {
                    printf("Invalid token: %s\n", word);
                }
                index = 0;
            }
            printf("Punctuation: %c\n", input[i]);
            continue;
        }

        word[index++] = input[i];
    }

    if (index > 0) {
        word[index] = '\0';
        if (isKeyword(word)) {
            printf("Keyword: %s\n", word);
        } else if (isNumber(word)) {
            printf("Number: %s\n", word);
        } else if (checkVariable(word)) {
            printf("Variable: %s\n", word);
        } else {
            printf("Invalid token: %s\n", word);
        }
    }
}

int main() {
    char input[100];
    printf("Enter an expression: ");
    gets(input);
    lex(input);
    return 0;
}
