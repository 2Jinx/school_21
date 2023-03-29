#include "print_module.h"

#include <stdio.h>
#include <string.h>
#include <time.h>

void print_log(char (*print)(char), char* message);

char print_char(char ch) { return putchar(ch); }
void print_log(char (*print)(char), char* message) {
    for (int i = 0; i < (int)strlen(Log_prefix); i++) {
        print(Log_prefix[i]);
    }
    int m_length = strlen(message);
    time_t real_time = time(NULL);
    struct tm* u = localtime(&real_time);
    char t[11];
    sprintf(t, "%02d:%02d:%02d ", u->tm_hour, u->tm_min, u->tm_sec);
    for (int i = 0; t[i] != '\0'; i++) {
        print(t[i]);
    }
    for (int i = 0; i < m_length; i++) {
        print(message[i]);
    }
}
