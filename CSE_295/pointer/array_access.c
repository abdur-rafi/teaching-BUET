#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;
    printf("Accessing array elements in different ways:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
        printf("*(arr + %d) = %d\n", i, *(arr + i));
        printf("p[%d] = %d\n", i, p[i]);
        printf("*(p + %d) = %d\n", i, *(p + i));
        printf("i[p] = %d\n", i[p]);
        printf("*(i + p) = %d\n", *(i + p));
        printf("i[arr] = %d\n", i[arr]);
        printf("*(i + arr) = %d\n", *(i + arr));
        printf("-----------------------------\n");
    }
    return 0;
}