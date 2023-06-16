#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encodeString(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        str[i] += 5;  // Perform character substitution by adding 5 to each character
    }
}

void decodeString(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        str[i] -= 5;  // Reverse the character substitution by subtracting 5 from each character
    }
}

int main() {
    char originalString[] = "Hello, World!";
    char encodedString[100];

    // Encode the original string
    strcpy(encodedString, originalString);
    encodeString(encodedString);

    printf("Encoded String: %s\n", encodedString);

    // Decode the encoded string
    decodeString(encodedString);

    printf("Decoded String: %s\n", encodedString);

    return 0;
}
