#include <stdio.h>
#include <math.h>
double function(double x){
    double res = (7.0 * pow(10.0,-3.0)) * (pow(x,4.0)) + ((22.8 * pow(x,1.0 / 3.0) - 1000.0) * x + 3.0) / (x * x / 2.0) - x * pow((10.0 + x), (2.0 / x)) - 1.0;
    return floor(res*10)/10;
}

int main(){
    int a;
    double functRes;
    printf("Введите число : ");
    int testA = scanf("%d", &a);
    if (testA != 0){
        functRes = function(a);
        printf("%3.1f", functRes);
    }
    else{
        printf("n/a");
    }
}
