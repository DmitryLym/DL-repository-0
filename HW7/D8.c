
/*
 * D8.c
 * v0
 * 07.07.24
 *
 * Составить рекурсивную функцию, Выведите все числа от A до B включительно,
 * в порядке возрастания, если A < B, или в порядке убывания в противном случае.
 * Формат входных данных
 * Два целых числа через пробел.
 * Формат результата
 * Последовательность целых чисел.
 *
 */


#include <stdio.h>

void printN(int A,int B);

int main(int argc, char **argv)
{
    int A,B ;
    A=B=0;

    scanf("%d %d",&A,&B);

    printN(A,B);

    return 0;
}


void printN(int A,int B) // ФУНКЦИЯ печати
{

    if(A<B)
    {
        printf("%d ",A);
        A++;
        printN(A,B);
    }
    else if (A>B)
    {
        printf("%d ",A);
        A--;
        printN(A,B);
    }
    else if (A==B)
        printf("%d ",A);

}



