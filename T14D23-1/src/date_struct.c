#include "date_struct.h"

#include <stdio.h>
#include <stdlib.h>

int struct_input(struct date_struct *date) {
    int y;     // год
    int m;     // месяц
    int d;     // день
    int h;     // час
    int min;   // минута
    int sec;   // секунда
    int st;    // статус
    int cod;   // код
    char end;  // конец строки

    int flag = 1;  // флажок для проверки ввода

    if (scanf("%d %d %d %d %d %d %d %d %c", &y, &m, &d, &h, &min, &sec, &st, &cod, &end) == 9 &&
        (end == '\n' || end == '\0')) {
        date->year = y;
        date->mounth = m;
        date->day = d;
        date->hour = h;
        date->minute = min;
        date->second = sec;
        date->status = st;
        date->code = cod;
    } else {
        flag = 0;
    }

    return flag;
}

void struct_output(struct date_struct date) {
    printf("%d %d %d %d %d %d %d %d\n", date.year, date.mounth, date.day, date.hour, date.minute, date.second,
           date.status, date.code);
}

int struct_compare(struct date_struct date1, struct date_struct date2) {  // равны - 0, -1 - a > b, 1 - a <
                                                                          // b
    int result = 0;
    if (date1.year > date2.year) result = -1;
    if (date1.year < date2.year) result = 1;
    if (date1.year == date2.year) {
        if (date1.mounth > date2.mounth) result = -1;
        if (date1.mounth < date2.mounth) result = 1;
        if (date1.mounth == date2.mounth) {
            if (date1.day > date2.day) result = -1;
            if (date1.day < date2.day) result = 1;
            if (date1.day == date2.day) result = time_compare(date1, date2);
        }
    }

    return result;
}

int time_compare(struct date_struct date1,
                 struct date_struct date2) {  // вспомогательный метод для struct_compare
    int result = 0;
    if (date1.hour > date2.hour) result = -1;
    if (date1.hour < date2.hour) result = 1;
    if (date1.hour == date2.hour) {
        if (date1.minute > date2.minute) result = -1;
        if (date1.minute < date2.minute) result = 1;
        if (date1.minute == date2.minute) {
            if (date1.second > date2.second) result = -1;
            if (date1.second < date2.second) result = 1;
            if (date1.second == date2.second) {
                if (date1.status > date2.status) result = -1;
                if (date1.status < date2.status) result = 1;
                if (date1.status == date2.status) {
                    if (date1.code > date2.code) result = -1;
                    if (date1.code < date2.code) result = 1;
                }
            }
        }
    }

    return result;
}
