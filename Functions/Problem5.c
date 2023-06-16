#include <stdio.h>

// Function to set a bit at a given position
unsigned char setBit(unsigned char num, int pos) {
    return num | (1 << pos);
}

// Function to clear a bit at a given position
unsigned char clearBit(unsigned char num, int pos) {
    return num & ~(1 << pos);
}

// Function to toggle a bit at a given position
unsigned char toggleBit(unsigned char num, int pos) {
    return num ^ (1 << pos);
}

int main() {
    unsigned char num = 0b01010101; // Example 8-bit number

    printf("Original number: 0x%X\n", num);

    // Set bit at position 2
    num = setBit(num, 2);
    printf("After setting bit at position 2: 0x%X\n", num);

    // Clear bit at position 5
    num = clearBit(num, 5);
    printf("After clearing bit at position 5: 0x%X\n", num);

    // Toggle bit at position 7
    num = toggleBit(num, 7);
    printf("After toggling bit at position 7: 0x%X\n", num);

    return 0;
}
