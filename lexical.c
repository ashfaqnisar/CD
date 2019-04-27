#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int keyword = 0, operator = 0, identifier = 0;

bool isDelimiter(char *str) {
    if (!strcmp(str, " ") || !strcmp(str, "+") || !strcmp(str, "-") ||
        !strcmp(str, "*") || !strcmp(str, "/") || !strcmp(str, "%") ||
        !strcmp(str, "<") || !strcmp(str, ">") || !strcmp(str, "=") ||
        !strcmp(str, "==") || !strcmp(str, ",") || !strcmp(str, ":") ||
        !strcmp(str, ";") || !strcmp(str, ">") || !strcmp(str, "<") ||
        !strcmp(str, "!") || !strcmp(str, "{") || !strcmp(str, "}") ||
        !strcmp(str, "(") || !strcmp(str, ")") || !strcmp(str, "[") ||
        !strcmp(str, "]") || !strcmp(str, "<")) {
        return true;
    }
    return false;
}

bool isOperator(char *str) {
    if (!strcmp(str, "+") || !strcmp(str, "-") || !strcmp(str, "*") ||
        !strcmp(str, "/") || !strcmp(str, "%") || !strcmp(str, "<") ||
        !strcmp(str, ">") || !strcmp(str, "=") || !strcmp(str, "==")) {
        return true;
    }
    return false;

}

bool isInt(char *str) {
    if (!strcmp(str, "0") || !strcmp(str, "1") || !strcmp(str, "2") ||
        !strcmp(str, "3") || !strcmp(str, "4") || !strcmp(str, "5") ||
        !strcmp(str, "6") || !strcmp(str, "7") || !strcmp(str, "8") ||
        !strcmp(str, "9")) {
        return true;
    }
    return false;
}

bool isKeyword(char *str) {
    if (!strcmp(str, "for") || !strcmp(str, "if") || !strcmp(str, "while") ||
        !strcmp(str, "else") || !strcmp(str, "do") || !strcmp(str, "int") ||
        !strcmp(str, "float") || !strcmp(str, "string") || !strcmp(str, "char") ||
        !strcmp(str, "long") || !strcmp(str, "true") || !strcmp(str, "switch") ||
        !strcmp(str, "return") || !strcmp(str, "void") || !strcmp(str, "break")) {

        return true;
    }
    return false;

}

bool isIdentifier(char *str) {
    int len = strlen(str);
    if (len == 0) {
        return false;
    }
    if (!strcmp(str, "0") || !strcmp(str, "1") || !strcmp(str, "2") ||
        !strcmp(str, "3") || !strcmp(str, "4") || !strcmp(str, "5") ||
        !strcmp(str, "6") || !strcmp(str, "7") || !strcmp(str, "8") ||
        !strcmp(str, "9") || isDelimiter(str) == true) {
        return false;
    }
    return true;
}

char *splitTheString(char *inputstr) {
    char *str = inputstr;
    char *p;

    p = strtok(str, " ");

    while (p != NULL) {
        if (isKeyword(p)) {
            printf("%s is a keyword\n", p);
            keyword++;
        } else if (isInt(p)) {
            printf("%s is an integer\n", p);
        } else if (isDelimiter(p)) {
            if (isOperator(p)) {
                printf("%s is an operator\n", p);
                operator++;
            }
            printf("%s is a an delimeter\n", p);
        } else if (isIdentifier(p)) {
            printf("%s is an identifier \n", p);
            identifier++;
        }

        p = strtok(NULL, " ");
    }
    return p;
}

void printTheTotals() {
    printf("\nTotal no of operators are: %d", operator);
    printf("\nTotal no of identifiers are: %d", identifier);
    printf("\nTotal no of keywords are %d", keyword);
}

int main() {

    char input[50] = "int i = 5 ;";
    char input2[50] = "if ( i == 5 ) {";
    char input3[50] = "return true ; }";
    splitTheString(input);
    splitTheString(input2);
    splitTheString(input3);
    printTheTotals();

    return 0;
}