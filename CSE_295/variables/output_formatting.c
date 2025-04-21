#include <stdio.h>

int main() {
    int integer = 12345;
    float floating = 123.456789;

    printf("Default integer: %d\n", integer);
    printf("Integer with width 10: %10d\n", integer);
    printf("Integer with width 10, left-aligned: %-10d\n", integer);
    printf("Integer with leading zeros: %010d\n", integer);
    printf("Integer in octal: %o\n", integer);
    printf("Integer in hexadecimal (lowercase): %x\n", integer);
    printf("Integer in hexadecimal (uppercase): %X\n", integer);

    printf("\nDefault float: %f\n", floating);
    printf("Float with 2 decimal places: %.2f\n", floating);
    printf("Float with 4 decimal places: %.4f\n", floating);
    printf("Float in scientific notation: %e\n", floating);
    printf("Float with width 10 and 2 decimal places: %10.2f\n", floating);
    printf("Float with width 10, left-aligned, 2 decimal places: %-10.2f\n", floating);

    return 0;
}