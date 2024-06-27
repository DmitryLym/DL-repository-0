/*
 * A17.c
 * v0
 * 28.06.24
 *
 * Ввести номер месяца и вывести название времени года.
 * Формат входных данных
 * Целое число от 1 до 12 - номер месяца.
 * Формат результата
 * Время года на английском: winter, spring, summer, autumn
 *
 */


#include <stdio.h>

int main(int argc, char **argv)
{
    unsigned short int month_n=0;        //номер месяца

    scanf("%hu",&month_n);               //считывание номера месяца

    if ((month_n <= 2) || (month_n == 12))
        printf("winter");
    else  if ((month_n >= 3) && (month_n <= 5))
        printf("spring");
    else  if ((month_n >= 6) && (month_n <= 8))
        printf("summer");
    else
        printf("autumn");

    return 0;
}

