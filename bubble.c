#include <stdio.h>

int main(void){

    int a[] = {1,7,5,4,3,6,2};

    int a_LIST = sizeof(a) / sizeof(a[0]);

    int i,j;

    
        printf("�ŏ��̔z��@");
        for(int b = 0 ; b < a_LIST; b++){  //b���z��̗v�f��菬������
            printf(" %d ",a[b]);
            if( b == a_LIST - 1 ){
            printf("\n");
            }
        }
    

    
    for(int i = 0 ; i < a_LIST; i++){ //�z��̗v�f���̉񐔂̃��[�v
        for(int j = 0; j < a_LIST; j++){
        int tmp;
                if( a[j] > a[j + 1] ){ //j�����[�v��0����ǂ�ǂ񑝂��Ă����̂ŁAj+1�Ŕ�r�����Ĉ�Ԓ[�܂Ŏ����Ă���
                tmp = a[j];
                a [j] = a[j + 1];
                a[j + 1] = tmp;
                }
            }
        }
    

   
    
    printf("����ւ�����̔z��@");
        for(int b = 0 ; b < a_LIST; b++){  //b���z��̗v�f��菬������
        
        printf(" %d ",a[b]);
            if( b == a_LIST - 1 ){
            printf("\n");
            }
        }
    

    return 0;
}

