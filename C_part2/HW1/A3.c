/* A3.c
 * v0
 * 02.02.25
 *
 * На вход программе подается беззнаковое 32-битное целое число N и
 * натуральное число K (1 ≤ K ≤ 31). Требуется взять K младших битов
 * числа N и вывести полученное таким образом число.
 *
 */

#include <stdio.h>
#include <stdint.h>

int rightBits(uint32_t number, uint32_t bits)
{
    uint32_t mask = 1;
    for(int i=0; i<bits-1; i++)
    {
        mask <<= 1;
        mask |= 1;
    }
    number &= mask;
    return number;
}

int main ()
{
    int32_t number, bits, res;

    scanf("%d %d",&number, &bits);
    res = rightBits(number, bits);
    printf("%u", res);

    return 0;

}





