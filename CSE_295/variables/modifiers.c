#include <stdio.h>

int main() {
    short int shortInt = 123;
    long int longInt = 212312;
    unsigned int unsignedInt = 312312;
    int signedInt = -4234234;
    unsigned long int unsignedLongInt = 5345;
    short unsigned int shortUnsignedInt = 4566;

    unsigned long int sizeOfInt = sizeof(shortInt);
    unsigned long int sizeOfLongInt = sizeof(longInt);
    unsigned long int sizeOfUnsignedInt = sizeof(unsignedInt);
    unsigned long int sizeOfSignedInt = sizeof(signedInt);
    unsigned long int sizeOfUnsignedLongInt = sizeof(unsignedLongInt);
    unsigned long int sizeOfShortUnsignedInt = sizeof(shortUnsignedInt);
    

    printf("short int: Value = %hd, Size = %lu bytes\n", shortInt, sizeOfInt);
    printf("long int: Value = %ld, Size = %lu bytes\n", longInt, sizeOfLongInt);
    printf("unsigned int: Value = %u, Size = %lu bytes\n", unsignedInt, sizeOfUnsignedInt);
    printf("signed int: Value = %d, Size = %lu bytes\n", signedInt, sizeOfSignedInt);
    printf("unsigned long int: Value = %lu, Size = %lu bytes\n", unsignedLongInt, sizeOfUnsignedLongInt);
    printf("short unsigned int: Value = %hu, Size = %lu bytes\n", shortUnsignedInt, sizeOfShortUnsignedInt);
    

    float floatVar = 3.14f;
    double doubleVar = 3.141592653589793;

    unsigned long int sizeOfFloat = sizeof(floatVar);
    unsigned long int sizeOfDouble = sizeof(doubleVar);

    printf("float: Value = %f, Size = %lu bytes\n", floatVar, sizeOfFloat);
    printf("double: Value = %lf, Size = %lu bytes\n", doubleVar, sizeOfDouble);

    return 0;
}
