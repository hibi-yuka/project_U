    #include <stdio.h>
    #include <stdlib.h>//rand�֐��̗��p
    #include <time.h>//srand�֐��̗��p

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

    };//�n�}�𐶐�����t�B�[���h
    int x;
    int y;
    int r;

    srand((unsigned)time(NULL));//�v���O�������s�l���ɗ�������������
    /*
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
    }//�����܂ŕǂ𐶐�����
    */
                            
    filed[0][1] = 2;

    filed[max_y-1][max_x-2] = 2;

    int gps_x = 1;

    int gps_y = 0;

    filed[gps_y][gps_x] = 2;

    //�E��@����
    
    while(1){

        if(filed[gps_y][gps_x-1] == 1){//���Ɉړ�

            filed[gps_y+1][gps_x] = 2;
            gps_y += 1;
            printf("���Ɉړ�\n");

        }else if(filed[gps_y][gps_x+1] == 0){//�E�Ɉړ�

            filed[gps_y][gps_x+1] = 2;
            gps_x += 1;
            printf("�E�Ɉړ�\n");

        }else if(filed[gps_y][gps_x-1] == 0){//���Ɉړ�

            filed[gps_y][gps_x-1] = 2;
            gps_x -= 1;
            printf("���Ɉړ�\n");

        }else if(filed[gps_y-1][gps_x] == 0){//�E�Ɉړ�

            filed[gps_y-1][gps_x] = 2;
            gps_y -= 1;
            printf("�E�Ɉړ�\n");

        }else if(filed[gps_y+1][gps_x] == 1){//�ǂɌ���

            filed[gps_y][gps_x] = 3;

            printf("�ڂ̑O���ǂ�\n");
            
                if(filed[gps_y-1][gps_x] == 1){//�E��ɕǂ̏ꍇ

                filed[gps_y][gps_x+1] = 2;//�i�s����������

                }else if(filed[gps_y-1][gps_x] == 0){//�E��ɓ��̏ꍇ

                filed[gps_y][gps_x+1] = 2;//�i�s�������E��

                }else { //�܏��H�ɓ������ꍇ
                    printf("�i�s������ύX���悤\n");
                    if(filed[gps_y-1][gps_x] == 2){//�ォ���̏ꍇ



                    }
                }

        }else if(filed[max_y-1][max_x-2] == 2){//�o���ɓ���
            printf("���H�˔j\n");
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
    }//�����܂Œn�}����    
    return 0;
   
}
