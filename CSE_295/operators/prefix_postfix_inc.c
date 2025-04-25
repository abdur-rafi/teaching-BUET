#include <stdio.h>

int main() {
    int a = 10;
    int b;
    
    b = ++a;

    printf("After prefix increment, a: %d, b: %d\n", a, b);

    a = 10;
    b = a++;

    printf("After postfix increment, a: %d, b: %d\n", a, b);

    // using postfix and prefix operators in expression
    a = 10;
    b = a++ * 4;
    printf("After using postfix in expression, a: %d, b: %d\n", a, b);

    a = 10;
    b = ++a * 4;
    printf("After using prefix in expression, a: %d, b: %d\n", a, b);

    return 0;
}