#include<stdio.h>

int main(void){

    int valueX = 100;
    int valueY = 200;

    int *ptr;

    int *ptr2;

    ptr = &valueX;
  
    ptr2 = ptr;
    printf("%p\n",ptr);
     printf("%p\n",valueX);
    printf("%p\n",ptr2);

    return 0;

}


