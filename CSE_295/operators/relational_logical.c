#include <stdio.h>

int main() {
    int a = 10, b = 20, c = 30;

    int isALessThanB = a < b;
    int isAGreaterThanB = a > b;
    int isALessThanOrEqualToB = a <= b;
    int isAGreaterThanOrEqualToB = a >= b;
    int isAEqualToB = a == b;
    int isANotEqualToB = a != b;


    printf("a < b: %d\n", isALessThanB);
    printf("a > b: %d\n", isAGreaterThanB);
    printf("a <= b: %d\n", isALessThanOrEqualToB);
    printf("a >= b: %d\n", isAGreaterThanOrEqualToB);
    printf("a == b: %d\n", isAEqualToB);
    printf("a != b: %d\n", isANotEqualToB);

    
    int isALessThanBAndC = (a < b) && (b < c);
    int isALessThanBOrC = (a < b) || (b < c);
    int isNotALessThanB = !(a < b);
    
    printf("a < b AND b < c: %d\n", isALessThanBAndC);
    printf("a < b OR b < c: %d\n", isALessThanBOrC);
    printf("NOT (a < b): %d\n", isNotALessThanB);


    return 0;
}