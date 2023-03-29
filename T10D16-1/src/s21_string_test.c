#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

void s21_strcmp_test();
void s21_strlen_test();
void s21_strcpy_test();
void s21_strcat_test();
void s21_strchr_test();
void s21_strstr_test();

int main() {
#ifdef strlen
    s21_strlen_test();
#endif
#ifdef strcmp
    s21_strcmp_test();
#endif
#ifdef strcopy
    s21_strcpy_test();
#endif
#ifdef strcat
    s21_strcat_test();
#endif
#ifdef strchr
    s21_strchr_test();
#endif
#ifdef strstr
    s21_strstr_test();
#endif
    return 0;
}

void s21_strlen_test() {
    char *test1 = "Hello!";
    char *test2 = "/";
    char *test3 = "";
    char *test4 = " ";
    int size = 0;

    size = s21_strlen(test1);
    printf("%s %d\n", test1, size);
    if (size == 6) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }

    size = s21_strlen(test2);
    printf("\n%s %d\n", test2, size);
    if (size == 1) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }

    size = s21_strlen(test3);
    printf("\n%s %d\n", test3, size);
    if (size == 0) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }

    size = s21_strlen(test4);
    printf("\n%s %d\n", test4, size);
    if (size == 1) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void s21_strcmp_test() {
    char *test1 = "Hello!";
    char *test2 = "Hello!";
    char *test3 = "Hello";
    char *test4 = "Hello!!";
    int res;

    res = s21_strcmp(test1, test2);
    printf("\n%s %s %d\n", test1, test2, res);
    if (res == 0) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }

    res = s21_strcmp(test1, test3);
    printf("\n%s %s %d\n", test1, test3, res);
    if (res > 0) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }

    res = s21_strcmp(test1, test4);
    printf("\n%s %s %d\n", test1, test4, res);
    if (res < 0) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void s21_strcpy_test() {
    char *test1 = "Hello";
    char *test2 = "\0";
    char *test3 = "Hel-lo!";

    char *copy = malloc((s21_strlen(test1)) * sizeof(char));
    s21_strcpy(copy, test1);
    printf("\n%s %s\n", test1, copy);
    if (s21_strcmp(test1, copy) == 0) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }

    free(copy);

    copy = malloc((s21_strlen(test2)) * sizeof(char));
    copy[0] = '\0';
    s21_strcpy(copy, test2);
    printf("\n%s %s\n", test2, copy);
    if (s21_strcmp(test2, copy) == 0) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }

    free(copy);

    copy = malloc((s21_strlen(test3)) * sizeof(char));
    copy[0] = '\0';
    s21_strcpy(copy, test3);
    printf("\n%s %s\n", test3, copy);
    if (s21_strcmp(test3, copy) == 0) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }

    free(copy);
}

void s21_strcat_test() {
    char *test1 = "Hello,";
    char *test2 = " my";
    char *test3 = " friend!";
    char *str = malloc(sizeof(char));
    char *res = "Hello,";

    str[0] = '\0';
    printf("\n%s %s\n", str, test1);
    s21_strcat(str, test1);
    printf("%s", str);
    if (s21_strcmp(res, str) == 0) {
        printf("\nSUCCESS");
    } else {
        printf("\nFAIL");
    }
    free(str);

    str = malloc(sizeof(char));
    res = "Hello, my";
    printf("\n%s %s\n", str, test2);
    s21_strcat(str, test2);
    printf("%s", str);
    if (s21_strcmp(res, str) == 0) {
        printf("\nSUCCESS");
    } else {
        printf("\nFAIL");
    }
    free(str);

    str = malloc(sizeof(char));
    res = "Hello, my friend!";
    printf("\n%s %s\n", str, test3);
    s21_strcat(str, test3);
    printf("%s", str);
    if (s21_strcmp(res, str) == 0) {
        printf("\nSUCCESS");
    } else {
        printf("\nFAIL");
    }
    free(str);
}

void s21_strchr_test() {
    char *test = "0125345";
    char *res;

    res = s21_strchr(test, '3');
    printf("\n%s 3\n", test);
    if (*res == '3') {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }

    res = s21_strchr(test, '7');
    printf("\n%s 7\n", test);
    if (res == NULL) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }

    res = s21_strchr(test, '5');
    printf("\n%s 5\n", test);
    if (*res == '5') {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void s21_strstr_test() {
    char *test = "ABBAABB";
    char *expected1 = "AA";
    char *res;

    res = s21_strstr(test, expected1);
    printf("\n%s %s\n", test, expected1);
    if (*res == 'A') {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }

    char *expected2 = "BB";
    res = s21_strstr(test, expected2);
    printf("\n%s %s\n", test, expected2);
    if (*res == 'B') {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }

    char *expected3 = "OO";
    res = s21_strstr(test, expected3);
    printf("\n%s %s\n", test, expected3);
    if (res == NULL) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}
