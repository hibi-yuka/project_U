#include <stdio.h>

int factorial(int n){

    if(n>0){
    return n * factorial(n-1);
    }else{
        return 1;
    }
}

int main(void){

    int num;

    printf("整数値を入力してください");
    scanf("%d",&num);

    printf("階乗は%dです",factorial(num));

    return 0;


}