// Demonstration: Modeling Course, Students, Teachers, Forum Posts using Structures in C
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 3
#define MAX_POSTS 2

struct Student {
    int id;
    char name[50];
};

struct Teacher {
    int id;
    char name[50];
};

enum AuthorType { STUDENT, TEACHER };

struct ForumPost {
    int post_id;
    char content[200];
    enum AuthorType author_type; // Use enum for author type
    union {
        struct Student student;
        struct Teacher teacher;
    } author;
};
    // Explanation:
    // A union is used for the author field in ForumPost because a post can be made by either a student or a teacher, but never both at the same time.
    // Using a union saves memory, as only the space for the largest member (Student or Teacher) is allocated, not both.
    // The author_type field indicates which member of the union is valid for each post.
    // This is a common pattern when a field can represent multiple types, but only one is active at a time.

struct Course {
    int course_id;
    char title[100];
    struct Teacher instructor;
    struct Student students[MAX_STUDENTS];
    struct ForumPost posts[MAX_POSTS];
};

// Minimum guaranteed size calculation for all structs:
// struct Student {
//     int id;            // sizeof(int)
//     char name[50];     // 50 * sizeof(char)
// }
// Minimum size = sizeof(int) + 50*sizeof(char)
//
// struct Teacher {
//     int id;            // sizeof(int)
//     char name[50];     // 50 * sizeof(char)
// }
// Minimum size = sizeof(int) + 50*sizeof(char)
//
// struct ForumPost {
//     int post_id;       // sizeof(int)
//     char content[200]; // 200 * sizeof(char)
//     char author_type;  // sizeof(char)
//     union { struct Student student; struct Teacher teacher; } author;
//         // Minimum size of union = max(sizeof(struct Student), sizeof(struct Teacher))
// }
// Minimum size = sizeof(int) + 200*sizeof(char) + sizeof(char) + max(sizeof(struct Student), sizeof(struct Teacher))
//
// struct Course {
//     int course_id;                        // sizeof(int)
//     char title[100];                      // 100 * sizeof(char)
//     struct Teacher instructor;            // sizeof(struct Teacher)
//     struct Student students[MAX_STUDENTS];// MAX_STUDENTS * sizeof(struct Student)
//     struct ForumPost posts[MAX_POSTS];    // MAX_POSTS * sizeof(struct ForumPost)
// }
// Minimum size = sizeof(int) + 100*sizeof(char) + sizeof(struct Teacher)
//              + MAX_STUDENTS*sizeof(struct Student)
//              + MAX_POSTS*sizeof(struct ForumPost)
//
// You can print these values in main as:
// printf("Minimum guaranteed size of struct Student: %zu\n", sizeof(int) + 50*sizeof(char));
// printf("Minimum guaranteed size of struct Teacher: %zu\n", sizeof(int) + 50*sizeof(char));
// printf("Minimum guaranteed size of struct ForumPost: %zu\n", sizeof(int) + 200*sizeof(char) + sizeof(char) + ((sizeof(struct Student) > sizeof(struct Teacher)) ? sizeof(struct Student) : sizeof(struct Teacher)));
// printf("Minimum guaranteed size of struct Course: %zu\n", sizeof(int) + 100*sizeof(char) + sizeof(struct Teacher) + MAX_STUDENTS*sizeof(struct Student) + MAX_POSTS*sizeof(struct ForumPost));
//
// Note: Actual size may be larger due to padding/alignment.

void print_course_info(struct Course c) {
    const char* author_type_str[] = {"Student", "Teacher"};
    printf("Course: %s (ID: %d)\n", c.title, c.course_id);
    printf("Instructor: %s (ID: %d)\n", c.instructor.name, c.instructor.id);
    printf("Students:\n");
    for(int i=0; i<MAX_STUDENTS; i++) {
        printf("  %s (ID: %d)\n", c.students[i].name, c.students[i].id);
    }
    printf("Forum Posts:\n");
    for(int i=0; i<MAX_POSTS; i++) {
        const char* a_type = (c.posts[i].author_type >= 0 && c.posts[i].author_type <= 1) ? author_type_str[c.posts[i].author_type] : "Unknown";
        if (c.posts[i].author_type == STUDENT)
            printf("  Post %d by %s %s: %s\n", c.posts[i].post_id, a_type, c.posts[i].author.student.name, c.posts[i].content);
        else if (c.posts[i].author_type == TEACHER)
            printf("  Post %d by %s %s: %s\n", c.posts[i].post_id, a_type, c.posts[i].author.teacher.name, c.posts[i].content);
        else
            printf("  Post %d by Unknown: %s\n", c.posts[i].post_id, c.posts[i].content);
    }
}

int main() {
    struct Teacher t1 = {1, "Dr. Smith"};
    struct Student s1 = {101, "Alice"};
    struct Student s2 = {102, "Bob"};
    struct Student s3 = {103, "Charlie"};

    struct ForumPost p1 = {1, "What is the deadline for Assignment 1?", STUDENT, {.student = s1}};
    struct ForumPost p2 = {2, "Welcome to the course!", TEACHER, {.teacher = t1}};

    struct Course cse295 = {
        295,
        "Introduction to Programming",
        t1,
        {s1, s2, s3},
        {p1, p2}
    };

    print_course_info(cse295);

    printf("Minimum guaranteed size of struct Student: %zu\n", sizeof(int) + 50*sizeof(char));
    printf("Minimum guaranteed size of struct Teacher: %zu\n", sizeof(int) + 50*sizeof(char));
    printf("Minimum guaranteed size of struct ForumPost: %zu\n", sizeof(int) + 200*sizeof(char) + sizeof(enum AuthorType) + ((sizeof(struct Student) > sizeof(struct Teacher)) ? sizeof(struct Student) : sizeof(struct Teacher)));
    printf("Minimum guaranteed size of struct Course: %zu\n", sizeof(int) + 100*sizeof(char) + sizeof(struct Teacher) + MAX_STUDENTS*sizeof(struct Student) + MAX_POSTS*sizeof(struct ForumPost));

    return 0;
}
