#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binary_files_operations.h"

void menu();

int main() { menu(); }

void menu() {
    int type = 0, test = 0, flag = 1;
    char *file = malloc(sizeof(char *));
    scanf("%s", file);
    test = scanf("%d", &type);
    if (test == 1 && (type == 0 || type == 1 || type == 2)) {
        switch (type) {
            case 0: {
                open_binary_file(file, &flag, type);
                break;
            }
            case 1: {
                open_binary_file(file, &flag, type);
                break;
            }
            case 2: {
                open_binary_file(file, &flag, type);
                break;
            }
            default: {
                printf("n/a\n");
                break;
            }
        }
    } else {
        printf("n/a");
    }
    free(file);
}
