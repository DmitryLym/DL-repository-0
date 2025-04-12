
#include "header.h"


//Заданные функции и их производные

//Функция #1
float f1(float x)
{
    return 0.6*x+3;
}
float df1(float x)  //1я производная функции
{
    return 0.6;
}
float ddf1(float x) //2я производная функции
{
    return 0;
}

//Функция #2
float f2(float x)
{
    return (x-2)*(x-2)*(x-2)-1;
}
float df2(float x)
{
    return 3*(x-2)*(x-2);
}
float ddf2(float x)
{
    return 6*(x-2);
}

//Функция #3
float f3(float x)
{
    return 3/x;
}
float df3(float x)
{
    return -3/(x*x);
}
float ddf3(float x)
{
    return 6/(x*x*x);
}
