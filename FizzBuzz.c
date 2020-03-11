
#include <stdio.h>


int main(){

    int number;


    printf("”’l“ü—Í");
    scanf("%d",&number);

    
    for( int a = 31; number<a; number++){

        if( number % 3 == 0 && number % 5 == 0){

        printf("%d FizzBuzz\n",number);
    
        }else if( number % 3 == 0 ){

        printf("%d Fizz\n",number);

        }else if( number %  5 == 0){

         printf("%d Buzz\n",number);

        }else {

        printf("%d Not Found\n",number);

        }
    }

    return 0;

}