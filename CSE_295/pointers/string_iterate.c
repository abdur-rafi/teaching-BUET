#include <stdio.h>

int main() {
    char str[] = "Hello, world!";
    char *p = str;
    printf("Iterating string using pointer:\n");
    while (*p != '\0') {
        printf("%c ", *p);
        p++;
    }
    printf("\n");
    return 0;
}