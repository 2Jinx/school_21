#include <stdio.h>
int Fibonacci(int k){
    if (k == 1 || k == 2){
        return 1;
    }
    return Fibonacci(k - 1) + Fibonacci(k - 2);
}
int main(){
    int n;
    printf("Введите число : ");
    int test = scanf("%d", &n);
    if (test != 0){
        int res = Fibonacci(n);
        printf("%d",res);
    }
    else{
        printf("n/a");
    }
}
