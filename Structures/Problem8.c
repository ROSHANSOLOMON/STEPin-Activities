#include <stdio.h>

#define MAX_STUDENTS 100

struct Student {
    char name[50];
    float marks;
};

void readStudents(struct Student students[], int n) {
    printf("Enter student details:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]s", students[i].name);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }
}

void writeStudents(struct Student students[], int n) {
    printf("\nStudent details:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }
}

float calculateAverageMarks(struct Student students[], int n) {
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += students[i].marks;
    }
    return sum / n;
}

void printStudentsAboveAverage(struct Student students[], int n, float average) {
    printf("\nStudents scoring above average marks:\n");
    for (int i = 0; i < n; i++) {
        if (students[i].marks > average) {
            printf("Student %d:\n", i + 1);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
        }
    }
}

void printStudentsBelowAverage(struct Student students[], int n, float average) {
    printf("\nStudents scoring below average marks:\n");
    for (int i = 0; i < n; i++) {
        if (students[i].marks < average) {
            printf("Student %d:\n", i + 1);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    if (n > MAX_STUDENTS) {
        printf("Maximum number of students exceeded.\n");
        return 1;
    }

    struct Student students[MAX_STUDENTS];

    readStudents(students, n);
    writeStudents(students, n);

    float average = calculateAverageMarks(students, n);
    printf("\nAverage marks: %.2f\n", average);

    printStudentsAboveAverage(students, n, average);
    printStudentsBelowAverage(students, n, average);

    return 0;
}
