/*
 * E2.c
 * v0
 * 14.07.24
 *
 * Ввести c клавиатуры массив из 5 элементов, найти минимальный из них.
 * Формат входных данных
 * 5 целых чисел через пробел
 * Формат результата
 * Одно единственное целое число
 *
 */


#include <stdio.h>

enum {SIZE=5}; //размер массива

int A[SIZE];

void input(int A[],int SIZE);
int min(int A[],int SIZE);


int main(int argc, char **argv)
{

    input(A,SIZE);

    printf("%d",min(A,SIZE));


    return 0;
}


void input(int A[],int SIZE) //ФУНКЦИЯ ввода массива
{
    for (int i=0; i<SIZE; i++)
        scanf("%d",&A[i]);
}


int min(int A[],int SIZE) //ФУНКЦИЯ поиска мин
{
    int m = A[0];

    for (int i=1; i<SIZE; i++)
    {
        if(A[i]< m)
            m=A[i];
    }
    return m;
}
