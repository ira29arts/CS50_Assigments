#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5
#define MAX_NAME_LENGTH 50

struct Student {
    char name[MAX_NAME_LENGTH];
    float subj1;
    float subj2;
    float subj3;
    char grade;
    float average;
};

void calculate_average_and_grade(struct Student *student) {
    student->average = (student->subj1 + student->subj2 + student->subj3) / 3.0;

    if (student->average >= 90) {
        student->grade = 'A';
    } else if (student->average >= 80) {
        student->grade = 'B';
    } else if (student->average >= 70) {
        student->grade = 'C';
    } else if (student->average >= 60) {
        student->grade = 'D';
    } else {
        student->grade = 'F';
    }
}

int main() {
    struct Student students[MAX_STUDENTS];

    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("\nEnter details for student %d:\n", i + 1);

        printf("Name: ");
        scanf(" %[^\n]s", students[i].name);

        printf("Subject 1 Mark: ");
        scanf("%f", &students[i].subj1);

        printf("Subject 2 Mark: ");
        scanf("%f", &students[i].subj2);

        printf("Subject 3 Mark: ");
        scanf("%f", &students[i].subj3);

        calculate_average_and_grade(&students[i]);
    }

    printf("\nStudent Data:\n");
    printf("--------------------------------------------------\n");
    printf("%-20s %-10s %-10s %-10s %-10s %-10s\n", "Name", "Subj 1", "Subj 2", "Subj 3", "Average", "Grade");
    printf("--------------------------------------------------\n");


    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("%-20s %-10.2f %-10.2f %-10.2f %-10.2f %-10c\n",
               students[i].name, students[i].subj1, students[i].subj2,
               students[i].subj3, students[i].average, students[i].grade);
    }
    printf("--------------------------------------------------\n");

    return 0;
}
