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

    printf("�����l����͂��Ă�������");
    scanf("%d",&num);

    printf("�K���%d�ł�",factorial(num));

    return 0;


}