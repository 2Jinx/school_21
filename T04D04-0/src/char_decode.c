#include <math.h>
#include <stdio.h>
//void inHex(char num){
//    while (num > 0){
//        if (num % 16 < 10){
//            printf("%d", num % 16);
//            num = num / 16;
//        }
//        if (num % 16 == 10)
//            num = num / 16;
//            printf("%c",
//    }
//}
void Coding(char str){
    int countSpaces, repeats;
    countSpaces = 0;
    repeats = 0;
    while ((str = getchar()) != 10){
        repeats++;
        if (str == 32){
            countSpaces++;
            continue;
        }
        else{
            if (countSpaces == 0 && repeats > 1){
                printf("n/a");
                break;
            }
            else{
                printf (" %3d%s", str, (str == '\n' ? "\n" : ""));
            }
        }
    }
}
int main(){
    char s;
    Coding(s);
    char c = 'A';
    printf("%d", c);
}
