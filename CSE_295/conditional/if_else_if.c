#include <stdio.h>


int main(){

    int a = 10, b = 20, c = 30;

    // use only if to find the largest number
    if(a > b){
        if(a > c){
            printf("a is largest number\n");
        }
    }
    else{
        if(b > c){
            printf("b is largest number\n");
        }
        else{
            printf("c is largest number\n");
        }
    }

    // use if else if to find the largest number
    if(a > b && a > c){
        printf("a is largest number\n");
    }
    else if(b > c){
        printf("b is largest number\n");
    }
    else{
        printf("c is largest number\n");
    }


    int grade = 85;

    if(grade >= 90 && grade <= 100){
        printf("Grade: A\n");
    }
    else if(grade >= 80 && grade < 90){
        printf("Grade: B\n");
    }
    else if(grade >= 70 && grade < 80){
        printf("Grade: C\n");
    }
    else if(grade >= 60 && grade < 70){
        printf("Grade: D\n");
    }
    else if(grade >= 0 && grade < 60){
        printf("Grade: F\n");
    }
    else{
        printf("Invalid grade\n");
    }

    // Simplified grade evaluation without redundant checks
    if (grade >= 90) {
        printf("Grade: A\n");
    }
    else if (grade >= 80) {
        printf("Grade: B\n");
    }
    else if (grade >= 70) {
        printf("Grade: C\n");
    }
    else if (grade >= 60) {
        printf("Grade: D\n");
    }
    else if (grade >= 0) {
        printf("Grade: F\n");
    }
    else {
        printf("Invalid grade\n");
    }

    // remove the braces
    if (grade >= 90)
        printf("Grade: A\n");
    else if (grade >= 80)
        printf("Grade: B\n");
    else if (grade >= 70)
        printf("Grade: C\n");
    else if (grade >= 60)
        printf("Grade: D\n");
    else if (grade >= 0)
        printf("Grade: F\n");
    else
        printf("Invalid grade\n");

    return 0;
}