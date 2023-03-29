#ifndef BINARY_FILES_OPERATIONS_H
#define BINARY_FILES_OPERATIONS_H

#include <stdio.h>

void open_binary_file(char *filename, int *flag, int oper);
void read_binary_file(FILE *file, int operation);
void write_binary_file(char *filename, int *flag, int oper);
int search_in_binary_file(char *filename);

#endif
