/*
 * A16.c
 * v0
 * 26.06.24
 *
 * Ввести три числа и определить, верно ли, что они вводились в порядке возрастания.
 *
 * Формат входных данных
   Три целых числа
 *
 * Формат результата
   Одно слово YES или NO
 *
 */


#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


int main(int argc, char **argv)
{
    uint16_t a,b,c;                   //входные данные
    a=b=c=0;

    scanf("%"SCNu16"%"SCNu16"%"SCNu16,&a,&b,&c);             //считывание входных данных


    (a<b)   ?   ( (b<c) ? printf("YES") : printf("NO") )   :   printf("NO")  ;

    return 0;
}






