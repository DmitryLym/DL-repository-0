/*
 * F2.c
 * v0
 * 03.08.24
 *
 * Написать только одну функцию, которая ставит в начало массива все четные элементы, а в конец – все нечетные. Не нарушайте порядок следования чисел между собой. Строго согласно прототипу:.
 * void sort_even_odd(int n, int a[])
 * Формат входных данных
 * Функцийя принмате на вход целые числа
 * Формат результата
 * Отсортированный исходный массив

*/
/*
#include <stdio.h>

enum {size=5}; //размер массива  20 5
int a[size];

void input(int size,int a[]);

void sort_even_odd(int size,int a[]);

void print(int size,int a[]);

//=============================================================================================================================

int main(int argc, char **argv)
{

    input(size,a);

    sort_even_odd(size,a);

    print(size,a);

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
        printf("%d ",a[i]);
}


*/
void sort_even_odd(int size,int a[]) //ФУНКЦИЯ - сортировкa в начало массива все четные
{

    int bufer[size];
    int ke=0; //счетчик bufer для четных чисел
    int ko=(size-1);//счетчик bufer для нечетных чисел

    for (int i=0; i<size; i++) // выписываем четные в начало буфера и нечетные в конец
    {
        if (a[i]%2 == 0)
        {
            bufer[ke] = a[i];
            ke++;
        }
        else
        {
            bufer[ko] = a[i];
            ko--;
        }

    }

    for (int i=0; i<ke; i++) //перезаписываем исходный массив четные числа
    {
        a[i] = bufer[i];
    }
    for (int i=ke; i<size; i++) //перезаписываем исходный массив нечетные числа
    {
        a[i] = bufer[size-1+(ke-i)];
    }
}

