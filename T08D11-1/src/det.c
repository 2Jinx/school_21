#include <stdio.h>
#include <stdlib.h>

double det(double **matrix, int n);
int dynamic_memory(int *n, int *m);
int input(double **matrix, int n);
void output(double det);
void get_minor(double **matrix, double **p, int i, int j, int n);

int main() {
    double **matrix;
    double determinant;
    int n, m;
    int flag = dynamic_memory(&n, &m);
    if (flag == 1) {
        matrix = (double **)malloc(n * sizeof(double));
        for (int i = 0; i < n; i++) matrix[i] = (double *)malloc(m * sizeof(double));
        flag = input(matrix, n);
        if (flag == 1) {
            determinant = det(matrix, n);
            output(determinant);
            for (int i = 0; i < n; i++) {
                free(matrix[i]);
            }
            free(matrix);
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
}

int dynamic_memory(int *n, int *m) {
    int flag = 1;
    int test = scanf("%d%d", n, m);
    if (test != 2 || *n < 1 || *m < 1 || (*n) != (*m)) {
        flag = 0;
    }
    return flag;
}

int input(double **matrix, int n) {
    int flag = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int test = scanf("%lf", &matrix[i][j]);
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

void output(double determinant) { printf("%f", determinant); }

void get_minor(double **matrix, double **p, int row, int column, int n) {
    int r = 0, c = 0;
    for (int i = 0; i < n - 1; i++) {
        if (i == row) {
            r = 1;
        }

        c = 0;
        for (int j = 0; j < n - 1; j++) {
            if (j == column) {
                c = 1;
            }

            p[i][j] = matrix[i + r][j + c];
        }
    }
}

double det(double **matrix, int n) {
    double **p;
    double determinant;
    int k = 1;
    if (n == 1) {
        determinant = matrix[0][0];
        return determinant;
    }
    if (n == 2) {
        determinant = matrix[0][0] * matrix[1][1] - (matrix[0][1] * matrix[1][0]);
        return determinant;
    }
    if (n > 2) {
        p = (double **)malloc((n * n - 1) * sizeof(double *));
        for (int i = 0; i < n - 1; i++) {
            p[i] = malloc((n - 1) * sizeof(double));
        }
        for (int i = 0; i < n; i++) {
            get_minor(matrix, p, i, 0, n);
            determinant += k * matrix[0][i] * det(p, n - 1);
            k = -k;
        }
        for (int i = 0; i < n; i++) {
            free(p[i]);
        }
        free(p);
    }
    return determinant;
}
