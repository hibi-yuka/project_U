#include <stdio.h>

int main(void){

    int x,y;
    int sum = 0;
    int count = 0;

    do{        
    printf("合計と平均を計算します\nxの値を入力して下さい:");
    scanf("%d",&x);
    printf("%dが入力されました\n",x);

    sum = sum + x;
    count = count + 1;

    printf("合計値は%dです",sum);
    printf("計算を続けたい場合は1と入力してください:");
    scanf("%d",&y);

    }while(y==1);

    printf("カウントは次の通りです 合計%d 平均%d\n",sum,count);

    printf("現在の合計は%d,平均は%.2fです\n",sum,(double)sum/count);

    return 0;
}