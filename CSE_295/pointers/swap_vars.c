#include <stdio.h>


// try to write a function that swap two integers
// Will it work as expected?
void swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}


int main(){
    int x = 5;
    int y = 10;

    printf("Before swap: x = %d, y = %d\n", x, y);
    
    // Call the swap function
    swap(x, y);
    
    printf("After swap: x = %d, y = %d\n", x, y); // This will not show swapped values
    // The values of x and y remain unchanged because in c, when you pass variables to a function,
    // their values are copied to the function parameters.
    // This means that the swap function only swaps the copies of the values, not the original
    // variables themselves.

    return 0;
}