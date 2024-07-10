
/*
 * D7.c
 * v0
 * 07.07.24
 *
 * Составить рекурсивную функцию, печать всех чисел от N до 1.
 * Формат входных данных
 * Одно натуральное число
 * Формат результата
 * Последовательность целых чисел от введенного числа до 1, через пробел.
 *
 */


#include <stdio.h>

void printN(int N);

int main(int argc, char **argv)
{
    int IN;

    scanf("%d",&IN);

    printN(IN);

    return 0;
}


void printN(int N) // ФУНКЦИЯ печати от N до 1
{
    if (N==1)
        printf("%d ",N);
    else
    {
        printf("%d ",N);
        printN(N-1);

    }
}


