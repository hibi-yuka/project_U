    #include <stdio.h>
    #include <stdlib.h>//rand関数の利用
    #include <time.h>//srand関数の利用

    #define max_x 9
    #define max_y 9


    int main(void){


    int filed[max_y][max_x];//地図を生成するフィールド
    int x;
    int y;
    int r;

    srand((unsigned)time(NULL));//プログラム実行値時に乱数を初期する


    for( y = 0; y<max_y; y += 1){//地図の外周を設定する

        for( x = 0; x<max_x; x += 1){

            if( x == 0 || y == 0){//上側、左側の壁を設定    
                filed[y][x] = 1;
            }else if( x == max_x-1 || y == max_y-1){//下側、右側の壁を設定
                filed[y][x] = 1;
            }else{
                filed[y][x] = 0;
            }
        }
    }

    y = 2;

    for( x = 2; x<max_x-1; x += 2){//地図の中の棒を設定       

        filed[y][x] = 1;

        r = (rand()%12) + 1;

        if(r >= 1 && r <= 3){

            if(filed[y-1][x] == 0){
                filed[y-1][x] = 1;
            }else if(filed[y-1][x] == 1){
                x = x -2;
            }

        }else if(r >=  4&& r <= 6){
            if(filed[y][x+1] == 0){
                filed[y][x+1] = 1;
            }else if(filed[y][x+1] == 1){
                x = x -2;

            }
            
        }else if(r >= 7 && r <= 9){
            if(filed[y+1][x] == 0){
                filed[y+1][x] = 1;
            }else if(filed[y+1][x] == 1){
                x = x -2;
            }

        }else if(r >= 10 && r <= 12){
            if(filed[y][x-1] == 0){
                filed[y][x-1] = 1;
            }else if(filed[y][x-1] == 1){
                x = x -2;
            }
        }
        
    }
    

    //幅高さは5以上の奇数で生成するのが基本
    for(y = 4; y<max_y-1; y += 2){

        for( x = 2; x<max_x-1; x += 2){

            filed[y][x] = 1;

            r = (rand()%12) + 1;

            printf("%d\n",r);

            if(r >= 1 && r <= 4){

                if(filed[y][x+1] == 0){

                    filed[y][x+1] = 1;

                }else if(filed[y][x+1] == 1){

                    x = x -2;

                }

            }else if(r >= 5 && r <= 8){

                if(filed[y+1][x] == 0){

                    filed[y+1][x] = 1;

                }else if(filed[y+1][x] == 1){

                    x = x -2;

                }

            }else if(r >= 9 && r <= 12){

                if(filed[y][x-1] == 0){

                    filed[y][x-1] = 1;

                }else if(filed[y][x-1] == 1){

                    x = x -2;

                }

            }
        }
                                
    }
                            
    filed[0][1] = 2;

    filed[max_y-1][max_x-2] = 2;

    

    for( y = 0; y<max_y; y += 1){

        for(x = 0; x<max_x; x += 1){

            if( filed[y][x] == 0){

                printf("%2s"," ");

            }else if( filed[y][x] == 1){

                printf("%2s","1");

            }else if( filed[y][x] == 2){

                printf("%2s","2");

            }

        }
        
        printf("\n");

        

    }//ここまで地図生成
    
    return 0;
    /*
    int gps_x = 1;
    int gps_y = 0;

    filed[gps_y][gps_x] = 2;

    if(filed[gps_y+1][gps_x] == 0){//下に移動

        filed[gps_y+1][gps_x] == 2;

    }else if(filed[gps_y-1][gps_x] == 0){//上に移動

        filed[gps_y-1][gps_x] == 2;

    }else  if(filed[gps_y][gps_x-1] == 0){//左に移動

        filed[gps_y][gps_x-1] == 2;

    }else if(filed[gps_y][gps_x+1] == 0){//右に移動

        filed[gps_y][gps_x+1] == 2;

    }else if(filed[max_y-1][max_x-2] == 0){

        for( y = 0; y<max_y; y += 1){
            for(x = 0; x<max_x; x += 1){

            if( filed[y][x] == 0){

                printf("%2s"," ");

            }else if(filed[y][x] == 1){

                printf("%2s","1");

            }else if(filed[y][x] == 1){

                printf("%2s","1");
            }
            printf("\n");
        }//ここまで地図生
    }
    return 0;
    }
    */
}
