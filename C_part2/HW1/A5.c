/* A5.c
 * v0
 * 02.02.25
 *
 * На вход программе подается беззнаковое 32-битное целое число N.
 * Требуется найти количество единичных битов в двоичном представлении
 * данного числа.
 *
 */

#include <stdio.h>
#include <stdint.h>

int totalBits(uint32_t number)
{
    int N=0; //кол-во битов
    //    printf("number = %x\n", number);
    for(int i=0; i<32; i++)
    {
        if (number & 0x80000000)
        {
            N++;
        }
        number <<=1;
    }
    return N;
}

int main ()
{
    int32_t number, res;

    scanf("%d",&number);
    res = totalBits(number);
    printf("%d", res);

    return 0;

}





