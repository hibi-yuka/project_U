#include <stdio.h>

void change(int *na,int *nb){ //ここで仮引数はアドレスが渡されている

    int suttc = *na; //ここではアドレスの中身が渡される
    *na = *nb;
    *nb = suttc;

}


int main(){

    int na = 11;
    int nb = 22;

    printf("na=%d\n",na);
    printf("nb=%d\n",nb);

    change(&na,&nb);

    printf("na=%d\n",na);
    printf("nb=%d\n",nb);

    return 0;

}