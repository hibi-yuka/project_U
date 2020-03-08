#include <stdio.h>

#define NUMBER 3
#define FAILED -1

int search(int v[], int key, int n){

    int i = 0;

    v[n] = key;

    while(1){
      
        if(v[i] == key){ /*Še”z—ñ‚Ì’l‚ðkey‚É‚ ‚é’T‚·’l‚ªˆê’v‚µ‚½‚ç‚»‚Ì”z—ñ‚ª“ü‚Á‚Ä‚¢‚é’l‚ð•Ô‚·*/
            break;
        }
        i++;
    }
    
    return (i < n) ? i : FAILED;
    
    
}

int main(void){

    int i,ky,idx;
    int v[NUMBER + 1]; 

    for(i = 0; i < NUMBER; i++){ /*‚±‚±‚Å”z—ñ‚É’l‚ð“ü—Í*/
    printf("v[%d] :",i);
    scanf("%d",&v[i]);
    }

    printf("’T‚·’l‚ÍH :");
    scanf("%d",&ky);   /*’T‚·’l‚ð“ü—Í‚·‚é*/


    if((idx = search(v,ky,NUMBER)) == FAILED){
        puts("\n’TõŽ¸”s");
    }else{
        printf("%d‚Í%d‚É‚ ‚è‚Ü‚·\n",ky,idx + 1);
    }    /* code */
    return 0;
}
