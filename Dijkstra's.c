#include  <stdio.h>


#define N 7 //地点の数

int main(){

    int Distance[N][N] = {
    {0,2,8,4,-1,-1,-1},
    {2,0,-1,-1,3,-1,-1},
    {8,-1,0,-1,2,3,-1},
    {4,-1,-1,0,-1,8,-1},
    {-1,3,2,-1,0,-1,9},
    {-1,-1,3,8,-1,0,3},
    {-1,-1,-1,-1,9,3,0}
    }; //地点の組み合わせに対し、距離が値として代入される

    int nPoint = N; //地点数

    int sp,dp; //出発＆目的地点

    printf("出発地の地点番号を入力してください ==> ");
    scanf("%d",&sp);
  
    printf("目的地の地点番号を入力してください ==> ");
    scanf("%d",&dp);

    int sRoute[nPoint] //spからdpの繋がる地点を持つ配列

    int sDist = 999; //spからdpの距離の値(合算値が入っているの)

    int pDist[nPoint]; //出発地点から各地点までの最短距離を設定する配列

    int pRoute[nPoint];

    bool pFixid[nPoint];  

    int sPoint,i,j,newDist;
    
    for(int i = 0; i<nPoint; i++ ){

        sRoute[i] = -1;
        pDist[i] = 999;
        pFixed[i] = false;
    
    }

    pDist[sp] = 0;

    //次は(5)より

    //出発地から各地点までの最短距離を算出しながら、最短経路を求める

    //行13~22 配列pFixedを調べ、
    //出発地から全ての地点までの最短距離が確定していれば、最短経路探索処理を抜ける

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

     printf("出発地から目的地までの最短経路\n");
  for(i=j;i>=0;i--){
    printf("%d,",sRoute[i]);
  }
  printf("\n出発地から目的地までの最短距離sDist = %d",sDist);
  
  return 0;
}