    #include <stdio.h>
    #include <stdlib.h>//rand�֐��̗��p
    #include <time.h>//srand�֐��̗��p

    #define max_x 9
    #define max_y 9


    int main(void){


    int filed[max_y][max_x];//�n�}�𐶐�����t�B�[���h
    int x;
    int y;
    int r;

    srand((unsigned)time(NULL));//�v���O�������s�l���ɗ�������������


    for( y = 0; y<max_y; y += 1){//�n�}�̊O����ݒ肷��

        for( x = 0; x<max_x; x += 1){

            if( x == 0 || y == 0){//�㑤�A�����̕ǂ�ݒ�    
                filed[y][x] = 1;
            }else if( x == max_x-1 || y == max_y-1){//�����A�E���̕ǂ�ݒ�
                filed[y][x] = 1;
            }else{
                filed[y][x] = 0;
            }
        }
    }

    y = 2;

    for( x = 2; x<max_x-1; x += 2){//�n�}�̒��̖_��ݒ�       

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
    

    //��������5�ȏ�̊�Ő�������̂���{
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

        

    }//�����܂Œn�}����
    
    return 0;
    /*
    int gps_x = 1;
    int gps_y = 0;

    filed[gps_y][gps_x] = 2;

    if(filed[gps_y+1][gps_x] == 0){//���Ɉړ�

        filed[gps_y+1][gps_x] == 2;

    }else if(filed[gps_y-1][gps_x] == 0){//��Ɉړ�

        filed[gps_y-1][gps_x] == 2;

    }else  if(filed[gps_y][gps_x-1] == 0){//���Ɉړ�

        filed[gps_y][gps_x-1] == 2;

    }else if(filed[gps_y][gps_x+1] == 0){//�E�Ɉړ�

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
        }//�����܂Œn�}��
    }
    return 0;
    }
    */
}
