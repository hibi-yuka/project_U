#include <stdio.h>

int main(void){

    int a,b,i;
    int sum = 0;
    int count = 0;

    printf("入力回数は何回ですか?:");
    scanf("%d",&a);

    for( i = 0; i < a; i++){
        printf("NO.%d:",i + 1);
        scanf("%d",&b);
        
        count += 1;
        sum += b;
    }

    printf("合計値%d,平均値は%d",sum,sum/count);

    }

