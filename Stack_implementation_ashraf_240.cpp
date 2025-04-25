#include <stdio.h>
#define MAX 1000

typedef struct {
    int top;
    int items[MAX];
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int push(Stack *s, int item) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return 0;
    }
    s->items[++(s->top)] = item;
    printf("%d pushed\n", item);
    return 1;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return 0;
    }
    return s->items[(s->top)--];
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is Empty\n");
        return 0;
    }
    return s->items[s->top];
}

int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("%d popped\n", pop(&s));
    printf("%d popped\n", pop(&s));

    printf("Element in stack: ");
    int i = s.top;
    while (i>=0) {
        printf("%d ", s.items[i]);
        i--;
    }

    return 0;
}
