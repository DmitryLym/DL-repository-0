/*
 * E7.c
 * v0
 * 16.07.24
 *
 * Считать массив из 10 элементов и выполнить инверсию отдельно для 1-ой и 2-ой половин массива.
 * Необходимо изменить считанный массив и напечатать его одним циклом.
 * Формат входных данных
 * 10 целых элементов массива через пробел.
 * Формат результата
 * 10 целых элементов массива через пробел.
 *
 */


#include <stdio.h>

enum {SIZE=10}; //размер массива
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


void m05_reverse(int A[],int SIZE) //ФУНКЦИЯ - перестановки и печати массива в одном цикле
{

    for (int i=0; i<SIZE; i++)
    {
        if (i>=0 && i<=SIZE/4)
            swap(&A[i],&A[SIZE/2-1-i]);

        if (i>=SIZE/2 && i<=SIZE/2+SIZE/4)
            swap(&A[i],&A[SIZE-1-(i-(SIZE/2))]);

        printf("%d ",A[i]);
    }

}


