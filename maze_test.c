    #include <stdio.h>
    #include <stdlib.h>//rand関数の利用
    #include <time.h>//srand関数の利用

    #define max_x 7
    #define max_y 7

    int main(void){

    int filed[max_y][max_x] = {

    {1,1,1,1,1,1,1},
    {1,0,1,1,1,1,1},
    {1,0,1,1,1,1,1},
    {1,0,1,1,1,1,1},
    {1,0,1,1,1,1,1},
    {1,0,0,0,0,0,1},
    {1,1,1,1,1,1,1}

    };//地図を生成するフィールド
    int x;
    int y;
    int r;

    srand((unsigned)time(NULL));//プログラム実行値時に乱数を初期する
    /*
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
    }//ここまで壁を生成する
    */
                            
    filed[0][1] = 2;

    filed[max_y-1][max_x-2] = 2;

    int gps_x = 1;

    int gps_y = 0;

    filed[gps_y][gps_x] = 2;

    //右手法処理
    
    while(1){

        if(filed[gps_y][gps_x-1] == 1){//下に移動

            filed[gps_y+1][gps_x] = 2;
            gps_y += 1;
            printf("下に移動\n");

        }else if(filed[gps_y][gps_x+1] == 0){//右に移動

            filed[gps_y][gps_x+1] = 2;
            gps_x += 1;
            printf("右に移動\n");

        }else if(filed[gps_y][gps_x-1] == 0){//左に移動

            filed[gps_y][gps_x-1] = 2;
            gps_x -= 1;
            printf("左に移動\n");

        }else if(filed[gps_y-1][gps_x] == 0){//右に移動

            filed[gps_y-1][gps_x] = 2;
            gps_y -= 1;
            printf("右に移動\n");

        }else if(filed[gps_y+1][gps_x] == 1){//壁に激突

            filed[gps_y][gps_x] = 3;

            printf("目の前が壁だ\n");
            
                if(filed[gps_y-1][gps_x] == 1){//右手に壁の場合

                filed[gps_y][gps_x+1] = 2;//進行方向を左へ

                }else if(filed[gps_y-1][gps_x] == 0){//右手に道の場合

                filed[gps_y][gps_x+1] = 2;//進行方向を右へ

                }else { //袋小路に入った場合
                    printf("進行方向を変更しよう\n");
                    if(filed[gps_y-1][gps_x] == 2){//上か道の場合



                    }
                }

        }else if(filed[max_y-1][max_x-2] == 2){//出口に到着
            printf("迷路突破\n");
            break;
        }
    }
    
     for( y = 0; y<max_y; y += 1){

        for(x = 0; x<max_x; x += 1){

            if( filed[y][x] == 0){

                printf("%2s"," ");

            }else if( filed[y][x] == 1){

                printf("%2s","1");

            }else if( filed[y][x] == 2){

                printf("%2s","2");
            }else if(filed[y][x] == 3){

                printf("%2s","3");
            }
           
        }
        printf("\n");
    }//ここまで地図生成    
    return 0;
   
}
