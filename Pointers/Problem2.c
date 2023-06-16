#include <stdio.h>

void swap(void *a, void *b, size_t size) {
    char *temp = malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

int main() {
    int num1 = 10, num2 = 20;
    printf("Before swap: num1 = %d, num2 = %d\n", num1, num2);
    swap(&num1, &num2, sizeof(int));
    printf("After swap: num1 = %d, num2 = %d\n", num1, num2);

    float f1 = 3.14, f2 = 2.718;
    printf("Before swap: f1 = %f, f2 = %f\n", f1, f2);
    swap(&f1, &f2, sizeof(float));
    printf("After swap: f1 = %f, f2 = %f\n", f1, f2);

    char c1 = 'A', c2 = 'B';
    printf("Before swap: c1 = %c, c2 = %c\n", c1, c2);
    swap(&c1, &c2, sizeof(char));
    printf("After swap: c1 = %c, c2 = %c\n", c1, c2);

    return 0;
}
