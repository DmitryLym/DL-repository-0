/* A10.c
 * v0
 * 05.02.25
 *
 * Необходимо реализовать программу, которой на входе передаётся
 * вещественное число в типе float, она возвращает порядок который
 * хранится в поле EXP в виде десятичного целого числа. Функция должна
 * строго соответствовать прототипу
 * int extractExp(float)
 *
 */

#include <stdio.h>
#include <stdint.h>

int extractExp(float);

int main ()

{
    float in; //входные данные

    scanf("%f",&in);

    printf("%d",extractExp(in)) ;

    return 0;

}

int extractExp(float in)
{
    int exp;

    union floatbit {
        float value;
        struct {
            uint32_t mant : 23;
            uint32_t exp : 8;
            uint32_t sign : 1;
        } bit;
            } f;

    f.value = in;

    exp = f.bit.exp;
    return exp;
}
