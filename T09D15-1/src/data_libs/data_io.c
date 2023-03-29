#include "data_io.h"

#include <stdio.h>
int input(double *data, int n) {
    int flag = 1;
    for (int i = 0; i < n; i++) {
        int test = scanf("%lf", &data[i]);
        if (test == 0) {
            flag = 0;
            break;
        }
    }
    return flag;
}

void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%.2f", data[i]);
        } else {
            printf("%.2f ", data[i]);
        }
    }
}
