#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n, int f);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double squareMean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v, int f);

int main() {
    int n, data[NMAX];
    int fl = input(data, &n);
    output(data, n, fl);
    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n), fl);

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

int max(int *a, int n) {
    int max = -2147483647 - 1;
    for (int *p = a; p - a < n; p++) {
        if (*p > max) {
            max = *p;
        }
    }
    return max;
}

int min(int *a, int n) {
    int min = 2147483647;
    for (int *p = a; p - a < n; p++) {
        if (*p < min) {
            min = *p;
        }
    }
    return min;
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
double variance(int *a, int n) { return squareMean(a, n) - mean(a, n) * mean(a, n); }

void output_result(int max_v, int min_v, double mean_v, double variance_v, int f) {
    if (f == 1) {
        printf("\n%d %d %f %f", max_v, min_v, mean_v, variance_v);
    }
}
