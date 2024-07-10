/*
 * D10.c
 * v0
 * 08.07.24
 *
 * Дано натуральное число n ≥ 1. Проверьте, является ли оно простым. Программа должна вывести слово YES,
 * если число простое или NO в противном случае. Необходимо составить рекурсивную функцию и использовать ее.
 * int is_prime(int n, int delitel)
 * Формат входных данных
 * Натуральное число
 * Формат результата
 * YES или NO
 *
 */


#include <stdio.h>

void is_prime(int n0,int delitel);
//int n0=0;

int main(int argc, char **argv)
{
    int IN;


    scanf("%d",&IN);
    //  n0=IN;
    is_prime(IN,IN);

    return 0;
}


void is_prime(int n0,int delitel) //ФУНКЦИЯ - число простое?
{
    // printf("%d ",n0); //отладка
    if (n0==1)
        printf("NO");
    else
    {
        if ((delitel-1)==1)
            printf("YES");
        else  if ((n0%(delitel-1))!=0)
        {
            //   printf("%d ""%d\n",(delitel-1),(n0%(delitel-1))); //отладка
            is_prime(n0,delitel-1);
        }
        else
            printf("NO");
    }
}

