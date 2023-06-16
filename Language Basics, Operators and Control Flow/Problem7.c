#include <stdio.h>

char getGrade(int marks) {
    char grade;

    switch (marks) {
        case 90 ... 100:
            grade = 'A';
            break;
        case 75 ... 89:
            grade = 'B';
            break;
        case 60 ... 74:
            grade = 'C';
            break;
        case 50 ... 59:
            grade = 'D';
            break;
        case 36 ... 49:
            grade = 'E';
            break;
        case 0 ... 35:
            grade = 'F';
            break;
        default:
            grade = 'X'; // Invalid marks
            break;
    }

    return grade;
}

int main() {
    int marks;
    printf("Enter the student's marks: ");
    scanf("%d", &marks);

    char grade = getGrade(marks);

    switch (grade) {
        case 'A':
            printf("Grade A\n");
            break;
        case 'B':
            printf("Grade B\n");
            break;
        case 'C':
            printf("Grade C\n");
            break;
        case 'D':
            printf("Grade D\n");
            break;
        case 'E':
            printf("Grade E\n");
            break;
        case 'F':
            printf("Grade F\n");
            break;
        default:
            printf("Invalid marks entered.\n");
            break;
    }

    return 0;
}
