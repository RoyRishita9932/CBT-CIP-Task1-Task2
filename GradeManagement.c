#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 100
#define MAX_SUBJECTS 10

// Structure to hold a student's information
struct Student {
    char name[50];
    float scores[MAX_SUBJECTS];
    int numSubjects;
    float average;
    float highestScore;
    float lowestScore;
};
void calculatePerformance(struct Student* student) {
    float sum = 0;
    float highest = student->scores[0];
    float lowest = student->scores[0];
    for (int i = 0; i < student->numSubjects; i++) {
        sum += student->scores[i];
        if (student->scores[i] > highest) {
            highest = student->scores[i];
        }
        if (student->scores[i] < lowest) {
            lowest = student->scores[i];
        }
    }

    student->average = sum / student->numSubjects;
    student->highestScore = highest;
    student->lowestScore = lowest;
}
void displaySummary(struct Student student) {
    printf("\nStudent Name: %s\n", student.name);
    printf("Average Score: %.2f\n", student.average);
    printf("Highest Score: %.2f\n", student.highestScore);
    printf("Lowest Score: %.2f\n", student.lowestScore);
    printf("Scores in each subject:\n");
    for (int i = 0; i < student.numSubjects; i++) {
        printf(" Subject %d: %.2f\n", i + 1, student.scores[i]);
    }
    printf("\n");
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents, numSubjects;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    for (int i = 0; i < numStudents; i++) {
        printf("\nEnter the name of student %d: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter the number of subjects for %s: ", students[i].name);
        scanf("%d", &students[i].numSubjects);
        for (int j = 0; j < students[i].numSubjects; j++) {
            printf("Enter the score for subject %d: ", j + 1);
            scanf("%f", &students[i].scores[j]);
        }

        calculatePerformance(&students[i]);
    }
    for (int i = 0; i < numStudents; i++) {
        displaySummary(students[i]);
    }

    return 0;
}
