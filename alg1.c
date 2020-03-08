#include <stdio.h>

int main(void)
{

    int a_list[5] = {0, 2, 6, 3, 5};

    int serch_a = 3; //‚±‚Ì’l‚ğ’T‚·

    int findID = -1; //Œ©‚Â‚©‚Á‚½‚Æ‚«‚Ì”Ô†

    int num = sizeof(a_list) / sizeof(a_list[0]);//”z—ñ‚Ì—v‘f”‚ğŒvZ

    for (int i = 0; i < num; i++){

        printf("%d\n",a_list[i]);

        if (a_list[i] == serch_a){
            findID = i;
            break;
        }
    }
    
    printf("—v‘f”‚Í%d\n", num);
    printf("Œ©‚Â‚©‚Á‚½”Ô†‚Í=%d", findID);

    return 0;
}
