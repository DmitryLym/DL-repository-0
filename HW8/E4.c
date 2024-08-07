/*
 * E4.c
 * v0
 * 15.07.24
 *
 * Считать массив из 10 элементов и найти в нем два максимальных элемента и напечатать их сумму.
 * Формат входных данных
 * 10 целых чисел через пробел.
 * Формат результата
 * Сумма двух максимальных элементов.
 *
 */


#include <stdio.h>

enum {SIZE=10}; //размер массива
int A[SIZE];

void input(int A[],int SIZE);

void max12(int A[], int SIZE, int *p_max1, int *p_max2);

//=============================================================================================================================

int main(int argc, char **argv)
{
    int max1, max2;
    max1 = max2 =0;

    input(A,SIZE);

    max12(A,SIZE, &max1, &max2);

    printf("%d",(max1+max2));

    return 0;
}

//=============================================================================================================================

void input(int A[],int SIZE) //ФУНКЦИЯ ввода массива
{
    for (int i=0; i<SIZE; i++)
        scanf("%d",&A[i]);
}


void max12(int A[], int SIZE, int *p_max1, int *p_max2) //ФУНКЦИЯ поиска макс 1 и макс 2
{
    int f_k; // флаг обозначающий что прошло присвоение большему максимуму и нужно избежать присвоение этого же числа меньшему максимуму
    *p_max2 = *p_max1 = A[0];
    if (A[1]<A[0])*p_max2 = A[1];

    //        printf("i=%d *p_max1 =%d *p_max2 =%d\n",0,*p_max1,*p_max2);
    for (int i=1; i<SIZE; i++)
    {
        //               printf("i=%d ",i);
        if( *p_max1 < A[i] )
        {
            *p_max2 = *p_max1;
            //                       printf("*p_max2 =%d ",*p_max2);
            *p_max1 = A[i];
            f_k=i;
            //                       printf("*p_max1 =%d ",*p_max1);
        }

        if(*p_max2 < A[i] && A[i] <= *p_max1 && f_k!=i )   // f_k!=i - проверяем флаг что при этом i уже произошла запись в больший максимум
        {
            *p_max2 = A[i];
            //                      printf("*p_max2 =%d\n",*p_max2);
        }
    }


}


