#include <stdio.h>


int value_of_determinant(int n, int determinant[n][n]){
    if (n == 1){
        return determinant[0][0];
    }
    if(n == 2){
        return determinant[0][0] * determinant[1][1] - determinant[1][0] * determinant[0][1];
    }
    int value = 0;

    for(int i = 0; i < n; ++i){
        int curr_element_of_first_row = determinant[0][i];
        int sign = 1;
        if(i % 2 == 1){
            sign = -1;
        }
        int sub_determinant[n-1][n-1];

        for(int r = 1; r < n; ++r){
            int curr_col_in_sub_determinant = 0;
            for(int c = 0; c < n; ++c){
                if(c == i){
                    continue;
                }
                sub_determinant[r - 1][curr_col_in_sub_determinant] = determinant[r][c];
                curr_col_in_sub_determinant++;  
            }
        }
        int value_of_sub_determinant = value_of_determinant(n - 1, sub_determinant);
        value += sign * curr_element_of_first_row * value_of_sub_determinant;
    }

    return value;
}