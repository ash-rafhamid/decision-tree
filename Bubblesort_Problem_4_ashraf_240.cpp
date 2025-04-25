#include <stdio.h>
#include <stdlib.h>

void bubbleSortDescending(float* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    float* array = (float*)malloc(size * sizeof(float));
    printf("Enter %d floating-point numbers:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%f", &array[i]);
    }

    bubbleSortDescending(array, size);

    printf("Array sorted in descending order:\n");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}
