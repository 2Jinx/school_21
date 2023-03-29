#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n, int f);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    int fl = input(data, &n);
    squaring(data, n);
    output(data, n, fl);
    return 0;
}

int input(int *a, int *n) {
    int test = scanf("%d", n);
    int flag = 1;
    if (test != 1 || *n > 10 || *n < 0) {
        flag = 0;
    } else {
        for (int *p = a; p - a < *n; p++) {
            int test = scanf("%d", p);
            if (test != 1) {
                flag = 0;
                break;
            }
        }
    }
    return flag;
}

void output(int *a, int n, int f) {
    if (f == 1) {
        for (int *p = a; p - a < n; p++) {
            printf("%d ", *p);
        }
    } else {
        printf("n/a \n");
    }
}

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        *p *= (*p);
    }
}
