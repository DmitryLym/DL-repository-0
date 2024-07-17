/*
 * E12.c
 * v0
 * 16.07.24
 *
 * Считать массив из 10 элементов и отсортировать первую половину по возрастанию, а вторую – по убыванию.
 * Формат входных данных
 * 10 целых чисел через пробел
 * Формат результата
 * Исходный массив. Первая часть отсортирована по возрастанию, вторая половина по убыванию.
 *
 */


#include <stdio.h>

enum {SIZE=10}; //размер массива
int A[SIZE];

void input(int A[],int SIZE);

void swap(int *a,int *b);

void sort_updown(int A[],int SIZE);

void print(int A[],int SIZE);

//=============================================================================================================================

int main(int argc, char **argv)
{

    input(A,SIZE);

    sort_updown(A,SIZE);

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


void sort_updown(int A[],int SIZE) //ФУНКЦИЯ - сортировкa половина по возрастании и половина по убыванию
{
    int unsorted =1; // флаг отсортированности массива

    while (unsorted) // сортируем 1ю половину по возрастанию
    {   unsorted =0;
        for (int i=0; i<SIZE/2-1; i++)
        {
            if (A[i+1] < A[i])
            {
                swap(&A[i+1],&A[i]);
                unsorted =1;
            }
        }
    }

    unsorted =1;

    while (unsorted) // сортируем 2ю половину по убыванию
    {   unsorted =0;
        for (int i=SIZE/2; i<SIZE-1; i++)
        {
            if (A[i+1] > A[i])
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
