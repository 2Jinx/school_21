#ifndef STACK_H
#define STACK_H

struct Stack {
    int maxsize;
    int top;
    char *items;
};

struct Stack *newStack(int size);
int IsEmpty(struct Stack *nstack);
int IsFull(struct Stack *nstack);
void Push(struct Stack *nstack, char item);
int Pop(struct Stack *nstack);
void CleanMemory(struct Stack *nstack);
void ToString(struct Stack *nstack);

#endif
