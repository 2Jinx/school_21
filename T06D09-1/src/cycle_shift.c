#include <math.h>
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n, int *c);
void output(int *a, int n, int f);
void shift(int *a, int n, int count);
void shift_left(int *a, int n);

int main() {
    int n, count, data[NMAX];
    int fl = input(data, &n, &count);
    shift(data, n, count);
    output(data, n, fl);
    return 0;
}

int input(int *a, int *n, int *c) {
    int test = scanf("%d", n);
    int flag = 1;
    if (test != 1 || *n > 10 || *n < 0) {
        flag = 0;
    }
    for (int *p = a; p - a < *n; p++) {
        int test = scanf("%d", p);
        if (test != 1) {
            flag = 0;
            break;
        }
    }
    char k = 0;
    if ((k = getchar()) != 10) {
        flag = 0;
    }
    int t = scanf("%d", c);
    if (t != 1) {
        flag = 0;
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
void shift_left(int *a, int n) {
    if (0 == n) return;
    int first = a[0];

    for (int i = 1; i < n; ++i) a[i - 1] = a[i];

    a[n - 1] = first;
}

void shift(int *a, int n, int count) {
    if (count > 0) {
        for (int i = 0; i < count; ++i) {
            shift_left(a, n);
        }
    } else {
        count = -count;
        count = count % n;
        count = n - count;

        for (int i = 0; i < count; ++i) {
            shift_left(a, n);
        }
    }
}
