#include <stdio.h>

int main(){
    
    int a= 12, b= 5, c = 3;

    int r1 = a * b / c ;

    int r2 = b / c * a;
    
    printf("r1: %d\n", r1);
    printf("r2: %d\n", r2);

    int e = 10, f = 15, g = 20;

    int h = e * f % g;

    printf("h: %d\n", h);

    int a1 = 12, b1 = 5, c1 = -1;

    int r3 = a1 > b1 && !b1 < c1;

    printf("r3: %d\n", r3);

    return 0;
}