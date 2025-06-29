// Demonstration of structure size and padding in C
#include <stdio.h>

struct NoPadding {
    char a;
    char b;
    char c;
};

struct WithPadding {
    char a;
    int b;
};

struct Mixed {
    char a;
    double b;
    int c;
    char d;
};

int main() {
    struct NoPadding np;
    printf("Size of struct NoPadding: %zu (actual), %zu (minimum guaranteed)\n", sizeof(np), sizeof(char) + sizeof(char) + sizeof(char));
    printf("Size of struct WithPadding: %zu (actual), %zu (minimum guaranteed)\n", sizeof(struct WithPadding), sizeof(char) + sizeof(int));
    printf("Size of struct Mixed: %zu (actual), %zu (minimum guaranteed)\n", sizeof(struct Mixed), sizeof(char) + sizeof(double) + sizeof(int) + sizeof(char));

    return 0;
}

/*
Expected Output (example on a typical 64-bit system):
Size of struct NoPadding: 3 (actual), 3 (minimum guaranteed)
Size of struct WithPadding: 8 (actual), 5 (minimum guaranteed)
Size of struct Mixed: 24 (actual), 14 (minimum guaranteed)

Explanation:
- The 'actual' size is what sizeof returns, which may include padding bytes added by the compiler for alignment.
- The 'minimum guaranteed' size is the sum of the sizes of the individual members, as required by the C standard.
- The actual size can be larger than the minimum guaranteed size due to padding.

Note:
The actual size of structures is compiler- and platform-dependent. The output you see on your machine may differ from the example above. 
*/
