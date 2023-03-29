#include <stdio.h>

#include "stack.h"
#define N 25
#define M 80

void print();

int main() {
    struct Stack *stack = newStack(8);
    Push(stack, *"G");
    Push(stack, *"I");
    Push(stack, *"V");
    Push(stack, *"E");
    Push(stack, *" ");
    Push(stack, *"U");
    Push(stack, *"P");
    Push(stack, *"!");
    ToString(stack);
    CleanMemory(stack);
}

void print() {
    int graph[N][M];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) graph[i][j] = 46;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) printf("%c", graph[i][j]);
        printf("\n");
    }
}
