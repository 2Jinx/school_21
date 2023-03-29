#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int input(int *a, int n);
void output(int *a, int n, int f);
void bubbleSort(int *a, int n);
int dynamic_memory(int *n);

int main() {
    int *data;
    int n;
    int flag = dynamic_memory(&n);
    if (flag == 1) {
        data = (int *)malloc(n * sizeof(int));
        free(data);
        int fl = input(data, n);
        bubbleSort(data, n);
        output(data, n, fl);
    } else {
        printf("n/a");
    }
    return 0;
}

int dynamic_memory(int *n) {
    int test = scanf("%d", n);
    int flag = 1;
    if (test != 1) {
        flag = 0;
    }
    return flag;
}
int input(int *a, int n) {
    int flag = 1;
    for (int i = 0; i < n; i++) {
        int test = scanf("%d", &a[i]);
        if (test != 1) {
            flag = 0;
            break;
        }
    }
    return flag;
}

void output(int *a, int n, int f) {
    if (f == 1) {
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
    } else {
        printf("n/a");
    }
}

void bubbleSort(int *a, int n) {
    int fl = 1;  // flag
    while (fl == 1) {
        fl = 0;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                int t = a[i];
                a[i] = a[i + 1];
                a[i + 1] = t;
                fl = 1;
            }
        }
    }
}
