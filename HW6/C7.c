
/* C7.c
 * v0
 * 02.07.24
 *
 * Составить функцию, которая переводит число N из десятичной системы счисления в P-ичную систему счисления.
 * Формат входных данных
 * Два целых числа. N ≥ 0 и 2 ≥ P ≥ 9
 * Формат результата
 * Одно целое число
 *
 */


#include <stdio.h>

void Dec_P(int N, int P);

int main(int argc, char **argv)
{
    int N=0;
    int P=0;  //входные данные с клавиатуры

    scanf("%d %d",&N,&P);

    Dec_P(N,P);

    return 0;
}


void  Dec_P(int N, int P) // ФУНКЦИЯ из десятичной системы в Р-ю
{
    char revers[20];
    int i=0;
    if (N!=0) //обработка ~0
    {
        while(N>0)
        {
            revers[i] = (char)( (N%P)+'0' );
            N = N/P;
            i++;
        }
        while ((i-1)>=0)
        {
            printf("%c",revers[i-1]);
            i--;
        }
    }
    else printf("0"); //обработка 0
}
