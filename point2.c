#include <stdio.h>

int main(void){

    int a = 10;
    int *b;

    b = &a;

    printf("%d\n",a);

    //����͓����A�h���X���w���Ă���
    printf("%p\n",&a); 
    printf("%p\n",b);

    //���ɂ͒l�����ړ����Ă���B*������b�̒l�ɊԐړI�ɃA�N�Z�X�ł���
    printf("%d\n",*b);
    
    printf("%p\n",&b); 

    return 0;
}

//�o�͌���
//10
//0061FF1C
//0061FF1C
//10
//0061FF18
