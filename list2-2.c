#include <stdio.h>

#define NUMBER 5 //マクロとしてNUMBER=5を作成

int test[NUMBER];

int top(void);//プロトタイプ宣言

int main(void){

    extern int test[];
    int i;

    printf("%d人の点数を入力してください\n",NUMBER);//人数が自動で渡される
    for( i = 0; i < NUMBER; i++){
        printf("%d人目 : ", i + 1);
        scanf("%d", &test[i]);
    }
    printf("最高点 = %d\n",top());

}


int top(void){

    extern int test[];
    int i;
    int max = test[0];

    for( i = 1; i < NUMBER; i++){
    if(test[i] > max)
    max = test[i];
    }
    return max;

}