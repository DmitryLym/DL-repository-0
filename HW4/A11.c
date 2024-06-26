/*
 * A11.c
 * v0
 * 26.06.24
 *
 * Напечатать сумму максимума и минимума.
 *
 * Формат входных данных
   Пять целых чисел разделенных пробелом
 *
 * Формат результата
   Одно целое число - сумма максимума и минимума.
 *
 */


#include <stdio.h>


int main(int argc, char **argv)
{
    int IN[5]  = {0,0,0,0,0};       //входные данные
    int max, min;                   //наибольшее и наименьшее
    max=min=0;

    for (int i=0; i<=4; i++)        //считывание входных данных
        scanf("%d",&IN[i]);

    max=min=IN[0];
    for (int i=1; i<=4; i++)
    {
        (max>IN[i]) ? ((min<IN[i]) ? 1 : (min=IN[i])) : (max=IN[i]);

        //printf("step= %d, max = %d, min = %d\n",i,max,min); // отладка
    }
    printf("%d",(max+min));                   //вывод

    return 0;
}





