#ifndef DATE_STRUCT_H
#define DATE_STRUCT_H

struct date_struct {  // одна запись в бинарном файле
    int year;
    int mounth;
    int day;
    int hour;
    int minute;
    int second;
    int status;
    int code;
};

int struct_input(struct date_struct *date);
void struct_output(struct date_struct date);
int struct_compare(struct date_struct date1, struct date_struct date2);
int time_compare(struct date_struct date1, struct date_struct date2);

#endif
