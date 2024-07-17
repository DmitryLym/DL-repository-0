/*
 * E1.c
 * v0
 * 14.07.24
 *
 * Ввести c клавиатуры массив из 5 элементов, найти среднее арифметическое всех элементов массива.
 * Формат входных данных
 * 5 целых не нулевых чисел через пробел
 * Формат результата
 * Одно число в формате "%.3f"
 *
 */


#include <stdio.h>

enum {SIZE=5}; //размер массива

int A[SIZE];

void input(int A[],int SIZE);
float mid(int A[],int SIZE);


int main(int argc, char **argv)
{

    input(A,SIZE);

    printf("%.3f",mid(A,SIZE));


    return 0;
}


void input(int A[],int SIZE) //ФУНКЦИЯ ввода массива
{
    for (int i=0; i<SIZE; i++)
        scanf("%d",&A[i]);
}


float mid(int A[],int SIZE) //ФУНКЦИЯ подсчета среднего
{
    int sum =0;

    for (int i=0; i<SIZE; i++)
    {
        sum+=A[i];
    }
    return ((float)sum)/SIZE;
}
