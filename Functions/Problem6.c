#include <stdio.h>

// Function to convert a decimal number to BCD format
unsigned char decimalToBCD(unsigned char decimal) {
    unsigned char bcd = 0; // BCD variable to store the result

    // Extracting the tens and ones digits from the decimal number
    unsigned char tens = decimal / 10;
    unsigned char ones = decimal % 10;

    // Converting the tens digit to BCD and shifting it to the left
    bcd = (tens << 4);

    // Combining the ones digit with the BCD representation
    bcd |= ones;

    return bcd;
}

int main() {
    unsigned char decimal = 25; // Example decimal number

    printf("Decimal number: %u\n", decimal);

    // Convert decimal to BCD
    unsigned char bcd = decimalToBCD(decimal);
    printf("BCD representation: 0x%X\n", bcd);

    return 0;
}
