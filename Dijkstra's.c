#include  <stdio.h>


#define N 7 //�n�_�̐�

int main(){

    int Distance[N][N] = {
    {0,2,8,4,-1,-1,-1},
    {2,0,-1,-1,3,-1,-1},
    {8,-1,0,-1,2,3,-1},
    {4,-1,-1,0,-1,8,-1},
    {-1,3,2,-1,0,-1,9},
    {-1,-1,3,8,-1,0,3},
    {-1,-1,-1,-1,9,3,0}
    }; //�n�_�̑g�ݍ��킹�ɑ΂��A�������l�Ƃ��đ�������

    int nPoint = N; //�n�_��

    int sp,dp; //�o�����ړI�n�_

    printf("�o���n�̒n�_�ԍ�����͂��Ă������� ==> ");
    scanf("%d",&sp);
  
    printf("�ړI�n�̒n�_�ԍ�����͂��Ă������� ==> ");
    scanf("%d",&dp);

    int sRoute[nPoint] //sp����dp�̌q����n�_�����z��

    int sDist = 999; //sp����dp�̋����̒l(���Z�l�������Ă����)

    int pDist[nPoint]; //�o���n�_����e�n�_�܂ł̍ŒZ������ݒ肷��z��

    int pRoute[nPoint];

    bool pFixid[nPoint];  

    int sPoint,i,j,newDist;
    
    for(int i = 0; i<nPoint; i++ ){

        sRoute[i] = -1;
        pDist[i] = 999;
        pFixed[i] = false;
    
    }

    pDist[sp] = 0;

    //����(5)���

    //�o���n����e�n�_�܂ł̍ŒZ�������Z�o���Ȃ���A�ŒZ�o�H�����߂�

    //�s13~22 �z��pFixed�𒲂ׁA
    //�o���n����S�Ă̒n�_�܂ł̍ŒZ�������m�肵�Ă���΁A�ŒZ�o�H�T�������𔲂���

    while(true){

        i=0;

        while(true){
        
            if( i < nPoint){
                if(pFixed[i] == 0);
                break;
            }

        i = i + 1;

        }

        if(i == nPoint){
            break;

        }

        for(j = i + 1; i < nPoint; j++){
            if((pFixed[j] == 0) && (pDist[j] < pDist[i])) 
            i = j;  
        }
    }
    sPoint = i;

    pFixed[sPoint] == true;

    for(j = 0; j < nPoint, j++){
        if((Distance[sPoint][i] > 0) && (pFixed[j]==0)){

           newDist =  pDist[sPoint] + Distance[sPoint][j];
            if(newDist < pDist[j]){
                pDist[j] = newDist;
                pRoute[j] = sPoint;
            }
        }
    }

    sDist = pDist[dp];
    j = 0;
    i = dp;

    while( i != sp){

    sRoute[j] = i;
    i = pRoute[i];
    j = j + 1;    
    }

    sRoute[j] = sp;

     printf("�o���n����ړI�n�܂ł̍ŒZ�o�H\n");
  for(i=j;i>=0;i--){
    printf("%d,",sRoute[i]);
  }
  printf("\n�o���n����ړI�n�܂ł̍ŒZ����sDist = %d",sDist);
  
  return 0;
}