#include <stdio.h>
#include <math.h>
int Division(int a, int b){  //деление чисел a и b
    int div;
    if (b == 0)
        return 0;
    else{
        while (a >= b){
            a = a - b;
            div++;
        }
    }
    return div;
}
int Reminder(int a, int b){  //поиск остатка от деления чисел a и b
    int rem;
    if (b == 0)
        return 0;
    else{
        while (a >= b){
            a = a - b;
            rem = a;
        }
        if(rem < 0){
            rem += b;
        }
    }
    return rem;
}
int IsPrime(int n){  //проверка n числа на простоту
    int i = 2;
    int flag = 1;
    while (i <= sqrt(n)){
        if(Reminder(n,i) == 0){
            flag = 0;
            break;
        }
        i++;
    }
    return flag;
}
int FindNod(int num){  //поиск простого НОД числа
    int nod = 0;
     
    for(int i = 1; i < num; i++){
        if(IsPrime(i) == 1){
            if(Reminder(num,i) == 0){
                nod = i;
            }
            else{
                continue;
            }
        }
        else{
            continue;
        }
    }
    return nod;
}
int main(){
    int x,res;
    printf("Введите x : ");
    int testX = scanf("%d", &x);
    if (testX != 0 && x != 0){
        res = FindNod(x);
        printf("%d",res);
    }
    else{
        printf("n/a");
    }
}
