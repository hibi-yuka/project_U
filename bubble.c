#include <stdio.h>

int main(void){

    int a[] = {1,7,5,4,3,6,2};

    int a_LIST = sizeof(a) / sizeof(a[0]);

    int i,j;

    
        printf("最初の配列　");
        for(int b = 0 ; b < a_LIST; b++){  //bが配列の要素より小さい時
            printf(" %d ",a[b]);
            if( b == a_LIST - 1 ){
            printf("\n");
            }
        }
    

    
    for(int i = 0 ; i < a_LIST; i++){ //配列の要素分の回数のループ
        for(int j = 0; j < a_LIST; j++){
        int tmp;
                if( a[j] > a[j + 1] ){ //jがループで0からどんどん増えていくので、j+1で比較をして一番端まで持っていく
                tmp = a[j];
                a [j] = a[j + 1];
                a[j + 1] = tmp;
                }
            }
        }
    

   
    
    printf("入れ替えた後の配列　");
        for(int b = 0 ; b < a_LIST; b++){  //bが配列の要素より小さい時
        
        printf(" %d ",a[b]);
            if( b == a_LIST - 1 ){
            printf("\n");
            }
        }
    

    return 0;
}

