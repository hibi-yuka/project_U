
#include <stdio.h>

#define NUMBER 3

int man;

int max_of(int v[],int n){

    int i;
    int max = v[0];

    for( i = 1; i < n; i++){

        if(v[i] > max)
        man = i + 1;
        max = v[i];
    }

    return max;
}


int main(void){

    int i;
    int eng[NUMBER];
    int mat[NUMBER];
    int max_e,max_m;

    printf("%d人の点数を入力してください\n",NUMBER);
    
    for( i = 0; i < NUMBER; i++){

        printf("[%d] 英語 :",i + 1);
        scanf("%d",&eng[i]);
        printf("     数学 :",i + 1);
        scanf("%d",&mat[i]);

    }

    max_e = max_of(eng,NUMBER);
    printf("英語の最高得点 %d点 取ったのは%d番目の子 :",max_e,man);

    max_m = max_of(mat,NUMBER);
    printf("数学の最高得点 %d点 取ったのは%d番目の子:",max_m,man);

    return 0;

}