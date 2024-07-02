/*
 * C1.c
 * v0
 * 01.07.24
 *
 * Cоставить функцию, модуль числа и привести пример ее использования.
 * Формат входных данных
 * Целое число
 * Формат результата
 * Целое не отрицательное число
 *
*/


#include <stdio.h>

int mod(int);

int main(int argc, char **argv)
{
    int IN =0;           //входные данные

    scanf("%d",&IN);         //считывание данных

    printf("%d",mod(IN));    //вывод результата

    return 0;
}

int mod(int number) //ФУНКЦИЯ модуль числа
{
    if (number <0)
        number *=(-1);

    return number;
}




