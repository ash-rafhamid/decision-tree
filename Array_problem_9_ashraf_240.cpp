#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, position;

    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int* arr = (int*)malloc(size * sizeof(int));

    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter an odd index position to delete the element: ");
    scanf("%d", &position);

    while (position % 2 == 0 || position >= size) {
        printf("Invalid index position! Please enter an odd index.\n");
        printf("Enter an odd index position to delete the element: ");
        scanf("%d", &position);
    }

    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;

    printf("Updated array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
