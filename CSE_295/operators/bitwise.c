#include <stdio.h>

void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;
    
    for (i = size-1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

int main() {
    unsigned short int a = 5;  
    unsigned short int b = 9;  

    printBits(sizeof(a), &a);
    printBits(sizeof(b), &b);

    unsigned short int c = a & b;
    printf("a & b = ");
    printBits(sizeof(c), &c);

    c = a | b;
    printf("a | b = ");
    printBits(sizeof(c), &c);

    c = a ^ b;
    printf("a ^ b = ");
    printBits(sizeof(c), &c);

    c = a >> 2;
    printf("a >> 2 = ");
    printBits(sizeof(c), &c);

    c = a << 2;
    printf("a << 2 = ");
    printBits(sizeof(c), &c);

    c = ~a;
    printf("~a = ");
    printBits(sizeof(c), &c);



    return 0;
}