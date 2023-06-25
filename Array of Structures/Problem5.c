#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int marks;
} Student;

void searchStudentByName(Student students[], int numStudents, const char *name) {
    int found = 0;
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Student found:\n");
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %d\n", students[i].marks);
            printf("\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with name '%s' not found.\n", name);
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

    searchStudentByName(students, numStudents, "Bob Johnson");
    searchStudentByName(students, numStudents, "Sarah Brown");

    return 0;
}
