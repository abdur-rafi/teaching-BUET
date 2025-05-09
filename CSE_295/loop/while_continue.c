#include <stdio.h>


int main(){
    int n = 50;
    int i = 0; 
    while(i < n){
        if(i % 2 == 0){
            // it will cause infinite loop. unline for loop, while loop
            // does not have increment or decrement statement
            // in the loop.
            // so we need to increment i here or
            // we can move the increment statement to the start of the loop
            continue; 
        }
        printf("i : %d\n", i);
        i++;
    }

    i = 0;
    while(i < n){
        i++;
        if(i % 2 == 0){
            // it will not cause infinite loop.
            continue; 
        }
        printf("i : %d\n", i);
    }
    

    return 0;
}