#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseString(char* input, struct Student* students, int size) {
    int i = 0;
    char temp[20];
    char* token = strtok(input, " ");

    while (token != NULL && i < size) {
        students[i].rollno = atoi(token);

        token = strtok(NULL, " ");
        strncpy(students[i].name, token, sizeof(students[i].name) - 1);
        students[i].name[sizeof(students[i].name) - 1] = '\0';

        token = strtok(NULL, " ");
        students[i].marks = atof(token);

        token = strtok(NULL, " ");
        i++;
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    getchar();  // Consume newline character

    struct Student* students = (struct Student*)malloc(size * sizeof(struct Student));

    char input[100];
    printf("Enter the student details (rollno name marks):\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove trailing newline character

    parseString(input, students, size);

    // Display the initialized array of structures
    for (int i = 0; i < size; ++i) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    free(students);

    return 0;
}
