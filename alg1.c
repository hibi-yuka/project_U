#include <stdio.h>

int main(void)
{

    int a_list[5] = {0, 2, 6, 3, 5};

    int serch_a = 3; //この値を探す

    int findID = -1; //見つかったときの番号

    int num = sizeof(a_list) / sizeof(a_list[0]);//配列の要素数を計算

    for (int i = 0; i < num; i++){

        printf("%d\n",a_list[i]);

        if (a_list[i] == serch_a){
            findID = i;
            break;
        }
    }
    
    printf("要素数は%d\n", num);
    printf("見つかった番号は=%d", findID);

    return 0;
}
