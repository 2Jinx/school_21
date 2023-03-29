#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void static_memory_matrix();
void dynamic_memory_matrix(int type);
void dynamic_matrx();

int main() {
    int type_of_memory;
    int f = scanf("%d", &type_of_memory);
    if (f == 1 && type_of_memory >= 1 && type_of_memory <= 4) {
        if (type_of_memory == 1) {
            static_memory_matrix();
        } else {
            if (type_of_memory == 4) {
                dynamic_matrx();
            }
            dynamic_memory_matrix(type_of_memory);
        }
    } else {
        printf("n/a");
    }
}

void static_memory_matrix() {
    int n, m;
    int test = scanf("%d%d", &n, &m);
    int flag = 1;
    if (test != 2) {
        flag = 0;
    } else {
        int data[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                test = scanf("%d", &data[i][j]);
                if (test != 1) {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag == 1) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    printf("%d ", data[i][j]);
                }
                printf("\n");
            }
        } else {
            printf("n/a");
        }
    }
    if (flag == 0) {
        printf("n/a");
    }
}

void dynamic_memory_matrix(int type) {
    int n, m;
    int test = scanf("%d%d", &n, &m);
    int flag = 1;
    if (test != 2) {
        flag = 0;
        printf("n/a");
    } else {
        if (type == 2) {
            int *data;
            data = (int *)malloc(n * m * sizeof(int));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int test = scanf("%d", data + i * m + j);
                    if (test != 1) {
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag == 1) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        printf("%d ", *(data + i * m + j));
                    }
                    printf("\n");
                }
                free(data);
            } else {
                printf("n/a");
            }
        } else if (type == 3) {
            int **data;
            data = (int **)malloc(n * sizeof(int));
            for (int i = 0; i < n; i++) {
                data[i] = (int *)malloc(m * sizeof(int));
                for (int j = 0; j < m; j++) {
                    test = scanf("%d", &data[i][j]);
                    if (test != 1) {
                        flag = 0;
                        break;
                    }
                    if (flag == 0) break;
                }
            }
            if (flag == 1) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        printf("%d ", data[i][j]);
                    }
                    printf("\n");
                }
                for (int i = 0; i < n; i++) {
                    free(data[i]);
                }
                free(data);
            } else {
                printf("n/a");
            }
        }
    }
}

void dynamic_matrx() {
    int n, m;
    int test = scanf("%d%d", &n, &m);
    int flag = 1;
    if (test != 2) {
        flag = 0;
    } else {
        int **data;
        int *k;
        data = (int **)malloc(n * sizeof(int *));
        k = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            data[i] = k + m * i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                test = scanf("%d", &data[i][j]);
                if (test != 1) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0) {
                break;
            }
        }
        if (flag == 1) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    printf("%d ", data[i][j]);
                }
                printf("\n");
            }

        } else {
            printf("n/a");
        }
        for (int i = 0; i < n; i++) {
            free(data[i]);
        }
        free(k);
        free(data);
    }
}
