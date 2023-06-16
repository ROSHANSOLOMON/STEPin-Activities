#include <stdio.h>

int main() {
    int rollNo;
    char name[50];
    float physicsMarks, mathMarks, chemistryMarks;
    float totalMarks, percentage;

    // Read roll number
    printf("Enter the roll number: ");
    scanf("%d", &rollNo);

    // Read name
    printf("Enter the name: ");
    scanf(" %[^\n]s", name);

    // Read marks of Physics, Math, and Chemistry
    printf("Enter the marks of Physics: ");
    scanf("%f", &physicsMarks);

    printf("Enter the marks of Math: ");
    scanf("%f", &mathMarks);

    printf("Enter the marks of Chemistry: ");
    scanf("%f", &chemistryMarks);

    // Calculate total marks and percentage
    totalMarks = physicsMarks + mathMarks + chemistryMarks;
    percentage = (totalMarks / 300) * 100;

    // Print the summary
    printf("\nSummary:\n");
    printf("Roll No: %d\n", rollNo);
    printf("Name: %s\n", name);
    printf("Physics Marks: %.2f\n", physicsMarks);
    printf("Math Marks: %.2f\n", mathMarks);
    printf("Chemistry Marks: %.2f\n", chemistryMarks);
    printf("Total Marks: %.2f\n", totalMarks);
    printf("Percentage: %.2f%%\n", percentage);

    return 0;
}
