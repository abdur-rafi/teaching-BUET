#include <stdio.h>


void print_matrix(int row, int col, int a[row][col]){
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void input_matrix(int row, int col, int a[row][col]){
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}


void add_matrices(int row, int col, int a[row][col], int b[row][col], int result[row][col]){
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

int main(){


    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int mat1[rows][cols], mat2[rows][cols];

    input_matrix(rows, cols, mat1);

    input_matrix(rows, cols, mat2);

    print_matrix(rows, cols, mat1);
    print_matrix(rows, cols, mat2);

    int result[rows][cols];

    return 0;
}
