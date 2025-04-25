#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int id;
} Student;

void insertionSort(Student* students, int count) {
    for (int i = 1; i < count; i++) {
        Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].id > key.id) {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
    }
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    Student* students = (Student*)malloc(numStudents * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the name and ID of each student:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d Name: ", i + 1);
        scanf("%s", students[i].name);
        printf("Student %d ID: ", i + 1);
        scanf("%d", &students[i].id);
    }

    insertionSort(students, numStudents);

    printf("Students sorted by ID in ascending order:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Name: %s, ID: %d\n", students[i].name, students[i].id);
    }

    free(students);
    return 0;
}
