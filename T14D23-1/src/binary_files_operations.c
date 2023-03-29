#include "binary_files_operations.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "date_struct.h"

void open_binary_file(char *filename, int *flag, int oper) {
    if (*flag == 1) {
        if (oper == 2) {
            write_binary_file(filename, flag, oper);
            oper = 1;
        }
        FILE *f;
        char file[30] = "../";
        strcat(file, filename);
        f = fopen(file, "ab+");
        if (f == NULL) {
            *flag = 0;
        } else {
            read_binary_file(f, oper);
        }
    } else {
        printf("n/a\n");
    }
}

void read_binary_file(FILE *file, int operation) {
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    struct date_struct *array = malloc(length * sizeof(array));
    while (!feof(file)) {
        fread((char *)array, length, 8, file);
    }
    int flag = 1;
    if (operation == 1) {
        while (flag) {
            flag = 0;
            for (int i = 0; i < (length / 32) - 1; i++) {
                if (struct_compare(array[i], array[i + 1]) < 0) {
                    struct date_struct tmp = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = tmp;
                    flag = 1;
                }
            }
        }
        operation = 0;
    }
    if (operation == 0) {
        for (int i = 0; i < length / 32; i++) {
            struct_output(array[i]);
        }
    }
    free(array);
    fclose(file);
}

void write_binary_file(char *filename, int *flag, int oper) {
    if (oper == 2) {
        FILE *f;
        char file[30] = "../";
        strcat(file, filename);
        f = fopen(file, "ab+");
        if (f == NULL) {
            *flag = 0;
        } else {
            int cnt = 0;
            unsigned int c = 0;
            while (cnt != 8) {
                scanf("%d", &c);
                fwrite((char *)&c, sizeof(unsigned int), 1, f);
                cnt++;
            }
        }
        fclose(f);
    }
}

int search_in_binary_file(char *filename) {
    int flag = 1;
    FILE *f;
    char file[30] = "../";
    strcat(file, filename);
    f = fopen(file, "ab+");
    if (f == NULL) {
        flag = 0;
    }
    int count = 0;
    if (flag == 1) {
        char *search = malloc(sizeof(char *));
        scanf("%s", search);
        int y = 0, m = 0, d = 0;
        char k[4];
        k[0] = search[0];
        k[1] = search[1];
        d = atoi(k);
        k[0] = search[3];
        k[1] = search[4];
        m = atoi(k);
        k[0] = search[6];
        k[1] = search[7];
        k[2] = search[8];
        k[3] = search[9];
        y = atoi(k);
        fseek(f, 0, SEEK_END);
        long length = ftell(f);
        fseek(f, 0, SEEK_SET);
        struct date_struct *array = malloc(length * sizeof(array));
        while (!feof(f)) {
            fread((char *)array, length, 8, f);
        }
        int fl = 1;
        while (fl) {
            for (int i = 0; i < length / 32; i++) {
                if (array[i].year == y && array[i].mounth == m && array[i].day == d) {
                    count = array[i].code;
                    fl = 0;
                }
            }
        }
        free(array);
        free(search);
        fclose(f);
    }
    return count;
}
