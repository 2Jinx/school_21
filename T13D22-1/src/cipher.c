#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exist_file(char *filename, int *flag);
void open_file(char *filename, int *flag);
void read_file(FILE *f);
void file_writer(char *filename, int *flag);
void menu();

int main() { menu(); }

void menu() {
    int type = 0, test = 0, flag = 1;
    char *file = malloc(sizeof(char *));
    test = scanf("%d", &type);
    while (type != -1) {
        if (test == 1 && (type == 1 || type == 2 || type == 3)) {
            switch (type) {
                case 1: {
                    scanf("%s", file);
                    exist_file(file, &flag);
                    open_file(file, &flag);
                    break;
                }
                case 2: {
                    file_writer(file, &flag);
                    open_file(file, &flag);
                    break;
                }
                default: {
                    printf("n/a\n");
                    break;
                }
            }
        } else {
            printf("n/a");
            break;
        }
        test = scanf("%d", &type);
    }
    free(file);
}

void exist_file(char *filename, int *flag) {
    int size_of_filename = strlen(filename);
    if (filename[size_of_filename - 4] != '.' && filename[size_of_filename - 3] != 't' &&
        filename[size_of_filename - 2] != 'x' && filename[size_of_filename - 1] != 't') {
        *flag = 0;
    }
}

void open_file(char *filename, int *flag) {
    if (*flag == 1) {
        FILE *f;
        f = fopen(filename, "r");
        if (f == NULL) {
            *flag = 0;
        } else if (*flag == 1) {
            read_file(f);
        }
    } else {
        printf("n/a\n");
    }
}

void read_file(FILE *f) {
    char c = fgetc(f);
    if (c != EOF) {
        while (c != EOF) {
            putchar(c);
            c = fgetc(f);
        }
        putchar('\n');
    } else {
        printf("n/a\n");
    }
    fclose(f);
}

void file_writer(char *filename, int *flag) {
    char a, b;
    if (*flag == 1) {
        FILE *f = fopen(filename, "a");
        if (f != NULL) {
            b = getchar();
            while ((a = getchar()) != '\n') {
                fputc(a, f);
            }
        } else {
            *flag = 0;
            b = getchar();
            b = ' ';
            while (b != '\n') {
                b = getchar();
            }
        }
        fclose(f);
    } else {
        b = getchar();
        b = ' ';
        while (b != '\n') {
            b = getchar();
        }
    }
}
