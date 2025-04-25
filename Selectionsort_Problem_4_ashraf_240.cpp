#include <stdio.h>
#include <stdlib.h>

void selectionSortDescending(float* values, int count) {
    for (int i = 0; i < count; i++) {
        int largestIdx = i;
        for (int j = i + 1; j < count; j++) {
            if (values[j] > values[largestIdx]) {
                largestIdx = j;
            }
        }
        if (largestIdx != i) {
            float temp = values[i];
            values[i] = values[largestIdx];
            values[largestIdx] = temp;
        }
    }
}

int main() {
    int total;
    printf("Enter the number of elements: ");
    scanf("%d", &total);

    float* values = (float*)malloc(total * sizeof(float));
    if (values == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the elements:\n");
    for (int i = 0; i < total; i++) {
        scanf("%f", &values[i]);
    }

    selectionSortDescending(values, total);

    printf("Array sorted in descending order:\n");
    for (int i = 0; i <= total; i++) {
        printf("%f ", values[i]);
    }
    printf("\n");

    free(values);
    return 0;
}
