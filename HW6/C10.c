
/* C10.c
 * v0
 * 03.07.24
 *
 * Составить функцию, печать всех простых множителей числа. Использовать ее для печати всех простых множителей числа.
 * void print_simple(int n)
 * Формат входных данных
 * Целое положительное число.
 * Формат результата
 * Последовательность всех простых множителей данного числа в порядке возрастания.
 *
 */


#include <stdio.h>

void print_simple(int n);

int main(int argc, char **argv)
{
    int IN;

    scanf("%d",&IN);

    print_simple(IN);

    return 0;
}


void print_simple(int n) // ФУНКЦИЯ печать всех простых множителей числа
{
    if (n!=0)
    {
        int i=2;
        while (i<=1001)
        {
            if ((n%i)==0)
            {
                printf("%d ",i);
                n/=i;
            }
            else i++;
        }
    }
    else
        printf("0");
}

