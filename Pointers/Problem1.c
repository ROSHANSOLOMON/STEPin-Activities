#include <stdio.h>

void printExponent(double num) {
    unsigned long long *ptr = (unsigned long long *)&num;
    unsigned long long exponent = (*ptr & 0x7FF0000000000000) >> 52;
    
    printf("Exponent in hexadecimal: 0x%llx\n", exponent);
    
    printf("Exponent in binary: 0b");
    for (int i = 11; i >= 0; i--) {
        printf("%llu", (exponent >> i) & 1);
    }
    printf("\n");
}

int main() {
    double x = 0.7;
    printExponent(x);

    return 0;
}
