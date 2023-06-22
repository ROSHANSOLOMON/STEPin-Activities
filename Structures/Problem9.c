#include <stdio.h>
#include <stdlib.h>

struct Rectangle {
    int length;
    int width;
};

struct Rectangle* modifyRectangle(struct Rectangle* rect) {
    rect->length += 1;
    rect->width += 1;

    return rect;
}

int main() {
    struct Rectangle* rect = (struct Rectangle*)malloc(sizeof(struct Rectangle));

    // Input rectangle dimensions
    printf("Enter length: ");
    scanf("%d", &(rect->length));
    printf("Enter width: ");
    scanf("%d", &(rect->width));

    // Print original rectangle dimensions
    printf("\nOriginal Rectangle:\n");
    printf("Length: %d\n", rect->length);
    printf("Width: %d\n", rect->width);

    // Modify rectangle dimensions using function
    struct Rectangle* modifiedRect = modifyRectangle(rect);

    // Print modified rectangle dimensions
    printf("\nModified Rectangle:\n");
    printf("Length: %d\n", modifiedRect->length);
    printf("Width: %d\n", modifiedRect->width);

    free(rect);

    return 0;
}
