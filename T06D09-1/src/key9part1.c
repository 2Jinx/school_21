/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length, int fl, int s);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int n, data[NMAX];
    int s, newdata[NMAX];
    int fl = input(data, &n);
    s = sum_numbers(data, n);
    int c = find_numbers(data, n, s, newdata);
    output(newdata, c, fl, s);
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
        }
    }
    return sum;
}
int input(int *buffer, int *length) {
    int test = scanf("%d", length);
    int flag = 1;
    if (test != 1 || *length > 10 || *length < 0) {
        flag = 0;
    } else {
        for (int i = 0; i < *length; i++) {
            int test = scanf("%d", &buffer[i]);
            if (test != 1) {
                flag = 0;
                break;
            }
        }
        char k = 0;
        if ((k = getchar()) != 10) {
            flag = 0;
        }
    }
    return flag;
}
void output(int *a, int n, int f, int s) {
    if (f == 1) {
        printf("%d\n", s);
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
    } else {
        printf("n/a \n");
    }
}
/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
    int id = 0;
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && number % buffer[i] == 0) {
            numbers[id] = buffer[i];
            count = count + 1;
            id++;
        }
    }
    return count;
}
