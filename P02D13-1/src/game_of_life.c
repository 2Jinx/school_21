#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define N 80
#define M 25
int map[M][N];

void life();
void print();
int start_page();
void set1();
void set2();
void set3();
void set4();
void set5();
void set6();
int game_settings();
int findNeighboor(int x, int y);

int main() {
    if (start_page() + game_settings() != 2) {
        printf("n/a");
    }
    return 0;
}

void life() {
    int buffer[M][N];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            buffer[i][j] = map[i][j];
        }
    }
    for (int i = 1; i < M - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            if (findNeighboor(i, j) == 3) {
                buffer[i][j] = 1;
            }
            if (findNeighboor(i, j) < 2 || findNeighboor(i, j) > 3) {
                buffer[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            map[i][j] = buffer[i][j];
        }
    }
}

void print() {
    printf("Для выхода из игры нажмите control + 'c'");
    for (int i = 1; i < M - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            if (map[i][j])
                printf("■");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int findNeighboor(int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int r = (x + i + M) % M;
            int c = (y + j + N) % N;
            count += map[r][c];
        }
    }
    return count;
}

int start_page() {
    printf(
        "Добро пожаловать в Game of Life! Выберите номер расстановки для продолжения... \n 1) Долгожители \n "
        "2) Периодические фигуры \n 3) Паровоз \n 4) Чеширский кот \n 5) Осциллятор Герца \n 6) Кастом\n");
    int file;
    int flag = 1;
    int test = scanf("%d", &file);
    if (test == 1 && file > 0 && file <= 6) {
        if (file == 1) {
            set1();
        }
        if (file == 2) {
            set2();
        }
        if (file == 3) {
            set3();
        }
        if (file == 4) {
            set4();
        }
        if (file == 5) {
            set5();
        }
        if (file == 6) {
            set6();
        }
    } else {
        flag = 0;
    }
    return flag;
}

void set1() {
    FILE* fp;
    fp = fopen("files/dolgozhiteli.txt", "rt");
    if (fp == NULL) {
        printf("file is empty");
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            fscanf(fp, "%d ", &map[i][j]);
        }
    }
}

void set2() {
    FILE* fp;
    fp = fopen("files/period.txt", "rt");
    if (fp == NULL) {
        printf("file is empty");
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            fscanf(fp, "%d ", &map[i][j]);
        }
    }
}

void set3() {
    FILE* fp;
    fp = fopen("files/parovoz.txt", "rt");
    if (fp == NULL) {
        printf("file is empty");
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            fscanf(fp, "%d ", &map[i][j]);
        }
    }
}

void set4() {
    FILE* fp;
    fp = fopen("files/cat.txt", "rt");
    if (fp == NULL) {
        printf("file is empty");
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            fscanf(fp, "%d ", &map[i][j]);
        }
    }
}

void set5() {
    FILE* fp;
    fp = fopen("files/gertz.txt", "rt");
    if (fp == NULL) {
        printf("file is empty");
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            fscanf(fp, "%d ", &map[i][j]);
        }
    }
}
void set6() {
    FILE* fp;
    fp = fopen("files/matrix.txt", "rt");
    if (fp == NULL) {
        printf("file is empty");
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            fscanf(fp, "%d ", &map[i][j]);
        }
    }
}

int game_settings() {
    printf(
        "Для выбора скорости выберите один из предложенных режимов ... \n 1) Быстро \n 2) Средне \n 3) "
        "Медленно \n");
    int speed;
    int flag = 1;
    int test = scanf("%d", &speed);
    if (test == 1 && speed > 0 && speed <= 3) {
        if (speed == 1) {
            while (1) {
                life();
                system("clear");
                print();
                usleep(1000);
            }
        }
        if (speed == 2) {
            while (1) {
                life();
                system("clear");
                print();
                usleep(10000);
            }
        } else {
            while (1) {
                life();
                system("clear");
                print();
                usleep(100000);
            }
        }
    } else {
        flag = 0;
    }
    return flag;
}
