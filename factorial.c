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

    printf("®”’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢");
    scanf("%d",&num);

    printf("ŠKæ‚Í%d‚Å‚·",factorial(num));

    return 0;


}