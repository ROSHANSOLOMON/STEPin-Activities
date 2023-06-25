#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void copyFileToUpper(FILE* source, FILE* destination) {
    int ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(toupper(ch), destination);
    }
}

void copyFileToLower(FILE* source, FILE* destination) {
    int ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(tolower(ch), destination);
    }
}

void copyFileToPurelyUpper(FILE* source, FILE* destination) {
    int ch;
    while ((ch = fgetc(source)) != EOF) {
        if (isalpha(ch)) {
            fputc(toupper(ch), destination);
        } else {
            fputc(ch, destination);
        }
    }
}

void copyFile(FILE* source, FILE* destination) {
    int ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: ./cp [option] source_file destination_file\n");
        return 1;
    }

    char* option = argv[1];
    FILE* source = fopen(argv[2], "r");
    FILE* destination = fopen(argv[3], "w");

    if (source == NULL) {
        printf("Error opening the source file.\n");
        return 1;
    }

    if (destination == NULL) {
        printf("Error creating the destination file.\n");
        return 1;
    }

    if (strcmp(option, "-s") == 0) {
        copyFileToPurelyUpper(source, destination);
    } else if (strcmp(option, "-l") == 0) {
        copyFileToLower(source, destination);
    } else if (strcmp(option, "-u") == 0) {
        copyFileToUpper(source, destination);
    } else {
        copyFile(source, destination);
    }

    printf("File copied successfully.\n");

    fclose(source);
    fclose(destination);

    return 0;
}
