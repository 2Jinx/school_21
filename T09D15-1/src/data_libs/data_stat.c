#include "data_stat.h"

#include <math.h>
#include <stdio.h>

double mean(double *data, int n) {
    double mean = 0.0;
    double pi = 1.0 / n;
    for (double *p = data; p - data < n; p++) {
        mean = mean + (*p) * pi;
    }
    return mean;
}

double squareMean(double *data, int n) {
    double sqm = 0.0;
    double pi = 1.0 / n;
    for (double *p = data; p - data < n; p++) {
        sqm = sqm + ((*p) * (*p)) * pi;
    }
    return sqm;
}
double variance(double *data, int n) { return squareMean(data, n) - mean(data, n) * mean(data, n); }

double max(double *data, int n) {
    double max = data[0];
    for (int i = 0; i < n; i++) {
        if (max < data[i]) {
            max = data[i];
        }
    }
    return max;
}

double min(double *data, int n) {
    double min = data[0];
    for (int i = 0; i < n; i++) {
        if (min > data[i]) {
            min = data[i];
        }
    }
    return min;
}

void sort(double *data, int n) {
    int flag = 1;
    while (flag == 1) {
        flag = 0;
        for (int i = 0; i < n - 1; i++) {
            if (data[i] > data[i + 1]) {
                int t = data[i];
                data[i] = data[i + 1];
                data[i + 1] = t;
                flag = 1;
            }
        }
    }
}
