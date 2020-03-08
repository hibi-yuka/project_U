#include <stdio.h>
#include <string.h>


//構造体とは、複数の値をまとめて管理できる
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

    struct Person person = {"〇山",20,0};
    Person2_ per = {"◇川",30,0};
    

    printf("name : %s\n" "age : %d\n" "gender : %d\n",person.name,person.age,person.gender);
    printf("name : %s\n" "age : %d\n" "gender : %d\n",per.name,per.age,per.gender);
    getchar();

}