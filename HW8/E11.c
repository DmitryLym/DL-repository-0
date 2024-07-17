/*
 * E11.c
 * v0
 * 16.07.24
 *
 * Считать массив из 10 элементов и отсортировать его по последней цифре.
 * Формат входных данных
 * 10 целых чисел через пробел
 * Формат результата
 * Этот же массив отсортированный по последней цифре
 *
 */


#include <stdio.h>

enum {SIZE=10}; //размер массива
int A[SIZE];

void input(int A[],int SIZE);

void swap(int *a,int *b);

void sort_last(int A[],int SIZE);

void print(int A[],int SIZE);

//=============================================================================================================================

int main(int argc, char **argv)
{

    input(A,SIZE);

    sort_last(A,SIZE);

    print(A,SIZE);

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


void sort_last(int A[],int SIZE) //ФУНКЦИЯ - сортировке по последней цифре
{
    int unsorted =1; // флаг отсортированности массива

    while (unsorted)
    {   unsorted =0;
        for (int i=0; i<SIZE-1; i++)
        {
            if (A[i+1]%10 < A[i]%10)
            {
                swap(&A[i+1],&A[i]);
                unsorted =1;
            }
        }
    }
}
void print(int A[],int SIZE) //ФУНКЦИЯ печати массива
{
    for (int i=0; i<SIZE; i++)
        printf("%d ",A[i]);
}
