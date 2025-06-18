#include <stdio.h>

int fact(int n){
    if(n < 0){
        printf("n cannot be negative\n");
        return;
    }
    if (n == 0){
        return 1;
    }

    return n * fact(n - 1);

}

int fibonacchi(int n){
    if(n == 1) return 0;
    if (n == 2) return 1;

    return fibonacchi(n-1) + fibonacchi(n-2);
}