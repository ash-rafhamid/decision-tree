#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int* numbers = (int*)malloc(size * sizeof(int));

    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &numbers[i]);
    }

    int evenCount = 0, oddCount = 0;

    for (int i = 0; i < size; i++) {
        if (numbers[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    if (evenCount >= 2) {
        for (int i = size - 1; i >= 0; i--) {
            if (numbers[i] % 2 == 0) {
                for (int j = i; j < size - 1; j++) {
                    numbers[j] = numbers[j + 1];
                }
                for (int j = size - 1; j > i; j--) {
                    numbers[j] = numbers[j - 1];
                }
                size -= 2;
                break;
            }
        }
    } else if (evenCount == 1) {
        int newElement1, newElement2;
        printf("Enter two elements to insert in the middle:\n");
        scanf("%d %d", &newElement1, &newElement2);
        int middleIndex = size / 2;
        numbers = (int*)realloc(numbers, (size + 2) * sizeof(int));
        for (int i = size; i > middleIndex; i--) {
            numbers[i] = numbers[i - 1];
        }
        numbers[middleIndex] = newElement1;
        numbers[middleIndex + 1] = newElement2;
        size += 2;
    } else {
        int middleIndex = size / 2;
        int newElement;
        printf("No even elements found. Enter a new element to insert next to the middle:\n");
        scanf("%d", &newElement);
        numbers = (int*)realloc(numbers, (size + 1) * sizeof(int));
        for (int i = size; i > middleIndex + 1; i--) {
            numbers[i] = numbers[i - 1];
        }
        numbers[middleIndex + 1] = newElement;
        size++;
    }

    printf("Updated array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    free(numbers);
    return 0;
}
