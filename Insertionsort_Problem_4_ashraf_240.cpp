#include <stdio.h>
#include <stdlib.h>

void insertionSortDescending(float* array, int size) {
    for (int i = 1; i < size; i++) {
        float key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] < key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

int main() {
    int length;
    printf("Enter the number of elements: ");
    scanf("%d", &length);

    float* array = (float*)malloc(length * sizeof(float));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the elements:\n");
    for (int i = 0; i < length; i++) {
        scanf("%f", &array[i]);
    }

    insertionSortDescending(array, length);

    printf("Array sorted in descending order:\n");
    for (int i = 0; i < length; i++) {
        printf("%f ", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}
