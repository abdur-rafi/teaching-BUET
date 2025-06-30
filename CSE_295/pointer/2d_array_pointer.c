#include <stdio.h>

int main() {
    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    printf("Accessing 2D array using arr directly:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("arr[%d][%d] = %d\t", i, j, *(*(arr + i) + j));
        }
        printf("\n");
    }
    printf("Accessing 2D array using pointer arithmetic:\n");
    int *q = &arr[0][0];
    for (int i = 0; i < 2 * 3; i++) {
        printf("%d ", *(q + i));
    }
    printf("\n");
    return 0;
}