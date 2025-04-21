#include <stdio.h>

int main() {
    int a = 10, b = 3;
    
    a++;
    b--;
    printf("Incremented a: %d\n", a);
    printf("Decremented b: %d\n", b);

    --a;
    ++b;
    printf("Decremented a: %d\n", a);
    printf("Incremented b: %d\n", b);


    int sum = a + b;
    int difference = a - b;
    int product = a * b;
    int quotient = a / b;
    int remainder = a % b;
    int negative = -a;

    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", difference);
    printf("Product: %d\n", product);
    printf("Quotient: %d\n", quotient);
    printf("Remainder: %d\n", remainder);
    printf("Unary Negation: %d\n", negative);

    float x = 10.5, y = 3.2;
    float float_sum = x + y;
    float float_difference = x - y;
    float float_product = x * y;
    float float_quotient = x / y;

    printf("Float Sum: %.2f\n", float_sum);
    printf("Float Difference: %.2f\n", float_difference);
    printf("Float Product: %.2f\n", float_product);
    printf("Float Quotient: %.2f\n", float_quotient);
    

    return 0;
}