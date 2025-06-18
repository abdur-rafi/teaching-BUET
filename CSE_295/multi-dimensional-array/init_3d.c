#include <stdio.h>

int main() {
    // 1. Zero initialization
    int arr1[2][3][4] = {0};

    // 2. Full explicit initialization
    int arr2[2][3][4] = {
        {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
        },
        {
            {13, 14, 15, 16},
            {17, 18, 19, 20},
            {21, 22, 23, 24}
        }
    };

    // 3. Partial initialization (rest will be zero)
    int arr3[2][3][4] = {
        {
            {1, 2}, // rest are 0
            {3},    // rest are 0
        }
    };

    // 4. Flat initialization (row-major order)
    int arr4[2][3][4] = {
        1, 2, 3, 4, 5, 6, 7, 8,
        9, 10, 11, 12, 13, 14, 15, 16,
        17, 18, 19, 20, 21, 22, 23, 24
    };

    

    return 0;
}