#include <stdio.h>
#include <string.h>

int main() {
    int size;
    printf("Enter number of students data you want to insert = ");
    scanf("%d", &size);
    int AA[size];
    char name[size][30];

    // Input student data
    for (int i = 0; i < size; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", name[i]);
        printf("Enter ID of student %d: ", i + 1);
        scanf("%d", &AA[i]);
    }

    // Selection sort
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (AA[j] < AA[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        if (min_idx != i) {
            int temp = AA[i];
            AA[i] = AA[min_idx];
            AA[min_idx] = temp;

            char temp_name[30];
            strcpy(temp_name, name[i]);
            strcpy(name[i], name[min_idx]);
            strcpy(name[min_idx], temp_name);
        }
    }

    printf("\nSorted values : \n\n");
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Name: %s\n", AA[i], name[i]);
    }

    return 0;
}