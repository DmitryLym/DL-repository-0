/*
 * F6.c
 * v0
 * 04.08.24
 *
 * Написать только одну логическую функцию, которая определяет, верно ли, что среди элементов массива есть два одинаковых. Если ответ «да», функция возвращает 1; если ответ «нет», то 0. Строго согласно прототипу:
 * int is_two_same(int size, int a[]);
 * Формат входных данных
 * Массив из целых чисел
 * Формат результата
 * Функция возвращает 1 или 0

*/

/*

#include <stdio.h>

enum {size=101}; //размер массива
int a[size];

void input(int size,int a[]);

void print(int size,int a[]);

int is_two_same(int size,int a[]);

//=============================================================================================================================

int main(int argc, char **argv)
{

    input(size,a);
    //  print(size,a); //отладка

    if (is_two_same(size,a) == 0)
        printf("NO");
    else printf("YES");

    return 0;
}

//=============================================================================================================================

void input(int size,int a[]) //ФУНКЦИЯ ввода массива
{
    for (int i=0; i<size; i++)
        scanf("%d",&a[i]);
}


void print(int size,int a[]) //ФУНКЦИЯ печати массива
{
    for (int i=0; i<size; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

*/

int is_two_same(int size,int a[]) //ФУНКЦИЯ - есть 2 одинаковых?
{
    int same = 0; // флаг 2х одинаковых
    int k =0; //счетчик сравнения
    int t =0; // счетчик проходов
    for (int i=0; i<size-1; i++) // цикл элемента сравниваемого
    {
        t++;
        for (k=t; k<size; k++) // цикл элементов с которыми сравниваем
        {
            // printf("i = %d",i);            //отладка
            // printf(" a_i = %d",a[i]);      //отладка
            // printf(" k = %d",k);           //отладка
            // printf(" a_k = %d\n",a[k]);    //отладка
            if (a[i] == a[k])
            {
                same = 1;
                // printf("same = %d\n",same); //отладка
                // printf("a = %d\n",a[i]);    //отладка
                // printf("i = %d\n",i);       //отладка
                // printf("k = %d\n",k);       //отладка
                break;
            }
        }
        if (same == 1)
        {
            break;
        }
    }
    //  printf(" k_final = %d\n",k); //отладка
    return same;
}


