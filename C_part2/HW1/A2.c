/* A2.c
 * v0
 * 02.02.25
 *
 * На вход программе подается беззнаковое 32-битное целое число N и
 * натуральное число K (1 ≤ K ≤ 31). Требуется циклически сдвинуть
 * биты числа N вправо на K битов и вывести полученное таким образом
 * число.
 *
 */

#include <stdio.h>
#include <stdint.h>

int rightRotate(uint32_t rotate, uint32_t n)
{
    for(int i=0; i<n; i++)
    {
        if (rotate & 1)
        {
            rotate >>= 1;
            rotate |= 0x80000000;
        }
        else
        {
            rotate >>= 1;
        }
    }
    return rotate;
}

int main ()
{
    int32_t a, rotate, res;

    scanf("%d %d",&rotate, &a);
    res = rightRotate(rotate, a);
    printf("%u", res);

    return 0;

}





/*

int rightRotate(uint32_t n, uint32_t rotate)
{
    return (n >> rotate)|(n << (32 - rotate));
}
int main ()
{
    int32_t a, rotate, res;

    scanf("%d %d",&a, &rotate);
    res = rightRotate(a, rotate);
    printf("%d", res);

    return 0;
}

*/
