
/* C6.c
 * v0
 * 02.07.24
 *
 * Необходимо составить функцию, которая определяет, сколько зерен попросил положить
 * на N-ую клетку изобретатель шахмат (на 1-ую – 1 зерно, на 2-ую – 2 зерна, на 3-ю – 4 зерна, …)
 * Формат входных данных
 * Цлое число от 1 до 64
 * Формат результата
 * Одно целое число. Количество зерен на данной клетке.
 *
 */


#include <stdio.h>


unsigned long long int seeds(short N);

int main(int argc, char **argv)
{
    short in=0;   //входные данные с клавиатуры

    scanf("%hd",&in);

    printf("%llu",seeds(in));

    return 0;
}


unsigned long long int seeds(short N) // ФУНКЦИЯ вычисления количества зерен
{
    unsigned long long int y=0;

    for(int i=1; i<=N ; i++)
    {
        if(i==1)
            y = 1;
        else
        {
            y*=2;

        }
    }


    return y;
}
