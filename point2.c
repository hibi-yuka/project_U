#include <stdio.h>

int main(void){

    int a = 10;
    int *b;

    b = &a;

    printf("%d\n",a);

    //下二つは同じアドレスを指している
    printf("%p\n",&a); 
    printf("%p\n",b);

    //下には値が直接入っている。*がつくとbの値に間接的にアクセスできる
    printf("%d\n",*b);
    
    printf("%p\n",&b); 

    return 0;
}

//出力結果
//10
//0061FF1C
//0061FF1C
//10
//0061FF18
