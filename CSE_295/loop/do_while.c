#include <stdio.h>

int main(){
    int nStudents;

    do {
        printf("Please enter a positive number of students: ");
        scanf("%d", &nStudents);
        if(nStudents <= 0) {
            printf("Invalid input. \n");
        }
    } while (nStudents <= 0);
    
    float sum = 0;
    int inputRemaining = nStudents;

    while (inputRemaining > 0)
    {
        float mark;
        printf("Enter mark: ");
        scanf("%f", &mark);

        while (mark < 0 || mark > 100) {
            printf("Invalid mark. Please enter a mark between 0 and 100: ");
            scanf("%f", &mark);
        }

        sum += mark;
        inputRemaining--;
    }
    
    float average = sum / nStudents;
    
    printf("The average mark is: %.2f\n", average);

    return 0;
}