#include <stdio.h>

int findMaxIfElse(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int findMaxTernary(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int num1, num2;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    int maxIfElse = findMaxIfElse(num1, num2);
    int maxTernary = findMaxTernary(num1, num2);

    printf("Using if-else: %d\n", maxIfElse);
    printf("Using ternary operator: %d\n", maxTernary);

    return 0;
}
