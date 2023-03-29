#include <stdio.h>
#include <stdlib.h>
/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int *array, int n, int m, int *result_matrix);

/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int *array, int n, int m, int *result_matrix);
int input(int *matrix, int n, int m);
void output(int *matrix, int n, int m);
void swap(int *l_item, int *r_item);
int getPivot(int *a, int k, int b);
void quickSort(int *array, int a, int b);
void get_array_from_matrix(int *matrix, int n, int m, int *array);
int dynamic_memory(int *n, int *m);
int main() {
    int *matrix, *array, *result_matrix;
    int n, m, arr_size;
    int flag = dynamic_memory(&n, &m);
    if (flag == 1) {
        matrix = (int *)malloc(n * m * sizeof(int));
        flag = input(matrix, n, m);
        if (flag == 1) {
            arr_size = n * m;
            result_matrix = (int *)malloc(n * m * sizeof(int));
            array = (int *)malloc(arr_size * sizeof(int));
            get_array_from_matrix(matrix, n, m, array);
            quickSort(array, 0, arr_size - 1);
            sort_horizontal(array, n, m, result_matrix);
            output(result_matrix, n, m);
            printf("\n");
            sort_vertical(array, n, m, result_matrix);
            printf("\n");
            output(result_matrix, n, m);
            free(matrix);
            free(result_matrix);
            free(array);
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
}

int input(int *matrix, int n, int m) {
    int flag = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int test = scanf("%d", matrix + i * m + j);
            if (test != 1) {
                flag = 0;
                break;
            }
            if (flag == 0) {
                break;
            }
        }
    }
    return flag;
}

void output(int *matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == m - 1)
                printf("%d", *(matrix + i * m + j));
            else
                printf("%d ", *(matrix + i * m + j));
        }
        if (i != n - 1) printf("\n");
    }
}

int dynamic_memory(int *n, int *m) {
    int flag = 1;
    int test = scanf("%d%d", n, m);
    if (test != 2 || *n < 0 || *m < 0) {
        flag = 0;
    }
    return flag;
}

void get_array_from_matrix(int *matrix, int n, int m, int *array) {
    int ind = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ind++;
            array[ind] = *(matrix + i * m + j);
        }
    }
}

void quickSort(int *array, int a, int b) {
    if (a < b) {
        int pivotIndex = getPivot(array, a, b);
        quickSort(array, a, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, b);
    }
}

int getPivot(int *array, int a, int b) {
    int pivot = array[b];
    int i = (a - 1);
    for (int j = a; j <= b; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[b]);

    return (i + 1);
}

void swap(int *l_item, int *r_item) {
    int t = *l_item;
    *l_item = *r_item;
    *r_item = t;
}

void sort_horizontal(int *array, int n, int m, int *result_matrix) {
    int ind = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++) {
                *(result_matrix + i * m + j) = array[ind];
                ind++;
            }
        } else {
            for (int j = m - 1; j >= 0; j--) {
                *(result_matrix + i * m + j) = array[ind];
                ind++;
            }
        }
    }
}

void sort_vertical(int *array, int n, int m, int *result_matrix) {
    int ind = 0;
    for (int j = 0; j < m; j++) {
        if (j % 2 == 0) {
            for (int i = 0; i < n; i++) {
                *(result_matrix + i * m + j) = array[ind];
                ind++;
            }
        } else {
            for (int i = n - 1; i >= 0; i--) {
                *(result_matrix + i * m + j) = array[ind];
                ind++;
            }
        }
    }
}
