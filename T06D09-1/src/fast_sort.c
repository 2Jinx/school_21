#include <math.h>
#include <stdio.h>

int input(int *a, int n);
void output(int *a, int n, int f);
void quickSort(int *a, int k, int b);
void swap(int *l_item, int *r_item);
int getPivot(int *a, int k, int b);
void mergeSort(int *a, int k, int b);

int main() {
    int n = 10, data[n], newdata[n];
    int fl = input(data, n);
    if (fl == 1) {
        for (int i = 0; i < n; i++) {
            newdata[i] = data[i];
        }
    }
    quickSort(data, 0, n - 1);
    output(data, n, fl);
    printf("\n");
    mergeSort(newdata, 0, n - 1);
    output(newdata, n, fl);
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

void quickSort(int *a, int k, int b) {
    if (k < b) {
        int pivotIndex = getPivot(a, k, b);
        quickSort(a, k, pivotIndex - 1);
        quickSort(a, pivotIndex + 1, b);
    }
}

int getPivot(int *a, int k, int b) {
    int pivot = a[b];
    int i = (k - 1);
    for (int j = k; j <= b; j++) {
        if (a[j] < pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[b]);

    return (i + 1);
}
void swap(int *l_item, int *r_item) {
    int t = *l_item;
    *l_item = *r_item;
    *r_item = t;
}

void mergeSort(int *a, int k, int b) {
    if (b - k < 1) {
        return;
    }
    int c = (k + b) / 2;

    mergeSort(a, k, c);
    mergeSort(a, c + 1, b);

    int mergeArr[b - k + 1];

    int i = k, j = c + 1;
    for (int z = 0; z < b - k + 1; z++) {
        if (i > c) {  // 1 arr is over
            mergeArr[z] = a[j++];
        } else if (j > b) {  // 2 arr is over
            mergeArr[z] = a[i++];
        } else if (a[i] < a[j]) {
            mergeArr[z] = a[i++];
        } else {
            mergeArr[z] = a[j++];
        }
    }

    i = k;
    int n = sizeof(mergeArr) / sizeof(mergeArr[0]);
    for (int z = 0; z < n; z++) {
        a[i++] = mergeArr[z];
    }
}
