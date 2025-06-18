#include <stdio.h>

int main() {
    // 1. Initialize all elements to zero
    int arr1[2][3] = {0};

    // 2. Initialize with nested braces
    int arr2[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    // 3. Initialize without nested braces (row-major order)
    int arr3[2][3] = {1, 2, 3, 4, 5, 6};

    // 4. Partial initialization (rest are zero)
    int arr4[2][3] = {
        {1},    // {1, 0, 0}
        {4, 5}  // {4, 5, 0}
    };

    // 5. Omit size of first dimension
    int arr5[][3] = {
        {7, 8, 9},
        {10, 11, 12}
    };

    

    // Print one array for demonstration
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }

    return 0;
}