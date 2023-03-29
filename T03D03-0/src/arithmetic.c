#include <stdio.h>
int main(){
    int a, b, sum, diff, mult, sub; //a,b-числа,sum-сумма,diff-разность,mult-произведение,sub-частное
    printf("Введите первое число : ");
    int testA = scanf("%d", &a);
    printf("Введите второе число : ");
    int testB = scanf("%d", &b);
    if (testA != 0 && testB != 0){
        sum = a + b;
        diff = a - b;
        mult = a * b;
        if (b == 0){
            printf("%d %d %d n/a", sum, diff, mult);
        }
        else{
            sub = a / b;
            printf("%d %d %d %d", sum, diff, mult, sub);
        }
    }
    else{
        printf("n/a");
    }
}
