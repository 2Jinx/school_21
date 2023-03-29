#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

int s21_strlen(char *str) {
    int i = 0;
    while (str[i]) {
        i++;
    }
    return i;
}

int s21_strcmp(char *str1, char *str2) {
    int result;
    int size1 = s21_strlen(str1);
    int size2 = s21_strlen(str2);
    if (size1 == size2) {
        for (int i = 0; i < size1; i++) {
            if (str1[i] > str2[i]) {
                result = 1;
            }
            if (str1[i] < str2[i]) {
                result = -1;
            }
        }
        result = 0;
    }
    if (size1 > size2) {
        result = 1;
    }
    if (size1 < size2) {
        result = -1;
    }
    return result;
}

char *s21_strcpy(char *str1, char *str2) {
    for (int i = 0; str2[i] != '\0'; i++) {
        str1[i] = str2[i];
    }
    return str1;
}

char *s21_strcat(char *str1, char *str2) {
    int size1 = s21_strlen(str1);
    int size2 = s21_strlen(str2);
    int ind = 0;
    str1 = (char *)realloc(str1, size1 + size2);
    for (int i = size1; i < size1 + size2; i++) {
        str1[i] = str2[ind];
        ind++;
    }
    return str1;
}

char *s21_strchr(char *str, char symbol) {
    int size = s21_strlen(str);
    char *res = NULL;
    for (int i = 0; i < size; i++) {
        if (str[i] == symbol) {
            res = str + i;
            break;
        }
    }
    return res;
}

char *s21_strstr(char *str1, char *str2) {
    int flag = 1;
    char *res = NULL;
    int k = 0, j = 0;
    for (int i = 0; i < s21_strlen(str1); i++) {
        if (str1[i] == str2[j]) {
            k = i;
            for (; j < s21_strlen(str2); j++) {
                if (str1[k] != str2[j]) {
                    flag = 0;
                    j = 0;
                    break;
                }
            }
            if (flag == 1) {
                res = str1 + i;
                break;
            }
        }
    }
    return res;
}
