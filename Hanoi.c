#include <stdio.h>


int hanoi_min(int n){//�~�Ղ��ړ����������v�����߂�

    if(n > 1){
        return( 2*hanoi_min(n-1)+1);
    }else{
        return 1;//�ُ�I��
    }

}

void hanoi(int n,char start,char use,char end){ //2 

    printf("�Ă΂ꂽ\n");

    if(n > 0){

        hanoi(n-1,start,end,use); //1 A C B
        printf("�~��%d���Y%c����Y%c��\n",n,start,end);
        hanoi(n-1,use,start,end);
    }
}

// 1 A C B  ���@0 A C B


int main(void){

    int disk;//�~�Ղ̐�
    printf("�~�Ղ̐�");
    scanf("%d",&disk);

    printf("\n");
    printf("�ړ���%d\n",hanoi_min(disk));
    printf("\n");

    hanoi(disk,'A','B','C');

    return 0;

}