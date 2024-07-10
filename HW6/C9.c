
/* C9.c
 * v0
 * 03.07.24
 *
 * Составить функцию вычисления N!. Использовать ее при вычислении факториала
 * int factorial(int n)
 * Формат входных данных
 * Целое положительное число не больше 20
 * Формат результата
 * Целое положительное число
 *
 */


#include <stdio.h>

unsigned long int fact(int x);

int main(int argc, char **argv)
{
    int IN;

    scanf("%d",&IN);

    printf("%lu",fact(IN));

    return 0;
}


unsigned long int fact(int x) // ФУНКЦИЯ вычисления факториала
{
    unsigned long int out =1;

    if (x==0) return out;

    for (int i=1; i<=x; i++)
        out *= i;

    return out;
}


