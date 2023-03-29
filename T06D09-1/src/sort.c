#include <math.h>
#include <stdio.h>

int input(int *a, int n);
void output(int *a, int n, int f);
void bubbleSort(int *a, int n);

int main() {
    int n = 10, data[n];
    int fl = input(data, n);
    bubbleSort(data, n);
    output(data, n, fl);
    return 0;
}

int input(int *a, int n) {
    int flag = 1;
    for (int *p = a; p - a < n; p++) {
        int test = scanf("%d", p);
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
        printf("n/a \n");
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
