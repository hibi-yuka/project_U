#include <stdio.h>

#define NUMBER 5 //�}�N���Ƃ���NUMBER=5���쐬

int test[NUMBER];

int top(void);//�v���g�^�C�v�錾

int main(void){

    extern int test[];
    int i;

    printf("%d�l�̓_������͂��Ă�������\n",NUMBER);//�l���������œn�����
    for( i = 0; i < NUMBER; i++){
        printf("%d�l�� : ", i + 1);
        scanf("%d", &test[i]);
    }
    printf("�ō��_ = %d\n",top());

}


int top(void){

    extern int test[];
    int i;
    int max = test[0];

    for( i = 1; i < NUMBER; i++){
    if(test[i] > max)
    max = test[i];
    }
    return max;

}