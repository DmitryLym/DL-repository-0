/*
 * E9.c
 * v0
 * 16.07.24
 *
 * Считать массив из 10 элементов и выполнить циклический сдвиг ВПРАВО на 1.
 * Формат входных данных
 * 10 целых чисел через пробел
 * Формат результата
 * 10 целых чисел через пробел сдвинутых вправо на 1 элемент циклически
 *
 */


#include <stdio.h>

enum {SIZE=10}; //размер массива
int A[SIZE];

void input(int A[],int SIZE);

void print(int A[],int SIZE);

void shift_r1(int A[],int SIZE);

//=============================================================================================================================

int main(int argc, char **argv)
{

    input(A,SIZE);

    shift_r1(A,SIZE);

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


void shift_r1(int A[],int SIZE) //ФУНКЦИЯ сдвига вправо на 1
{
    int temp = A[SIZE-1];

    for (int i=SIZE-1; i>0; i--)
        A[i]=A[i-1];

    A[0] = temp;


}


