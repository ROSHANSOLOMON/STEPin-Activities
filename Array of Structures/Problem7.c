#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int marks;
} Student;

Student* deleteStudent(Student* students, int* numStudents) {
    if (*numStudents == 0) {
        printf("No students to delete.\n");
        return students;
    }

    // Shift the array to the left by one position
    for (int i = 0; i < (*numStudents) - 1; i++) {
        students[i] = students[i+1];
    }

    // Decrease the size of the array
    *numStudents -= 1;
    students = realloc(students, sizeof(Student) * (*numStudents));

    return students;
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
    
    // Delete a student
    students = deleteStudent(students, &numStudents);
    
    printf("Updated Students:\n");
    displayStudents(students, numStudents);

    // Cleanup memory
    free(students);

    return 0;
}
