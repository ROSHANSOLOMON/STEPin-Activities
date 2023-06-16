#include <stdio.h>
#include <ctype.h>

int findCharType(char ch) {
    if (isalpha(ch)) {
        if (isupper(ch)) {
            return 1; // Uppercase letter (A-Z)
        } else {
            return 2; // Lowercase letter (a-z)
        }
    } else if (isdigit(ch)) {
        return 3; // Digit (0-9)
    } else if (isprint(ch)) {
        return 4; // Printable symbol
    } else {
        return 5; // Non-printable symbol
    }
}

int main() {
    char ch;
    printf("Enter a character: ");
    scanf(" %c", &ch);

    int result = findCharType(ch);

    switch (result) {
        case 1:
            printf("Type: Uppercase letter (A-Z)\n");
            break;
        case 2:
            printf("Type: Lowercase letter (a-z)\n");
            break;
        case 3:
            printf("Type: Digit (0-9)\n");
            break;
        case 4:
            printf("Type: Printable symbol\n");
            break;
        case 5:
            printf("Type: Non-printable symbol\n");
            break;
        default:
            printf("Invalid character\n");
            break;
    }

    return 0;
}
