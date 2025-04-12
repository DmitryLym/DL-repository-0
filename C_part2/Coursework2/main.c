#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#include "header.h"


//**********************************************************************
int main(int argc, char **argv)
{

    uint8_t abscissa =0; //флаг печати точек пересечения
    uint8_t iterations=0; //флаг печати количества итераций на поиск точек пересечений
    float eps1=0; //переменная точность вычисления точек пересечения
    float eps2=0; //переменная точность вычисления интеграла
    uint8_t test1=0; //запуск тестирования поиска точек пересечения
    uint8_t test2=0; //запуск тестирования расчета интеграла
    float points[2] = {-101, -100}; //отрезок поиска корня
    char pause = 0; //просто переменная для паузы в конце работы программы
    float root_1,root_2,root_3 =-777; //точки пересечения (корни уравнения)

    int r = Interface(argc,argv,&abscissa,&iterations,&eps1,&eps2,&test1,&test2); //запуск интерфейса пользователя
    if (r<0) // конец программы,введены неверные данные
    {
        return -1;
    }
    else
    {
        if (test1 ==1) //запуск тестирования функции root
        {
            printf("\n");
            printf("------------------Test root's function----------------------\n");
            printf("Verification by function y=x*x and y=x\n");
            printf("section x= [0.5;1.5] eps = 0.0001 valid root = 1\n");
            float root_0 =-777;
            points[0] = 0.5;
            points[1] = 1.5;
            printf("------------------Root #0--------------------------\n");
            root_0 = root(testR1,testR2,points[0], points[1],0.0001,dtestR1,ddtestR1,dtestR2,ddtestR2,1);
            printf("Root 0  = %f\n", root_0);
            printf("\n");
        }

        if (test2 ==1) //запуск тестирования функции calcIntegralTrap
        {
            printf("\n");
            printf("------------------Test Integral's function------------------\n");
            printf("Verification by function y=1 and y=0\n");
            printf("section x= [0;100] eps = 200 valid value = 100\n");
            float S0=0;
            printf("------------------Integral #0----------------------\n");
            S0=calcIntegralTrap(testI1,testI2,0,100,200);
            printf("S0  = %f\n", S0);
            printf("\n");
        }


        if (eps1 !=0) //проверяем что пользователь задавал переменную
        {
            //Вычисление 1го корня f1-f3
            printf("\n");
            points[0] = -0.5;
            points[1] = -0.1;
            root_1 = root(f1,f3,points[0], points[1],eps1,df1,ddf1,df3,ddf3,iterations);
            if ( abscissa ==1)
            {
                printf("------------------Root #1----------------------\n");
                printf("Root 1  = %f\n", root_1);
            }

            //Вычисление 2го корня f3-f2

            points[0] = -0.3;
            points[1] = -0.1;
            root_2 = root(f3,f2,points[0], points[1],eps1,df3,ddf3,df2,ddf2,iterations);
            if ( abscissa ==1)
            {
                printf("------------------Root #2----------------------\n");
                printf("Root 2  = %f\n", root_2);
            }

            //Вычисление 3го корня f1-f2

            points[0] = 3.5;
            points[1] = 4;
            root_3 = root(f1,f2,points[0], points[1],eps1,df1,ddf1,df2,ddf2,iterations);
            if ( abscissa ==1)
            {
                printf("------------------Root #3----------------------\n");
                printf("Root 3  = %f\n", root_3);

            }
        }

        if (eps1 !=0 && eps2 !=0) //проверяем что пользователь задавал необходимые переменные
        {
            printf("\n\n");
            //Вычисление интеграла f1-f3
            float S1=0;
            printf("------------------Integral #1----------------------\n");
            S1=calcIntegralTrap(f1,f3,root_1,root_2, eps2);
            printf("S1  = %f\n", S1);

            //Вычисление интеграла f1-f2
            float S2=0;
            printf("------------------Integral #2----------------------\n");
            S2=calcIntegralTrap(f1,f2,root_2,root_3, eps2);
            printf("S2  = %f\n", S2);


            printf("\n");
            //Площадь всей фигуры
            printf("------------------TOTAL SQUARE---------------------\n");
            printf("S   = %f\n",S1+S2);
        }
        printf("\nPress \"Enter\" for exit.\n");
        scanf("%c",&pause);

        return 0;
    }
}
