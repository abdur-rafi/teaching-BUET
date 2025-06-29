// Demonstration of Structures in C
#include <stdio.h>
#include <string.h>

// 1. Structure Declaration
struct Student {
    char name[50];
    int age;
    float gpa;
};

// 2. Nested Structure
struct Date {
    int day, month, year;
};

struct Book {
    char title[100];
    char author[50];
    struct Date published;
};

// 3. Array of Structures
void print_students(struct Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Student %d: %s, Age: %d, GPA: %.2f\n", i+1, students[i].name, students[i].age, students[i].gpa);
    }
}

// 4. Passing Structure to Function
void print_book(struct Book b) {
    printf("Book: %s by %s, Published: %02d-%02d-%04d\n", b.title, b.author, b.published.day, b.published.month, b.published.year);
}

// Demonstrate structure copy on function call
void modify_student(struct Student s) {
    printf("Inside modify_student (before): %s, Age: %d, GPA: %.2f\n", s.name, s.age, s.gpa);
    s.age = 99; // Change value
    strcpy(s.name, "Modified");
    printf("Inside modify_student (after): %s, Age: %d, GPA: %.2f\n", s.name, s.age, s.gpa);
}

// 5. Returning Structure from Function
struct Student create_student(char name[50], int age, float gpa) {
    struct Student s;
    strncpy(s.name, name, sizeof(s.name));
    s.name[sizeof(s.name)-1] = '\0';
    s.age = age;
    s.gpa = gpa;
    return s;
}

// 6. Structure without a name (anonymous struct)
struct {
    char brand[20];
    int year;
} car1 = {"Toyota", 2020}, car2 = {"Honda", 2022};

int main() {
    // Initializing a structure
    struct Student s1 = {"Alice", 20, 3.8};
    struct Student s2;
    strcpy(s2.name, "Bob");
    s2.age = 22;
    s2.gpa = 3.5;

    // Array of structures
    struct Student class[] = {s1, s2, create_student("Charlie", 21, 3.9)};
    int n = 3;
    print_students(class, n);

    // Nested structure
    struct Book book1 = {"C Programming", "Dennis Ritchie", {22, 2, 1978}};
    print_book(book1);

    // Structure assignment
    struct Student s3 = s1;
    printf("Copied Student: %s, GPA: %.2f\n", s3.name, s3.gpa);

    // Demonstrate structure copy on function call
    printf("Before modify_student: %s, Age: %d, GPA: %.2f\n", s1.name, s1.age, s1.gpa);
    modify_student(s1);
    printf("After modify_student: %s, Age: %d, GPA: %.2f\n", s1.name, s1.age, s1.gpa);

    // Anonymous structure usage
    printf("Anonymous struct car1: %s, Year: %d\n", car1.brand, car1.year);
    printf("Anonymous struct car2: %s, Year: %d\n", car2.brand, car2.year);

    return 0;
}
