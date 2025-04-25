#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int id;
} Student;

void merge(Student* arr, int start, int mid, int end) {
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    Student* leftArr = (Student*)malloc(leftSize * sizeof(Student));
    Student* rightArr = (Student*)malloc(rightSize * sizeof(Student));

    for (int i = 0; i < leftSize; i++)
        leftArr[i] = arr[start + i];
    for (int j = 0; j < rightSize; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = start;
    while (i < leftSize && j < rightSize) {
        if (leftArr[i].id <= rightArr[j].id) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    free(leftArr);
    free(rightArr);
}

void mergeSort(Student* arr, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    Student* students = (Student*)malloc(numStudents * sizeof(Student));

    printf("Enter student information (Name ID):\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d Name: ", i + 1);
        scanf("%s", students[i].name);
        printf("Student %d ID: ", i + 1);
        scanf("%d", &students[i].id);
    }

    mergeSort(students, 0, numStudents - 1);

    printf("\nSorted list of students by ID:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Name: %s, ID: %d\n", students[i].name, students[i].id);
    }

    free(students);
    return 0;
}
