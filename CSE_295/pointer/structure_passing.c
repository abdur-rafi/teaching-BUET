#include <stdio.h>
#include <string.h>


enum Grade {
    A = 80,
    B = 70,
    C = 60,
    D = 50,
    F = 0
};


struct CourseParticipant {
    char name[50];
    char id[10];
    int age;
    char address[100];
    char department[50];
    int mark;
    enum Grade grade;
};

struct Course{
    char courseName[50];
    char courseCode[10];
    int credits;
    struct CourseParticipant participants[120];
    int participantCount;
};

struct CourseParticipant calculateGrade(struct CourseParticipant participant){
    if (participant.mark >= A) {
        participant.grade = A;
    } else if (participant.mark >= B) {
        participant.grade = B;
    } else if (participant.mark >= C) {
        participant.grade = C;
    } else if (participant.mark >= D) {
        participant.grade = D;
    } else {
        participant.grade = F;
    }
    return participant;
}


int main(){
    struct Course course;

    course.participantCount = 10;
    // Initialize participants by dummy data
    for (int i = 0; i < course.participantCount; i++) {
        strcpy(course.participants[i].name, "Participant");
        sprintf(course.participants[i].id, "ID%02d", i + 1);
        course.participants[i].age = 20 + i;
        strcpy(course.participants[i].address, "123 Main St");
        strcpy(course.participants[i].department, "Computer Science");
        course.participants[i].mark = 50 + i * 5;
    }
    // Calculate grades for each participant
    for (int i = 0; i < course.participantCount; i++) {
        course.participants[i] = calculateGrade(course.participants[i]);
        printf("Participant ID: %s, Name: %s, Grade: %d\n",
               course.participants[i].id,
               course.participants[i].name,
               course.participants[i].grade);
   }

   return 0;
}