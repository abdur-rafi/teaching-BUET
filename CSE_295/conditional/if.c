#include <stdio.h>


int main(){

    int a = 15, b = 10, c = 5;

    if(a > b){
        printf("a is greater than b\n");
    }

    if(a > b && a > c){
        printf("a is largest number\n");
    }

    b = 0;

    if(b){
        printf("b is non zero\n");
    }

    if(a = b){
        // printf("a = %a\n", a);
        printf("a = b evaluated to non zero value\n");
    }
    else{
        printf("a = b evaluated to zero value\n");
    }

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    if(1){
        printf("This will always be true\n");
    }
    
    

}