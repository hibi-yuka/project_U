#include <stdio.h>


int hanoi_min(int n){//円盤を移動させた合計を求める

    if(n > 1){
        return( 2*hanoi_min(n-1)+1);
    }else{
        return 1;//異常終了
    }

}

void hanoi(int n,char start,char use,char end){ //2 

    printf("呼ばれた\n");

    if(n > 0){

        hanoi(n-1,start,end,use); //1 A C B
        printf("円盤%dを杭%cから杭%cへ\n",n,start,end);
        hanoi(n-1,use,start,end);
    }
}

// 1 A C B  →　0 A C B


int main(void){

    int disk;//円盤の数
    printf("円盤の数");
    scanf("%d",&disk);

    printf("\n");
    printf("移動回数%d\n",hanoi_min(disk));
    printf("\n");

    hanoi(disk,'A','B','C');

    return 0;

}