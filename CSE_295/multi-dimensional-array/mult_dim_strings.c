#include <stdio.h>

int main() {
    // 2D array of strings
    char fruits[3][10] = {
        "Apple",
        "Banana",
        "Cherry"
    };

    // 3D array of strings: 2 categories, each with 2 fruits, each fruit name up to 10 chars
    char categories[2][2][10] = {
        { "Apple", "Banana" },
        { "Mango", "Peach" }
    };

    // Print 2D array
    for (int i = 0; i < 3; i++) {
        printf("fruits[%d]: %s\n", i, fruits[i]);
    }

    // Print 3D array
    for (int i = 0; i < 2; i++) {
        printf("Category %d:\n", i);
        for (int j = 0; j < 2; j++) {
            printf("  categories[%d][%d]: %s\n", i, j, categories[i][j]);
        }
    }

    return 0;
}