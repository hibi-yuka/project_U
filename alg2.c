#include<stdio.h>
#define FIGURE 7

int main(void){

    int test[10] = {1,2,3,4,5,6,7,8,9,10};

    int number = sizeof(test)/sizeof(int);

    int min = 0 + 1;

    int max = number;

    int mid;//�ŏ��l

    printf("min=%d max=%d\n",min,max);

    while(min <= max){

        mid = (min + max)/2;//�ő�ƍŏ��l���o���Ē����l�����߂�

         printf("�ő�l = %d �ŏ��l = %d �����l = %d\n",max,min,mid);

        if(test[mid] == FIGURE){//�T���lFIGURE��test[�����l]���r���A��v����Ȃ�I���

        printf("����=%d\n",test[mid]);

        printf("������܂���\n");
        return 0;

        }else if(test[mid]<FIGURE){//�T���l�������l���傫���ꍇ�́A�����l+1������

            min = mid + 1;


        }else if(test[mid > FIGURE]){//�T���l�������l�������������A�����l-1������
            max = mid - 1;
        }
    }

    printf("������܂���ł���");
    return 0;

}

