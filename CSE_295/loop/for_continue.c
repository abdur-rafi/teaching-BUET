#include <stdio.h>


int main(){
    int n = 50;
    for(int i = 0;i < n; ++i){
        if(i % 2 == 0){
            continue; 
        }
        printf("i : %d\n", i);
    }

    

    return 0;
}