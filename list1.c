#include <stdio.h>

int main(void){

    int x,y;
    int sum = 0;
    int count = 0;

    do{        
    printf("���v�ƕ��ς��v�Z���܂�\nx�̒l����͂��ĉ�����:");
    scanf("%d",&x);
    printf("%d�����͂���܂���\n",x);

    sum = sum + x;
    count = count + 1;

    printf("���v�l��%d�ł�",sum);
    printf("�v�Z�𑱂������ꍇ��1�Ɠ��͂��Ă�������:");
    scanf("%d",&y);

    }while(y==1);

    printf("�J�E���g�͎��̒ʂ�ł� ���v%d ����%d\n",sum,count);

    printf("���݂̍��v��%d,���ς�%.2f�ł�\n",sum,(double)sum/count);

    return 0;
}