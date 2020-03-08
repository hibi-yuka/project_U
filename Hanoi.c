#include <stdio.h>


int hanoi_min(int n){//‰~”Õ‚ğˆÚ“®‚³‚¹‚½‡Œv‚ğ‹‚ß‚é

    if(n > 1){
        return( 2*hanoi_min(n-1)+1);
    }else{
        return 1;//ˆÙíI—¹
    }

}

void hanoi(int n,char start,char use,char end){ //2 

    printf("ŒÄ‚Î‚ê‚½\n");

    if(n > 0){

        hanoi(n-1,start,end,use); //1 A C B
        printf("‰~”Õ%d‚ğY%c‚©‚çY%c‚Ö\n",n,start,end);
        hanoi(n-1,use,start,end);
    }
}

// 1 A C B  ¨@0 A C B


int main(void){

    int disk;//‰~”Õ‚Ì”
    printf("‰~”Õ‚Ì”");
    scanf("%d",&disk);

    printf("\n");
    printf("ˆÚ“®‰ñ”%d\n",hanoi_min(disk));
    printf("\n");

    hanoi(disk,'A','B','C');

    return 0;

}