#include <stdio.h>

int main(void)
{

    int a_list[5] = {0, 2, 6, 3, 5};

    int serch_a = 3; //���̒l��T��

    int findID = -1; //���������Ƃ��̔ԍ�

    int num = sizeof(a_list) / sizeof(a_list[0]);//�z��̗v�f�����v�Z

    for (int i = 0; i < num; i++){

        printf("%d\n",a_list[i]);

        if (a_list[i] == serch_a){
            findID = i;
            break;
        }
    }
    
    printf("�v�f����%d\n", num);
    printf("���������ԍ���=%d", findID);

    return 0;
}
