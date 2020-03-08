#include<stdio.h>
#define FIGURE 7

int main(void){

    int test[10] = {1,2,3,4,5,6,7,8,9,10};

    int number = sizeof(test)/sizeof(int);

    int min = 0 + 1;

    int max = number;

    int mid;//最小値

    printf("min=%d max=%d\n",min,max);

    while(min <= max){

        mid = (min + max)/2;//最大と最小値を出して中央値を求める

         printf("最大値 = %d 最小値 = %d 中央値 = %d\n",max,min,mid);

        if(test[mid] == FIGURE){//探す値FIGUREとtest[中央値]を比較し、一致するなら終わる

        printf("結果=%d\n",test[mid]);

        printf("見つかりました\n");
        return 0;

        }else if(test[mid]<FIGURE){//探す値が中央値より大きい場合は、中央値+1をする

            min = mid + 1;


        }else if(test[mid > FIGURE]){//探す値が中央値よりも小さい時、中央値-1をする
            max = mid - 1;
        }
    }

    printf("見つかりませんでした");
    return 0;

}

