#include <stdlib.h>


#include "header.h"


//Функция вычисления интеграла методом трапеций
float calcIntegralTrap(function f,function g,float a, float b, size_t n)
{

    float m(float x)
    {
        return f(x)-g(x);
    }


    float sum = 0;
    float h = (b-a)/n;;
    for(float x=a; x<=b-h; x+=h)
    {
        sum += 0.5*h*(m(x)+m(x+h));

    }
    return sum;
}

//Функции для тестирования вычисления инеграла
float testI1(float x)
{
    return 1;
}
float testI2(float x)
{
    return 0;
}
