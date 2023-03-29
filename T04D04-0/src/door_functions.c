#include <math.h>
#include <stdio.h>

double Anessi(double x){
    return 1 / (1 + pow(x,2));
}
double Bernulli(double x){
    if ((sqrt(1 + 4 * pow(x, 2)) - pow(x, 2) - 1) >= 0){
        return (sqrt(sqrt(1 + 4 * pow(x, 2)) - pow(x, 2) - 1));
    }
    else{
        return 0;
    }
}
double Hyperbola(double x){
    if (x == 0){
        return 0;
    }
    else{
        return 1 / pow(x,2);
    }
}
int main(){
    double partOfPi = M_PI / 21;
    double x = M_PI * (-1);
    int count = 0;
    while (x < M_PI){
        double anessi = Anessi(x);
        double bernulli = Bernulli(x);
        double hyperbola = Hyperbola(x);
        if (x == 0){
            printf("%f | %f | - | - \n", x, anessi);
        if (x >= 0 && x <= M_PI){
            }
            if (hyperbola == 0){
                printf("%f | %f | - | - \n", x, anessi);
            }
            else{
                printf("%f | %f | - | %f \n", x, anessi, hyperbola);
            }
        }
        else{
            if (bernulli != 0){
                if (hyperbola == 0){
                    printf("%f | %f | %f | - \n", x, anessi, bernulli);
                }
                else{
                    printf("%f | %f | %f | %f \n", x, anessi, bernulli, hyperbola);
                }
            }
            else{
                if (hyperbola == 0){
                    printf("%f | %f | - | - \n", x, anessi);
                }
                else{
                    printf("%f | %f | - | %f \n", x, anessi, hyperbola);
                }
                
            }
        }
        x += partOfPi;
        count++;
    }
    printf("%d", count);
}

