#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int marks;
} Student;

void rotateStudents(Student* students, int numStudents, int k) {
    k = k % numStudents; // Normalize k to handle larger values
    if (k < 0) {
        k = numStudents + k; // Convert negative k to positive value
    }

    Student* temp = malloc(sizeof(Student) * k);

    // Copy the last k elements to a temporary array
    for (int i = 0; i < k; i++) {
        temp[i] = students[numStudents - k + i];
    }

    // Shift the remaining elements to the right by k positions
    for (int i = numStudents - 1; i >= k; i--) {
        students[i] = students[i - k];
    }

    // Copy the temporary array to the beginning of the array
    for (int i = 0; i < k; i++) {
        students[i] = temp[i];
    }

    free(temp);
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
    int numStudents = 4;
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
    
    students[3].id = 4;
    strncpy(students[3].name, "Alice Williams", sizeof(students[3].name));
    students[3].marks = 95;

    printf("Initial Students:\n");
    displayStudents(students, numStudents);

    int k;
    printf("Enter the number of positions to rotate: ");
    scanf("%d", &k);

    rotateStudents(students, numStudents, k);

    printf("\nRotated Students:\n");
    displayStudents(students, numStudents);

    // Cleanup memory
    free(students);

    return 0;
}
