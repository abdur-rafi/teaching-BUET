#include <stdio.h>


int main(){

    int month;
    printf("Enter month number (1-12): ");
    scanf("%d", &month);

    if (month == 1) {
        printf("January\n");
    } else if (month == 2) {
        printf("February\n");
    } else if (month == 3) {
        printf("March\n");
    } else if (month == 4) {
        printf("April\n");
    } else if (month == 5) {
        printf("May\n");
    } else if (month == 6) {
        printf("June\n");
    } else if (month == 7) {
        printf("July\n");
    } else if (month == 8) {
        printf("August\n");
    } else if (month == 9) {
        printf("September\n");
    } else if (month == 10) {
        printf("October\n");
    } else if (month == 11) {
        printf("November\n");
    } else if (month == 12) {
        printf("December\n");
    } else {
        printf("Invalid month number\n");
    }

    switch (month) {
        case 1:
            printf("January\n");
            break;
        case 2:
            printf("February\n");
            break;
        case 3:
            printf("March\n");
            break;
        case 4:
            printf("April\n");
            break;
        case 5:
            printf("May\n");
            break;
        case 6:
            printf("June\n");
            break;
        case 7:
            printf("July\n");
            break;
        case 8:
            printf("August\n");
            break;
        case 9:
            printf("September\n");
            break;
        case 10:
            printf("October\n");
            break;
        case 11:
            printf("November\n");
            break;
        case 12:
            printf("December\n");
            break;
        default:
            printf("Invalid month number\n");
            break;
    }
    

    return 0;
}