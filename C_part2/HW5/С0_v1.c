/* C0.c
 * v1
 * 14.03.25
 *
 * Сколько различных трехзначных чисел можно получить из заданного
 * натурального N, вычеркивая цифры из его десятичной записи?
 *
 */

#include <stdio.h>
#include <string.h>



//#define DEBUG
#ifdef DEBUG
#define Deb if(1)
#else
#define Deb if(0)
#endif


#define ENTER 13


int main(int argc, char **argv)
{


    size_t N=0;
    char number[1000] = {0};
    char check[1000] = {0}; //массив в котором отмечается какие 3хзначные чмсла нам встретились при вычеркивании;
    int unicNumber = 0; // кол-во уникальных встретившихся 3хзначных цифр
    int number3x =0;
    scanf("%s",number);

    Deb printf("Input Data = %s\n",number);

    N = strlen(number);

    Deb printf("N = %zu\n",N);


    if (N>=3)
    {

        Deb printf("All Numbers = \n");
        for (size_t i=0; i<=N-3; i++)
        {
            for (size_t j=i+1; j<=N-2; j++)
            {
                for (size_t k=j+1; k<=N-1; k++)
                {
                    number3x = (number[i]-'0')*100+(number[j]-'0')*10+(number[k]-'0')*1;
                    Deb printf("%d\n",number3x);
                    if (number3x>=100) check[number3x]=1;
                }
                Deb printf("\n");
            }
            Deb printf("\n");
        }

        Deb printf("UNIC Numbers = ");
        for (int i=1; i<1000; i++)
        {
            unicNumber += check[i];
        }

        printf("%d\n",unicNumber);
    }
    else
        printf("0");
/*
int n=0;
    for (int i=0; i<1000; i++)
    {
        if (check[i]!=0)
        {
            n++;
            printf("%d) i = %d check = %d\n",n,i,check[i]);
        }
    }

*/
    return 0;
}



