#include <stdio.h>

int main(void){

    int x;
    int sum = 0 ;
    int i;

    printf("���͂����肢���܂�:");
    scanf("%d",&x);

    /*25��̃��[�v��1~10�܂ł�\�����A�܂��ŏ�������*/

    for( i = 1; i <= x; i ++){

    printf("%d", i % 10);

    }
    putchar('\n');
    return 0;

}