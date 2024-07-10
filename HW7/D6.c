
/* D6.c
 * v0
 * 07.07.24
 *
 * Дана строка заканчивающаяся символом точка '.' Напечатать строку наоборот.
 * Реализуйте рекурсивную функцию, которая считывает и печатает строку наоборот.
 * void reverse_string()
 * Формат входных данных
 * Строка из английских букв и знаков препинания. В конце строки символ точка.
 * Формат результата
 * Исходная строка задом наперед.
 *
 */


#include <stdio.h>

void reverse_string(void);

int main(int argc, char **argv)
{
    reverse_string();

    return 0;
}


void reverse_string(void) // ФУНКЦИЯ печать наоборот
{
    char c = '.';

    while ((c=getchar())!='.')
    {
        reverse_string();
        putchar(c);
        break;
    }
}
