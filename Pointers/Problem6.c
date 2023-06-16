#include <stdio.h>

int compareBoxes(int boxA[], int boxB[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        int currentItemA = boxA[i];
        int currentItemB = boxB[i];
        int foundMatch = 0;

        for (int j = 0; j < size; j++) {
            if (currentItemA == boxB[j]) {
                foundMatch = 1;
                break;
            }
        }

        if (foundMatch) {
            count++;
        }
    }

    return (count == size) ? 1 : 0;
}

int main() {
    int boxA[] = {200, 10, -90};
    int boxB[] = {-90, 200, 10};
    int size = sizeof(boxA) / sizeof(boxA[0]);

    int result = compareBoxes(boxA, boxB, size);
    printf("Result: %d\n", result);

    return 0;
}
