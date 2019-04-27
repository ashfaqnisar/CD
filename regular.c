#include <stdio.h>
#include <string.h>

int main() {//change this regular to main
    char ip[20], c;
    int i, j = 0, len, state = 0;
    printf("Enter the string");
    scanf("%s", ip);
    len = i = strlen(ip);
    while (i > 0) {
        c = ip[j];
        switch (state) {
            case 0:
                if (c == 'a')
                    state = 1;
                if (c == 'b')
                    state = 2;
                if (c == 'c')
                    state = 3;

                break;
            case 1:
                if (c == 'a')
                    state = 1;
                if (c == 'b')
                    state = 2;

                if (c == 'c')
                    state = 3;
                break;
            case 2:
                if (c == 'a')
                    state = 1;
                if (c == 'b')
                    state = 2;
                if (c == 'c')
                    state = 3;
                break;
            default:
                printf("Please provide a valid string");
        }
        j = j + 1;
        i = i - 1;
    }
    if (state == 1) {
        if (len == 1)
            printf("This is a string a and a+re");
        else
            printf("This not another string a+re");
    } else if (state == 2) {
        if (len == 3)
            printf("This is  a string a*b+ and abb re");
        else
            printf("This is not a string a*b+re");
    } else
        printf("Invalid String");

    return 0;
}