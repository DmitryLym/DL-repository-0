/*
 * E8.c
 * v0
 * 16.07.24
 *
 * Считать массив из 12 элементов и выполнить инверсию для каждой трети массива.
 * Формат входных данных
 * 12 целых чисел через пробел
 * Формат результата
 * 12 целых чисел через пробел
 *
 */


#include <stdio.h>

enum {SIZE=12}; //размер массива
int A[SIZE];

void input(int A[],int SIZE);

void swap(int *a,int *b);

void m05_reverse(int A[],int SIZE);


//=============================================================================================================================

int main(int argc, char **argv)
{

    input(A,SIZE);

    m05_reverse(A,SIZE);

    return 0;
}

//=============================================================================================================================

void input(int A[],int SIZE) //ФУНКЦИЯ ввода массива
{
    for (int i=0; i<SIZE; i++)
        scanf("%d",&A[i]);
}



void swap(int *a,int *b) //ФУНКЦИЯ перестановки
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}


void m05_reverse(int A[],int SIZE) //ФУНКЦИЯ - перестановки и печати каждой 1/3 массива в одном цикле
{

    for (int i=0; i<SIZE; i++)
    {
        if (i>=0 && i<=SIZE/3/2-1)
            swap(&A[i],&A[SIZE/3-1-i]);

        if (i>=SIZE/3 && i<=SIZE/3+SIZE/3/2-1)
            swap(&A[i],&A[SIZE-1-i]);

        if (i>=SIZE/3*2 && i<=SIZE/3*2+SIZE/3/2-1)
            swap(&A[i],&A[SIZE*5/3-1-i]);

        printf("%d ",A[i]);
    }

}


