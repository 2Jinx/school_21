#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binary_files_operations.h"

int main() {
    char *file = malloc(sizeof(char));
    scanf("%s", file);
    int res;
    res = search_in_binary_file(file);
    printf("%d", res);
    free(file);
}
