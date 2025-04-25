#include <stdio.h>
#include <stdlib.h>

// Function to merge two halves in descending order using a custom comparison function
void merge(float arr[], int left, int mid, int right, int (*compare)(float, float)) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    float* L = (float*)malloc(n1 * sizeof(float));
    float* R = (float*)malloc(n2 * sizeof(float));
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (compare(L[i], R[j]) >= 0) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

int compare_descending(float a, float b) {
    return a - b;
}

void mergeSort(float arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right, compare_descending); 
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    float* arr = (float*)malloc(n * sizeof(float));
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }
    mergeSort(arr, 0, n - 1);
    printf("Sorted array in descending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
} 