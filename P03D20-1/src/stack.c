#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

struct Stack *newStack(int size) {
    struct Stack *nstack = (struct Stack *)malloc(sizeof(struct Stack *));
    nstack->maxsize = size;
    nstack->top = -1;
    nstack->items = (char *)malloc(size * sizeof(char));

    return nstack;
}

int IsEmpty(struct Stack *nstack) { return nstack->top == -1; }

int IsFull(struct Stack *nstack) { return nstack->top + 1 == nstack->maxsize; }

void Push(struct Stack *nstack, char item) {
    if (!IsFull(nstack)) {
        nstack->items[++nstack->top] = item;
    } else {
        //        nstack->items = (char*)realloc((size + 1) * sizeof(char));
        //        nstack->items[top++] = item;
        printf("Stack overflow!!");
    }
}

int Pop(struct Stack *nstack) {
    if (!IsEmpty(nstack)) {
        return nstack->items[nstack->top--];
    } else {
        printf("Stack is empty!!");
    }
    return 0;
}

void CleanMemory(struct Stack *nstack) {
    free(nstack->items);
    free(nstack);
}
void ToString(struct Stack *nstack) {
    for (int i = 0; i < nstack->top + 1; i++) {
        printf("%c", nstack->items[i]);
    }
}
