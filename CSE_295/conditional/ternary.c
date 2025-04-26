#include <stdio.h>

int main() {
    // int a = 10, b = 20;
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    int max = (a > b) ? a : b;

    printf("The maximum value is: %d\n", max);

    int c = ((a > b) ? a : b) * 5;
    printf("The value of c is: %d\n", c);

    return 0;
}