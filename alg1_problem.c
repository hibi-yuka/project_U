//6�̈��ݕ������Ԏ��̋@������
//���g�������������z�Ɠ����l�i�̈��ݕ������̋@�̍����牽�ԖڂɈʒu����̂��A���̏��i���̒l�i���o�͂���
//���z��90�~,100�~,110�~,120�~,130�~,140�~��6��
//���ݕ��̕��ԏ��Ԃɔ���͂Ȃ��A���g�Őݒ肵�ėǂ��B
//���ނ�Ȃǂ͍l�����Ȃ��ėǂ��B
//�܂��\���̂𗘗p����B�錾���l�̑�����@�Ɏw��͂Ȃ�

#include <stdio.h>
#include <string.h>

typedef struct{

    char name[10];

    int price;

}Drink;

Drink p[6] = {
{"�y�v�V",130},
{"����͂�",100},
{"�J�t�F�I��",120},
{"����",90},
{"�J���s�X",140},
{"BOSS",110}
};


int main(void){


    int num = sizeof(p) / sizeof(p[0]);//�z��̗v�f��

    int my_coin;

    int findID = -1;//���`�T���ɐ��������ꍇ�A���̔z���ێ�����t���O

    printf("�d�݂𓊓����Ă������� ");
    scanf("%d",&my_coin);

    
    for( int i = 0; i<=num; i++){

        printf("���i����%s�A�l�i��%d�~�ł�\n",p[i].name,p[i].price);

        if(my_coin == p[i].price){//�������z�ƈ�v�������i�𔭌������ꍇ
             findID = i;
             break;
        }
    }
    printf("�������z�Ɠ����l�i�̏��i��%d�Ԗڂɂ���܂�\n",findID+1);
    printf("���i����%s�A�l�i��%d�~�ł�\n",p[findID].name,p[findID].price);

    return 0;

}