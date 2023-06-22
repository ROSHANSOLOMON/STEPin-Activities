#include <stdio.h>

struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

void swapFields(struct Student* s1, struct Student* s2) {
    struct Student temp;

    // Swap name
    strcpy(temp.name, s1->name);
    strcpy(s1->name, s2->name);
    strcpy(s2->name, temp.name);

    // Swap roll number
    int rollNumberTemp = s1->rollNumber;
    s1->rollNumber = s2->rollNumber;
    s2->rollNumber = rollNumberTemp;

    // Swap marks
    float marksTemp = s1->marks;
    s1->marks = s2->marks;
    s2->marks = marksTemp;
}

int main() {
    struct Student student1 = { "John", 101, 85.5 };
    struct Student student2 = { "Alice", 102, 90.0 };

    printf("Before swapping:\n");
    printf("Student 1: Name - %s, Roll Number - %d, Marks - %.2f\n", student1.name, student1.rollNumber, student1.marks);
    printf("Student 2: Name - %s, Roll Number - %d, Marks - %.2f\n", student2.name, student2.rollNumber, student2.marks);

    swapFields(&student1, &student2);

    printf("\nAfter swapping:\n");
    printf("Student 1: Name - %s, Roll Number - %d, Marks - %.2f\n", student1.name, student1.rollNumber, student1.marks);
    printf("Student 2: Name - %s, Roll Number - %d, Marks - %.2f\n", student2.name, student2.rollNumber, student2.marks);

    return 0;
}
