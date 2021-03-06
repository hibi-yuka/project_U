#include <stdio.h>

#define NUMBER 3
#define FAILED -1

int search(int v[], int key, int n){

    int i = 0;

    v[n] = key;

    while(1){
      
        if(v[i] == key){ /*各配列の値をkeyにある探す値が一致したらその配列が入っている値を返す*/
            break;
        }
        i++;
    }
    
    return (i < n) ? i : FAILED;
    
    
}

int main(void){

    int i,ky,idx;
    int v[NUMBER + 1]; 

    for(i = 0; i < NUMBER; i++){ /*ここで配列に値を入力*/
    printf("v[%d] :",i);
    scanf("%d",&v[i]);
    }

    printf("探す値は？ :");
    scanf("%d",&ky);   /*探す値を入力する*/


    if((idx = search(v,ky,NUMBER)) == FAILED){
        puts("\n探索失敗");
    }else{
        printf("%dは%dにあります\n",ky,idx + 1);
    }    /* code */
    return 0;
}
