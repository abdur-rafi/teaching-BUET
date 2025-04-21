#include <stdio.h>

int main() {
    int a = 10, b = 5, c;

    c = a;
    printf("c = a: %d\n", c);

    c += b;
    printf("c += b: %d\n", c);

    c -= b;
    printf("c -= b: %d\n", c);

    c *= b;
    printf("c *= b: %d\n", c);

    c /= b;
    printf("c /= b: %d\n", c);

    c %= b;
    printf("c %%= b: %d\n", c);

    return 0;
}
