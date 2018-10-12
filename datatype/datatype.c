#include<stdio.h>
#include "data.h"

main(int argc, char const *argv[])
{
    // type variable_list;
    int  j, k;
    char   c, ch;
    float  f, salary;
    double d;

    extern int i; // 声明，不是定义，不分配内存，为了编译继续

    i = 20; // 声明，也是定义，分配内存

    // C 中有两种类型的表达式：

    // 左值（lvalue）：指向内存位置的表达式被称为左值（lvalue）表达式。左值可以出现在赋值号的左边或右边。
    // 右值（rvalue）：术语右值（rvalue）指的是存储在内存中某些地址的数值。右值是不能对其进行赋值的表达式，也就是说，右值可以出现在赋值号的右边，但不能出现在赋值号的左边。

    char c1 = 94;

    signed char c3 = 94;
    unsigned char c2 = 94;

    printf("%d,%d\n",c1,c2);
    printf("%c,%c\n",c1,c2);

    if( c1 == c2 ){
        printf("==\n");
    }


    // 指针
    int * p;
    int p_vale = 1;

    p = &p_vale;

    // 数组
    int arr[10];


    return 0;
}
