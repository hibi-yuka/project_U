//6個の飲み物が並ぶ自販機がある
//自身が投入した金額と同じ値段の飲み物が自販機の左から何番目に位置するのか、その商品名の値段も出力せよ
//金額は90円,100円,110円,120円,130円,140円の6つ
//飲み物の並ぶ順番に縛りはなく、自身で設定して良い。
//お釣りなどは考慮しなくて良い。
//また構造体を利用せよ。宣言＆値の代入方法に指定はない

#include <stdio.h>
#include <string.h>

typedef struct{

    char name[10];

    int price;

}Drink;

Drink p[6] = {
{"ペプシ",130},
{"いろはす",100},
{"カフェオレ",120},
{"生茶",90},
{"カルピス",140},
{"BOSS",110}
};


int main(void){


    int num = sizeof(p) / sizeof(p[0]);//配列の要素数

    int my_coin;

    int findID = -1;//線形探索に成功した場合、その配列を保持するフラグ

    printf("硬貨を投入してください ");
    scanf("%d",&my_coin);

    
    for( int i = 0; i<=num; i++){

        printf("商品名は%s、値段は%d円です\n",p[i].name,p[i].price);

        if(my_coin == p[i].price){//投入金額と一致した商品を発見した場合
             findID = i;
             break;
        }
    }
    printf("投入金額と同じ値段の商品は%d番目にあります\n",findID+1);
    printf("商品名は%s、値段は%d円です\n",p[findID].name,p[findID].price);

    return 0;

}