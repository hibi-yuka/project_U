#include <stdio.h>
#include <string.h>


//�\���̂Ƃ́A�����̒l���܂Ƃ߂ĊǗ��ł���
struct Person{
    char name[50];
    int age;
    char gender;
};

typedef struct Person2{

    char name[40];
    int age;
    char gender;

}Person2_;

int main(void){

    struct Person person = {"�Z�R",20,0};
    Person2_ per = {"����",30,0};
    

    printf("name : %s\n" "age : %d\n" "gender : %d\n",person.name,person.age,person.gender);
    printf("name : %s\n" "age : %d\n" "gender : %d\n",per.name,per.age,per.gender);
    getchar();

}