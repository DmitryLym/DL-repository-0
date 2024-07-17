/*
 * E10.c
 * v0
 * 16.07.24
 *
 * Считать массив из 12 элементов и выполнить циклический сдвиг ВПРАВО на 4 элемента.
 * Формат входных данных
 * 12 целых чисел через пробел
 * Формат результата
 * 12 целых чисел через пробел
 *
 */


#include <stdio.h>

enum {SIZE=12,SHIFT=4}; //размер массива и сдвиг
int A[SIZE];

void input(int A[],int SIZE);

void print(int A[],int SIZE);

void shift_r(int A[],int SIZE,int SHIFT);

//=============================================================================================================================

int main(int argc, char **argv)
{

    input(A,SIZE);

    shift_r(A,SIZE,SHIFT);

    print(A,SIZE);

    return 0;
}

//=============================================================================================================================

void input(int A[],int SIZE) //ФУНКЦИЯ ввода массива
{
    for (int i=0; i<SIZE; i++)
        scanf("%d",&A[i]);
}


void print(int A[],int SIZE) //ФУНКЦИЯ печати массива
{
    for (int i=0; i<SIZE; i++)
        printf("%d ",A[i]);
}


void shift_r(int A[],int SIZE,int SHIFT) //ФУНКЦИЯ сдвига вправо на SHIFT
{
    int shift = SHIFT%SIZE; // сдвиг без периодов
    int B[SIZE]; // массив буфер

    for (int i=0; i<=shift-1; i++)
        B[i]=A[SIZE-shift+i];
    for (int i=shift; i<SIZE; i++)
        B[i]=A[i-shift];

    for (int i=0; i<SIZE; i++)
        A[i]=B[i];


}


