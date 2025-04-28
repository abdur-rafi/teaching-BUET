#include <stdio.h>


int main(){

    int a = 5, b = 3, c = 0;
    int d = (a > b) || (b = c);

    printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);

    a = 5;
    b = 3;
    c = 0;
    
    int f = (a < b) && (b = c);
    printf("a = %d, b = %d, c = %d, f = %d\n", a, b, c, f);

    return 0;

}