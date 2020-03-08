#include <stdio.h>
#include <stdlib.h>

void r(int);

void r(int n){

    if(n > 0){
        r(n-2);
        printf("%3d",n);
        r(n-1);
    }
}


int main(){

    r(4);

    return 0;


}