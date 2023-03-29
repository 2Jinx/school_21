#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

int main() {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    sort(doors);
    for (int i = 0; i < DOORS_COUNT; i++) {
        set_status(&doors[i], 0);
    }
    output(doors);
    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void set_status(struct door* doors, int status) { doors->status = status; }

void sort(struct door* doors) {
    int flag = 1;
    while (flag == 1) {
        flag = 0;
        for (int i = 0; i < DOORS_COUNT - 1; i++) {
            if (doors[i].id > doors[i + 1].id) {
                struct door tmp = doors[i];
                doors[i] = doors[i + 1];
                doors[i + 1] = tmp;
                flag = 1;
            }
        }
    }
}

void output(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        printf("%d %d", doors[i].id, doors[i].status);
        if (i != DOORS_COUNT - 1) {
            printf("\n");
        }
    }
}
