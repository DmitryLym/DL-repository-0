
/* D1.c
 * v0
 * 05.07.24
 *
 * Составить рекурсивную функцию, печать всех чисел от 1 до N
 * Формат входных данных
 * Одно натуральное число
 * Формат результата
 * Последовательность чисел от 1 до введенного числа
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


void printN(int N) // ФУНКЦИЯ печати от 1 до N
{
    if (N==1)
        printf("%d ",N);
    else
    {
        printN(N-1);
        printf("%d ",N);
    }
}


