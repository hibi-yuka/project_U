#include <stdio.h>

void FB();

int main(){

    FB();
    return 0;
    
}


void FB(){

    for( int a = 1; a<50; a++){

    //printf(a % 15 == 0 ? "%d Fizzbuzz\n",a : a % 3 == 0 ? "%d Fizz\n",a : a % 5 == 0 ? "%d Buzz\n",a : "%d\n",a);
    
    printf(a % 15 == 0 ? "%d Fizzbuzz\n" : a % 3 == 0 ? "%d Fizz\n" : a % 5 == 0 ? "%d Buzz\n" : "%d\n",a);
    //printf(a % 15 == 0 ? "%d FizzBuzz\n",a : a % 3 == 0 ? "%d Fizz\n",a : a % 5 == 0 ? "%d Buzz\n",a : "%d Not\n",a);
    }
}