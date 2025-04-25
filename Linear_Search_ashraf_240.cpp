#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int size, target;
    
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    
    int arr[size];
    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the target value to search: ");
    scanf("%d", &target);
    
    int result = linearSearch(arr, size, target);
    
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }
    
    return 0;
}
