/*
 * E3.c
 * v0
 * 15.07.24
 *
 * Считать массив из 10 элементов и найти в нем максимальный и минимальный элементы и их номера.
 * Формат входных данных
 * 10 целых чисел через пробел
 * Формат результата
 * 4 целых числа через пробел: номер максимума, максимум, номер минимума, минимум.
 *
 */


#include <stdio.h>

enum {SIZE=10}; //размер массива
int A[SIZE];

void input(int A[],int SIZE);

void maxmin_n_n(int A[], int SIZE, int *p_max, int *p_min, int *p_nmax, int *p_nmin);

//=============================================================================================================================

int main(int argc, char **argv)
{
    int max, min, nmax, nmin;
    max = min = nmax = nmin =0;

    input(A,SIZE);

    maxmin_n_n(A,SIZE, &max, &min, &nmax, &nmin);

    printf("%d %d %d %d",nmax,max,nmin,min);

    return 0;
}

//=============================================================================================================================

void input(int A[],int SIZE) //ФУНКЦИЯ ввода массива
{
    for (int i=0; i<SIZE; i++)
        scanf("%d",&A[i]);
}


void maxmin_n_n(int A[], int SIZE, int *p_max, int *p_min, int *p_nmax, int *p_nmin) //ФУНКЦИЯ поиска макс и мин и их положения
{
    *p_max = *p_min = A[0];
    *p_nmax = *p_nmin = 1;

    for (int i=1; i<SIZE; i++)
    {
        if( *p_max < A[i] )
        {
            *p_max = A[i];
            *p_nmax = (i+1);
        }
        if( *p_min > A[i] )
        {
            *p_min = A[i];
            *p_nmin = (i+1);
        }
    }

}


