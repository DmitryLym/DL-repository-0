/*
 * D2.c
 * v0
 * 05.07.24
 *
 * Составить рекурсивную функцию, которая определяет сумму всех чисел от 1 до N
 * Формат входных данных
 * Одно натуральное число
 * Формат результата
 * Сумма чисел от 1 до введенного числа
 *
 */


#include <stdio.h>

int sumN(int N);

int main(int argc, char **argv)
{
    int IN;

    scanf("%d",&IN);

    printf("%d",sumN(IN));

    return 0;
}


int sumN(int N) // ФУНКЦИЯ печати от 1 до N
{
    if (N==1)
        return 1;
    else
        return ( N+sumN(N-1) );
}


