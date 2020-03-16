    #include <stdio.h>
    #include <stdbool.h>

    #define N 7 /* �n�_�̐� */

    int main()
    {
    
    int Distance[N][N]={
        {0,2,8,4,-1,-1,-1},
        {2,0,-1,-1,3,-1,-1},
        {8,-1,0,-1,2,3,-1},
        {4,-1,-1,0,-1,8,-1},
        {-1,3,2,-1,0,-1,9},
        {-1,-1,3,8,-1,0,3},
        {-1,-1,-1,-1,9,3,0}
    }; /* �n�_�Ԃ̋������i�[����Ă���񎟌��z��Distance[i][j] */
 
    int nPoint = N; /* �n�_�̐� */
    int sp; /* �o���n�̒n�_�ԍ� */
    int dp; /* �ړI�n�̒n�_�ԍ� */
    
    printf("�o���n�̒n�_�ԍ�����͂��Ă������� ==> ");
    scanf("%d",&sp);
    
    printf("�ړI�n�̒n�_�ԍ�����͂��Ă������� ==> ");
    scanf("%d",&dp);
�ő�̏ꍇ�ł��n�_��葽���Ȃ�Ȃ�
    int sRoute[nPoint]; /* �o���n����ړI�n�܂ł̍ŒZ�����̒n�_��ێ�����z��A�v�f�͒n�_��(�ő�̏ꍇ�ł��n�_��葽���Ȃ�Ȃ�) */
   
    int sDist; /* �o���n����ړI�n�܂ł̍ŒZ���� */
    
    int pDist[nPoint]; /* �o���n����e�n�_�܂ł̍ŒZ������ݒ� */
    
    int pRoute[nPoint]; /*�ŒZ�������o�����ۂ̌o�R�n�̒n�_�ԍ�*/
    
    bool pFixed[nPoint]; /* �o���n����e�n�_�܂ł̍ŒZ�������m�肵�Ă��邩�ǂ��������ʂ���*/
    
    int sPoint,i,j,newDist; /*���ɕK�v�ȕϐ�*/
    
    sDist=99999; /* �o���n����ړI�n�܂ł̍ŒZ�����ɏ����l���i�[����i�ύX���Ȃ��Ă悢�j */
    
    for(i=0;i<nPoint;i++){
        sRoute[i]=-1; /* �ŒZ�o�H��̒n�_�̒n�_�ԍ��ɏ����l���i�[���� */
        pDist[i]=99999; /* �o���n����e�n�_�܂ł̍ŒZ�����ɏ����l���i�[���� */
        pFixed[i]=false; /* �e�n�_�̍ŒZ�����̊m���Ԃɏ����l���i�[���� */
    }
    
    pDist[sp]=0;/* �o���n����o���n���̂ւ̍ŒZ������0��ݒ肷�� */
    
    /*�����܂�(4)�A����ȉ���(5)*/

    while(true){ /* �ŒZ�o�H�T�� */

       i=0;

        while(i<nPoint){/* �n�_�ԍ�0~6�܂ŌJ��Ԃ� */

            if(pFixed[i]==0){ /*����0�Ȃ�true�ɂȂ�ŒZ�o�H���ݒ肳��Ă��鎖�ɂȂ�*/
            break; /* �ē����̌J��Ԃ����甲���� */
            }

            i=i+1;

        }
        
        if(i==nPoint){ /* �o���n����S�Ă̒n�_�܂ł̍ŒZ�o�H���m�肵�Ă���� */
        break; /* �ŒZ�o�H�T�������𔲂��� */
        }
        
        for(j=i+1;j<nPoint;j++){ /* �ŒZ���������Z���n�_��T�� */
            if((pFixed[j]==0) && (pDist[j] < pDist[i])){ /**/
            i=j;
            }
        }
        
        sPoint=i;
        
        pFixed[sPoint]=true; /* �o���n����̍ŒZ�������m�肷�� */
        
        for(j=0;j<nPoint;j++){
        if((Distance[sPoint][j]>0) && (pFixed[j]==0)){
            newDist=pDist[sPoint]+Distance[sPoint][j];
            if(newDist<pDist[j]){
            pDist[j]=newDist;
            pRoute[j]=sPoint;
            }
        }
    }
}
    
    sDist=pDist[dp];
    j=0;
    i=dp;
    while(i!=sp){
        sRoute[j]=i;
        i=pRoute[i];
        j=j+1;
    }
    sRoute[j]=sp;
    

        printf("�o���n����ړI�n�܂ł̍ŒZ�o�H\n");
        for(i=j;i>=0;i--){
            printf("%d,",sRoute[i]);
        }
        printf("\n�o���n����ړI�n�܂ł̍ŒZ����sDist = %d",sDist);
    
    return 0;
    }