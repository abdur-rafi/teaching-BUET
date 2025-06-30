#include <stdio.h>

int main() {
    int a = 10, b = 20, c = 30, d = 40;
    int *arr[4];
    arr[0] = &a;
    arr[1] = &b;
    arr[2] = &c;
    arr[3] = &d;
    printf("Array of pointers to integers:\n");
    for (int i = 0; i < 4; i++) {
        printf("Value at arr[%d]: %d\n", i, *arr[i]);
    }
    printf("Addresses stored in arr:\n");
    for (int i = 0; i < 4; i++) {
        printf("arr[%d] points to address: %p\n", i, arr[i]);
    }

    // Another example: pointer array initialization at declaration
    int x = 100, y = 200, z = 300;
    int *ptrs[3] = {&x, &y, &z};
    printf("\nPointer array initialized at declaration:\n");
    for (int i = 0; i < 3; i++) {
        printf("Value at ptrs[%d]: %d\n", i, *ptrs[i]);
    }

    // Example: array of pointers to strings
    const char *fruits[] = {"Apple", "Banana", "Cherry", "Date"};
    int fruits_count = sizeof(fruits) / sizeof(fruits[0]);
    printf("\nArray of pointers to strings (fruits):\n");
    for (int i = 0; i < fruits_count; i++) {
        printf("fruits[%d]: %s\n", i, fruits[i]);
    }
    printf("First letter of each fruit using pointer: ");
    for (int i = 0; i < fruits_count; i++) {
        printf("%c ", *(fruits[i]));
    }
    printf("\n");

    return 0;
}