#include <stdio.h>
#include <string.h>

void bubbleSort(char *names[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                char *temp = names[j];
                names[j] = names[j + 1];
                names[j + 1] = temp;
            }
        }
    }
}

int main() {
    char *names[] = {
        "Santosh", "Amol", "Santosh Jain", "Kishore", "Rahul", "Amolkumar", "Hemant"
    };
    int size = sizeof(names) / sizeof(names[0]);

    printf("Before sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", names[i]);
    }
    printf("\n");

    bubbleSort(names, size);

    printf("After sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", names[i]);
    }
    printf("\n");

    return 0;
}
