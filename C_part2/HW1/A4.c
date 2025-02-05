/* A4.c
 * v0
 * 02.02.25
 *
 * На вход программе подается беззнаковое 32-битное целое число N и
 * натуральное число K (1 ≤ K ≤ 31). Требуется взять K подряд идущих
 * битов числа N так, чтобы полученное число было максимальным.
 * Программа должна вывести полученное число.
 *
 */

#include <stdio.h>
#include <stdint.h>

int maxBitsK(uint32_t number, uint32_t bits)
{
    uint32_t mask = 1;
    uint32_t max=0;
    for(int i=0; i<bits-1; i++)
    {
        mask <<= 1;
        mask |= 1;
    }
    //    printf("mask0 = %x\n", mask);
    max = number & mask;
    //    printf("MAX0 = %d\n", max);
    for (int m =1; m<= (32-bits); m++)
    {
        //        printf("m = %d ", m);
        mask <<= 1;
        //        printf("mask = %x\n", mask);
        if (((number & mask)>>(m)) > max)
        {
            max = ((number & mask)>>(m));
        }
    }
    return max;
}

int main ()
{
    int32_t number, bits, res;

    scanf("%d %d",&number, &bits);
    res = maxBitsK(number, bits);
    printf("%u", res);

    return 0;

}





