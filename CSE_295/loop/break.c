#include <stdio.h>


int main(){

    double avg = 0;
    int breakLoop = 0;


    while(1){
        printf("Enter 2 numbers and an operator (+, -, *, /) or 'q' to quit: ");
        double num1, num2;
        double result = 0;
        char op;
        scanf("%lf %lf %c", &num1, &num2, &op);
        switch(op){
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if(num2 == 0){
                    printf("Error: Division by zero\n");
                    continue; // skip to the next iteration
                }
                result = num1 / num2;
                break;
            case 'q':
                printf("Exiting...\n");
                breakLoop = 1; // set the flag to exit the loop
                break;
            default:
                printf("Invalid operator. Please try again.\n");
                continue; // skip to the next iteration
        }
        if(breakLoop){
            break; // exit the loop
        }
        printf("%f %c %f = %f\n", num1, op, num2, result);

    }

    

    return 0;
}