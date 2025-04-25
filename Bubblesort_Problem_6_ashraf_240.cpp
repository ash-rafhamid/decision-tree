#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int id;
} Student;

void bubbleSortStudents(Student* students, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (students[j].id > students[j + 1].id) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);

    Student* students = (Student*)malloc(size * sizeof(Student));
    printf("Enter each student's Name and ID:\n");

    for (int i = 0; i < size; i++) {
        printf("Student %d Name: ", i + 1);
        scanf("%s", students[i].name);
        printf("Student %d ID: ", i + 1);
        scanf("%d", &students[i].id);
    }

    bubbleSortStudents(students, size);

    printf("Students sorted by ID in ascending order:\n");
    for (int i = 0; i < size; i++) {
        printf("Name: %s, ID: %d\n", students[i].name, students[i].id);
    }

    free(students);
    return 0;
}
