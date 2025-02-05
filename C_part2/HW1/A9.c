/*
 * A9.c
 * v0
 * 05.02.25
 *
 * В программе реализована структура данных:
 * struct pack_array {
 * uint32_t array; // поле для хранения упакованного массива из 0 и 1
 * uint32_t count0 : 8; // счетчик нулей в array
 * uint32_t count1 : 8; // счетчик единиц в array
 * }
 * Необходимо реализовать программу, которая упаковывает переданный
 * ей массив из 32-ух элементов 0 и 1 в указанную структуру данных.
 * Функция должна строго соответствовать прототипу:
 * void array2struct(int [], struct pack_array *)
 *
 */


#include <stdio.h>
#include <stdint.h>

struct pack_array {
    uint32_t array; // поле для хранения упакованного массива из 0 и 1
    uint32_t count0 : 8; // счетчик нулей в array
    uint32_t count1 : 8; // счетчик единиц в array
} st;

enum {size=32}; //размер массива  32
int a[size];

void input(int size,int a[]);

void array2struct(int [], struct pack_array *);

//=============================================================================================================================

int main(void)
{

    struct pack_array  *ps;
    ps = &st; //указатель на структуру

    input(size,a);

    array2struct(a,ps);

    return 0;
}

//=============================================================================================================================

void input(int size,int a[]) //ФУНКЦИЯ ввода массива
{
    for (int i=0; i<size; i++)
        scanf("%d",&a[i]);
}

void array2struct(int a[], struct pack_array *ps)
{
    for (int i=0; i<=31; i++)
    {
        (ps->array) += a[i]*(1<<(31-i));
        if(a[i])
        {
            (ps->count1)++;
        }
        else
        {
            (ps->count0)++;
        }
    }
    printf("%u %d %d",ps->array,ps->count0,ps->count1);
}
