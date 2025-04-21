#include <stdio.h>

int main(void){

    char c;
    printf("Enter a character: ");
    scanf("%c", &c);
    printf("You entered: %c\n", c);

    int a;
    printf("Enter an integer: ");
    scanf("%d", &a);
    printf("You entered: %d\n", a);

    float b;
    printf("Enter a float: ");
    scanf("%f", &b);
    printf("You entered: %f\n", b);
    
    

    return 0;
}