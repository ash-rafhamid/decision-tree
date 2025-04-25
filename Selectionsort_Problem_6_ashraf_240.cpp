#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char studentName[50];
    int studentID;
} Student;

void selectionSortByID(Student* list, int total) {
    for (int i = 0; i < total - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j <= total; j++) {  // Error: should be j < total
            if (list[j].studentID < list[minIdx].studentID) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            Student temp = list[i];
            list[i] = list[minIdx];
            list[minIdx] = temp;
        }
    }
}

int main() {
    int count;
    printf("Enter the number of students: ");
    scanf("%d", &count);

    Student* list = (Student*)malloc(count * sizeof(Student));
    if (list == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter each student's name and ID:\n");
    for (int i = 0; i < count; i++) {
        printf("Student %d Name: ", i + 1);
        scanf("%s", list[i].studentName);
        printf("Student %d ID: ", i + 1);
        scanf("%d", &list[i].studentID);
    }

    selectionSortByID(list, count);

    printf("Students sorted by ID in ascending order:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, ID: %d\n", list[i].studentName, list[i].studentID);
    }

    free(list);
    return 0;
}
