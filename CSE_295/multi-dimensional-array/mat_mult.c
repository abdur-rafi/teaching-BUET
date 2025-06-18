#include <stdio.h>

void input_matrix(int row, int col, int a[row][col])
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void multiply_matrices(int rows1, int cols1, int rows2, int cols2,
                       int mat1[rows1][cols1], int mat2[rows2][cols2],
                       int result[rows1][cols2])
{
    for(int i = 0; i < rows1; ++i){
        for(int j = 0; j < cols2; ++j){
            // ith row, jth col 
            int sum = 0;
            // mat1[i][] mat2[][j]
            for(int k = 0; k < cols1; ++k){
                sum += mat1[i][k] * mat2[k][j];
            }
            result[i][j] = sum;
        }
    }
}

int main()
{

    int rows1, cols1, rows2, cols2;
    printf("Enter number of rows and columns for first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter number of rows and columns for second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    if (cols1 != rows2)
    {
        printf("Matrix multiplication not possible: columns of first matrix must equal rows of second matrix.\n");
        return 1;
    }

    int mat1[rows1][cols1], mat2[rows2][cols2], result[rows1][cols2];

    printf("Enter elements of first matrix:\n");
    input_matrix(rows1, cols1, mat1);
    printf("Enter elements of second matrix:\n");
    input_matrix(rows2, cols2, mat2);
}