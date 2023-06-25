#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    int marks;
} Student;

void swap(Student *a, Student *b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

void sortStudents(Student students[], int numStudents) {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) {
            if (students[j].marks < students[j+1].marks) {
                swap(&students[j], &students[j+1]);
            }
        }
    }
}

void displayStudents(Student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i+1);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %d\n", students[i].marks);
        printf("\n");
    }
}

int main() {
    // Example usage
    Student students[4] = {
        {1, "John Doe", 85},
        {2, "Jane Smith", 92},
        {3, "Bob Johnson", 78},
        {4, "Alice Williams", 95}
    };

    int numStudents = sizeof(students) / sizeof(students[0]);

    sortStudents(students, numStudents);

    printf("Sorted Students:\n");
    displayStudents(students, numStudents);

    return 0;
}
