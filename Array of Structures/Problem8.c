#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int marks;
} Student;

void swapStudents(Student* students, int index1, int index2) {
    Student temp = students[index1];
    students[index1] = students[index2];
    students[index2] = temp;
}

void displayStudents(Student* students, int numStudents) {
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
    int numStudents = 3;
    Student* students = malloc(sizeof(Student) * numStudents);
    
    students[0].id = 1;
    strncpy(students[0].name, "John Doe", sizeof(students[0].name));
    students[0].marks = 85;
    
    students[1].id = 2;
    strncpy(students[1].name, "Jane Smith", sizeof(students[1].name));
    students[1].marks = 92;
    
    students[2].id = 3;
    strncpy(students[2].name, "Bob Johnson", sizeof(students[2].name));
    students[2].marks = 78;

    printf("Initial Students:\n");
    displayStudents(students, numStudents);

    int index1, index2;
    printf("Enter the indexes of the students to swap (separated by a space): ");
    scanf("%d %d", &index1, &index2);

    if (index1 >= 0 && index1 < numStudents && index2 >= 0 && index2 < numStudents) {
        swapStudents(students, index1, index2);
        printf("\nSwapping students at indexes %d and %d:\n", index1, index2);
        displayStudents(students, numStudents);
    } else {
        printf("\nInvalid indexes entered.\n");
    }

    // Cleanup memory
    free(students);

    return 0;
}
