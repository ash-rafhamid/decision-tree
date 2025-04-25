#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* creatNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** headRef, int newData) {
    struct Node* newNode = creatNode(newData);
    newNode->next = *headRef;
    *headRef = newNode;
}

void insertAtEnd(struct Node** headRef, int newData) {
    struct Node* newNode = creatNode(newData);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* last = *headRef;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

void deleteAtBeginning(struct Node** headRef) {
    if (*headRef == NULL) {
        printf("List is already empty.\n");
        return;
    }
    struct Node* temp = *headRef;
    *headRef = (*headRef)->next;
    free(temp);
}

void deleteAtEnd(struct Node** headRef) {
    if (*headRef == NULL) {
        printf("List is already empty.\n");
        return;
    }
    struct Node* temp = *headRef;
    struct Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev != NULL)
        prev->next = NULL;
    else
        *headRef = NULL;
    free(temp);
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 5);
    printf("List after inserting 5 and 10 at the beginning:\n");
    printList(head);

    insertAtEnd(&head, 15);
    insertAtEnd(&head, 20);
    printf("List after inserting 15 and 20 at the end:\n");
    printList(head);

    deleteAtBeginning(&head);
    printf("List after deleting the first node:\n");
    printList(head);

    deleteAtEnd(&head);
    printf("List after deleting the last node:\n");
    printList(head);

    return 0;
}
