#include <stdio.h>

struct Complex {
    double real;
    double imaginary;
};

struct Complex readComplex() {
    struct Complex num;
    printf("Enter the real part: ");
    scanf("%lf", &num.real);
    printf("Enter the imaginary part: ");
    scanf("%lf", &num.imaginary);
    return num;
}

void writeComplex(struct Complex num) {
    printf("Complex number: %.2lf + %.2lfi\n", num.real, num.imaginary);
}

struct Complex addComplex(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = num1.real + num2.real;
    result.imaginary = num1.imaginary + num2.imaginary;
    return result;
}

struct Complex multiplyComplex(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = (num1.real * num2.real) - (num1.imaginary * num2.imaginary);
    result.imaginary = (num1.real * num2.imaginary) + (num1.imaginary * num2.real);
    return result;
}

int main() {
    struct Complex num1, num2, sum, product;

    // Read the complex numbers
    printf("Enter the first complex number:\n");
    num1 = readComplex();
    printf("Enter the second complex number:\n");
    num2 = readComplex();

    // Write the complex numbers
    printf("\nFirst complex number:\n");
    writeComplex(num1);
    printf("Second complex number:\n");
    writeComplex(num2);

    // Add the complex numbers
    sum = addComplex(num1, num2);
    printf("\nSum of the complex numbers:\n");
    writeComplex(sum);

    // Multiply the complex numbers
    product = multiplyComplex(num1, num2);
    printf("Product of the complex numbers:\n");
    writeComplex(product);

    return 0;
}
