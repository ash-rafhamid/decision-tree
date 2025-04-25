#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, newElement, position;

    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int* arr = (int*)malloc(size * sizeof(int));

    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to insert: ");
    scanf("%d", &newElement);

    while (position <= 0 || position >= size || position % 2 != 0) {
        printf("Enter an even index position (excluding 0) to insert the element: ");
        scanf("%d", &position);
        if (position <= 0 || position >= size || position % 2 != 0) {
            printf("Invalid index position! Please try again.\n");
        }
    }

    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = newElement;
    size++;

    printf("Updated array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
