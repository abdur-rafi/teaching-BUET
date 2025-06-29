// Demonstration of Enums in C
#include <stdio.h>
#include <string.h>

// 1. Basic enum declaration and usage
enum Day { SUN, MON, TUE, WED, THU, FRI, SAT };

// 2. Enum with custom values
enum Status { OK = 200, NOT_FOUND = 404, ERROR = 500 };

// 3. Typedef enum for easier usage
typedef enum {
    RED,
    GREEN,
    BLUE
} Color;

// 4. Enum as function argument
void print_day(enum Day d) {
    const char* names[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    printf("Day: %s (%d)\n", names[d], d);
}

// 5. Enum in a struct
struct Task {
    char name[32];
    enum Status status;
};

// 6. Enum in switch-case
void handle_status(enum Status s) {
    switch(s) {
        case OK: printf("Status: OK\n"); break;
        case NOT_FOUND: printf("Status: Not Found\n"); break;
        case ERROR: printf("Status: Error\n"); break;
        default: printf("Status: Unknown\n"); break;
    }
}

int main() {
    // Basic usage
    enum Day today = WED;
    print_day(today);

    // Enum with custom values
    enum Status s1 = OK, s2 = NOT_FOUND, s3 = ERROR;
    printf("Status codes: OK=%d, NOT_FOUND=%d, ERROR=%d\n", OK, NOT_FOUND, ERROR);
    handle_status(s2);

    // Typedef enum
    Color c = GREEN;
    printf("Color value: %d\n", c);

    // Enum in struct
    struct Task t1 = {"Homework", OK};
    struct Task t2 = {"Exam", ERROR};
    printf("Task: %s, Status: %d\n", t1.name, t1.status);
    printf("Task: %s, Status: %d\n", t2.name, t2.status);
    handle_status(t2.status);

    // Enum array
    enum Day week[7] = {SUN, MON, TUE, WED, THU, FRI, SAT};
    printf("Days of week: ");
    for(int i=0; i<7; i++) printf("%d ", week[i]);
    printf("\n");

    // Enum comparison
    if (today == WED) printf("Today is Wednesday!\n");

    return 0;
}

/*
Expected Output (example):
Day: Wednesday (3)
Status codes: OK=200, NOT_FOUND=404, ERROR=500
Status: Not Found
Color value: 1
Task: Homework, Status: 200
Task: Exam, Status: 500
Status: Error
Days of week: 0 1 2 3 4 5 6 
Today is Wednesday!

Explanation:
- Enums assign names to integer constants, improving code readability.
- You can set custom values, use enums in structs, arrays, functions, and switch-case.
- Typedef makes enum usage easier.
*/
