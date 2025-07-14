#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;
    printf("Pointer p points to arr[0]: %d\n", *p);
    p = p + 2;
    printf("After p = p + 2, p points to arr[2]: %d\n", *p);
    p = p - 1;
    printf("After p = p - 1, p points to arr[1]: %d\n", *p);
    printf("Address of arr[0]: %p\n", arr);
    printf("Address of arr[2]: %p\n", arr + 2);
    printf("Difference (arr + 2) - arr: %ld\n", (arr + 2) - arr);
    return 0;
}