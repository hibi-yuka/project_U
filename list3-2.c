#include <stdio.h>

#define NUMBER 3
#define FAILED -1

int search(int v[], int key, int n){

    int i = 0;

    v[n] = key;

    while(1){
      
        if(v[i] == key){ /*�e�z��̒l��key�ɂ���T���l����v�����炻�̔z�񂪓����Ă���l��Ԃ�*/
            break;
        }
        i++;
    }
    
    return (i < n) ? i : FAILED;
    
    
}

int main(void){

    int i,ky,idx;
    int v[NUMBER + 1]; 

    for(i = 0; i < NUMBER; i++){ /*�����Ŕz��ɒl�����*/
    printf("v[%d] :",i);
    scanf("%d",&v[i]);
    }

    printf("�T���l�́H :");
    scanf("%d",&ky);   /*�T���l����͂���*/


    if((idx = search(v,ky,NUMBER)) == FAILED){
        puts("\n�T�����s");
    }else{
        printf("%d��%d�ɂ���܂�\n",ky,idx + 1);
    }    /* code */
    return 0;
}
