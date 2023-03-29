#include <stdio.h>
float lockPicker(float i, float j){
    if (((i * i) + (j * j)) < 25.0){
        printf("GOTCHA");
    }
    else{
        printf("MISS");
    }
}
int main(){
    float x, y;
    printf("Введите x : ");
    int testX = scanf("%f", &x);
    printf("Введите y : ");
    int testY = scanf("%f", &y);
    if (testX != 0 && testY != 0){
        lockPicker(x,y);
    }
    else{
        printf("n/a");
    }
}
