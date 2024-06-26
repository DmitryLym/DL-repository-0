/*
 * A14.c
 * v0
 * 26.06.24
 *
 * Дано трехзначное число, напечатать макисмальную цифру.
 *
 * Формат входных данных
   Целое положительное трехзначное число
 *
 * Формат результата
   Одна цифра
 *
 */


#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


int main(int argc, char **argv)
{
    uint16_t IN  = 0;                 //входные данные
    uint16_t a, b, c;                 //отдельные цифры
    a=b=c=0;
    uint16_t max=0;                   //максимальная цифра

    scanf("%"SCNu16,&IN);             //считывание входных данных

    a=IN/100;
    b=(IN%100)/10;
    c=IN%10;

    // printf("a= %" PRIu16 ", " "b= %" PRIu16 ", "  "c= %" PRIu16 "\n", a ,b, c); // отладка

    (a>b)   ?   ( (a>c) ? (max=a) : (max=c) )   :   ( (b>c) ? (max=b) : (max=c) ) ;


    printf("%" PRIu16,max);                   //вывод

    return 0;
}






