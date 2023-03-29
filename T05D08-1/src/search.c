#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
void output(int *a, int n, int f);
int search(int *a, int n);
double mean(int *a, int n);
double squareMean(int *a, int n);
double variance(int *a, int n);

int main() {
    int n, data[NMAX];
    int fl = input(data, &n);
    output(data, n, fl);
    return 0;
}

int input(int *a, int *n) {
    int test = scanf("%d", n);
    int flag = 1;
    if (test != 1 || *n > 30 || *n < 0) {
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
        int s = search(a, n);
        printf("%d", s);
    } else {
        printf("n/a \n");
    }
}

double mean(int *a, int n) {
    double mean = 0.0;
    double pi = 1.0 / n;
    for (int *p = a; p - a < n; p++) {
        mean = mean + (*p) * pi;
    }
    return mean;
}

double squareMean(int *a, int n) {
    double sqm = 0.0;
    double pi = 1.0 / n;
    for (int *p = a; p - a < n; p++) {
        sqm = sqm + ((*p) * (*p)) * pi;
    }
    return sqm;
}

int search(int *a, int n) {
    int res = 0;
    for (int *p = a; p - a < n; p++) {
        if (*p % 2 == 0 && *p != 0 && *p >= mean(a, n) && *p <= (mean(a, n) + 3 * sqrt(variance(a, n)))) {
            res = *p;
        }
    }
    return res;
}
double variance(int *a, int n) { return squareMean(a, n) - mean(a, n) * mean(a, n); }
