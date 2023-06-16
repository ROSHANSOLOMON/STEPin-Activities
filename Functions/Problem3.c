#include <stdio.h>

int findLargestNumber(int num) {
    int maxNum = 0;

    // Convert the number to a string for easier manipulation
    char numStr[5];
    sprintf(numStr, "%d", num);

    for (int i = 0; i < 4; i++) {
        // Remove the current digit by shifting the remaining digits
        int tempNum = 0;
        for (int j = 0; j < 4; j++) {
            if (j != i) {
                tempNum = tempNum * 10 + (numStr[j] - '0');
            }
        }

        // Update the maximum number if the current number is larger
        if (tempNum > maxNum) {
            maxNum = tempNum;
        }
    }

    return maxNum;
}

int main() {
    int num;
    printf("Enter a 4-digit number: ");
    scanf("%d", &num);

    int largestNum = findLargestNumber(num);
    printf("Largest number by deleting a single digit: %d\n", largestNum);

    return 0;
}
