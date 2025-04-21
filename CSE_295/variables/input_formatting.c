#include <stdio.h>

int main() {
    int a, b;

    printf("Address of a: %p\n", &a);
    printf("Address of b: %p\n", &b);

    printf("Enter two integers (space-separated): ");
    scanf("%d %d", &a, &b);
    printf("You entered: %d and %d\n", a, b);

    printf("Enter two integers (comma-separated): ");
    scanf("%d,%d", &a, &b);
    printf("You entered: %d and %d\n", a, b);

    printf("Enter two integers (dash-separated): ");
    scanf("%d-%d", &a, &b);

    printf("You entered: %d and %d\n", a, b);

    printf("Enter two integers (slash-separated): ");
    scanf("%d/%d", &a, &b);
    printf("You entered: %d and %d\n", a, b);

    return 0;
}
