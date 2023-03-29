#ifndef DOOR_STRUCT_H
#define DOOR_STRUCT_H

struct door {
    int id;
    int status;
};

void initialize_doors(struct door* doors);
void set_status(struct door* doors, int status);
void sort(struct door* doors);
void output(struct door* doors);

#endif
