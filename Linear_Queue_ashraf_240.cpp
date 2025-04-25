#include <stdio.h>
#define MAX 100

typedef struct {
    int items[MAX];
    int front;
    int rear;
} LinearQueue;

void initQueue(LinearQueue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(LinearQueue* q) {
    return q->front == -1;
}

int isFull(LinearQueue* q) {
    return q->rear == MAX - 1;
}

void enqueue(LinearQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->items[++(q->rear)] = value;
    printf("%d enqueued\n",value);
}

int dequeue(LinearQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

void displayQueue(LinearQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    
    printf("Elements in queue : ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    LinearQueue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    
    printf("%d dequeued\n", dequeue(&q));
    displayQueue(&q);
    
    return 0;
}
