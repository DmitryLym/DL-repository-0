
/* C2.c
 * v0
 * 02.07.24
 *
 * Составить функцию, возведение числа N в степень P. int power(n, p) и привести пример ее использования.
 * Формат входных данных
 * Два целых числа: N по модулю не превосходящих 1000 и P ≥ 0
 * Формат результата
 * Одно целое число
 *
 */


#include <stdio.h>

long int power(int n, int p );


int main(int argc, char **argv)
{
    int n,p;
    n=p=0;

    scanf("%d %d",&n,&p);             //считывание входных данных

    printf("%ld",power(n,p));

    return 0;
}

long int power (int n, int p)
{
    long int number =1;

    if (p==0) return 1;

    for (int i=1; i<=p; i++)

        number *= n;

    return number;

}
