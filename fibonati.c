#include <stdio.h>
#include <stdlib.h>

int fib(int b){

    switch (b){

    case 0:
    return 0;
    
    case 1:
    return 1;

    default:
    return fib(b-1) + fib(b-2);
    
    }
}


int main(){


    int a;

    printf("�ǂ̒l�܂Ōv�Z���܂����H");
    scanf("%d",&a);

    for( int b = 0; b < a; b++){

        printf("%d�Ԗڂ̃t�B�{�i�b�`�����%d�ł�\n",b, fib(b));

    }

    printf("end");

    return 0;

}