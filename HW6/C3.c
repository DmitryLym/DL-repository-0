
/* C3.c
 * v0
 * 02.07.24
 *
 * Написать функцию, которая возвращает среднее арифметическое двух переданных ей аргументов (параметров).
 * int middle(int a, int b)
 * Формат входных данных
 * Два целых не отрицательных числа
 * Формат результата
 * Одно целое число
 *
 */


#include <stdio.h>

int middle(int a, int b );


int main(int argc, char **argv)
{
    int a,b;
    a=b=0;

    scanf("%d %d",&a,&b);             //считывание входных данных

    printf("%d",middle(a,b));

    return 0;
}

int middle (int a, int b)
{
    return ((a+b)/2);
}
