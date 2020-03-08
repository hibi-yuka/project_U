#include <stdio.h>

int main(void){

    int x;
    int sum = 0 ;
    int i;

    printf("入力をお願いします:");
    scanf("%d",&x);

    /*25回のループで1~10までを表示し、また最初からやる*/

    for( i = 1; i <= x; i ++){

    printf("%d", i % 10);

    }
    putchar('\n');
    return 0;

}