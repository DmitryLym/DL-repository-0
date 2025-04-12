#include <stdio.h>
#include <math.h>

#include "header.h"

//Функция вычисления корней уравнения комбинированным методом <хорд+касательных>
float root(function f,function g,float a, float b, float eps,function df, function ddf,function dg, function ddg, uint8_t iterations )
{
    int stepcount=0; //кол-во шагов для вычисления

    float m(float x)
    {
        return f(x)-g(x);
    }
    float dm(float x)
    {
        return df(x)-dg(x);
    }
    float ddm(float x)
    {
        return ddf(x)-ddg(x);
    }

    while(fabs(a-b) > 2*eps)
    {
        if( m(a)*ddm(a)<0 )
            a = a - (m(a)*(a - b))/(m(a) - m(b));
        else
            a = a - m(a)/dm(a);
        if( m(b)*ddm(b)<0 )
            b = b - (m(b)*(b - a))/(m(b) - m(a));
        else
            b = b - m(b)/dm(b);
        stepcount++;
    }
    if (iterations !=0)
    {
        printf("Find <<combined method search>> root for %d steps\n",stepcount);
    }
    return (a+b)/2;
}




//Функции для тестирования вычисления корней
// корни 0 и 1;
float testR1(float x)
{
    return x*x;
}
float dtestR1(float x)  //1я производная функции
{
    return 2*x;
}
float ddtestR1(float x) //2я производная функции
{
    return 2;
}


float testR2(float x)
{
    return x;
}
float dtestR2(float x)  //1я производная функции
{
    return 1;
}
float ddtestR2(float x) //2я производная функции
{
    return 0;
}
