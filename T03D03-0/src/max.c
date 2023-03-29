#include <stdio.h>
int max(int i, int j){
    if (i > j)
        return i;
    else
        return j;
}
int main(){
    int a, b, maximum;
    printf("Введите первое число : ");
    int testA = scanf("%d", &a);
    printf("Введите второе число : ");
    int testB = scanf("%d", &b);
    if (testA != 0 && testB != 0){
        maximum = max(a,b);
        printf("%d", maximum);
    }
    else{
        printf("n/a");
    }
}
