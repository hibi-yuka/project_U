#include <stdio.h>

int main(void){

    int a,b,i;
    int sum = 0;
    int count = 0;

    printf("���͉񐔂͉���ł���?:");
    scanf("%d",&a);

    for( i = 0; i < a; i++){
        printf("NO.%d:",i + 1);
        scanf("%d",&b);
        
        count += 1;
        sum += b;
    }

    printf("���v�l%d,���ϒl��%d",sum,sum/count);

    }

