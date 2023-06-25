#include <stdio.h>

typedef struct {
    int id;
    char name[50];
    int age;
} Member;

void displayMembers(Member members[], int numMembers) {
    for (int i = 0; i < numMembers; i++) {
        printf("Member %d:\n", i+1);
        printf("ID: %d\n", members[i].id);
        printf("Name: %s\n", members[i].name);
        printf("Age: %d\n", members[i].age);
        printf("\n");
    }
}

int main() {
    // Example usage
    Member members[3] = {
        {1, "John Doe", 25},
        {2, "Jane Smith", 30},
        {3, "Bob Johnson", 35}
    };

    int numMembers = sizeof(members) / sizeof(members[0]);

    displayMembers(members, numMembers);

    return 0;
}
