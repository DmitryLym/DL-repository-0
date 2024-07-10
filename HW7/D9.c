/*
 * D9.c
 * v0
 * 07.07.24
 *
 * Дано натуральное число N. Вычислите сумму его цифр. Необходимо составить рекурсивную функцию.
 * int sum_digits(int n)
 * Формат входных данных
 * Одно натуральное число.
 * Формат результата
 * Целое число - сумма цифр введенного числа.
 *
 */


#include <stdio.h>

int sum_digits(int n);

int main(int argc, char **argv)
{
    int IN;

    scanf("%d",&IN);

    printf("%d",sum_digits(IN));

    return 0;
}


int sum_digits(int n) //ФУНКЦИЯ суммы цифр
{

    if (n==0) return 0;
    else return (n%10+sum_digits(n/10));

}
