/*
 * B6.c
 * v0
 * 28.06.24
 *
 * Ввести целое число и определить, верно ли, что в его записи есть две одинаковые цифры, стоящие рядом.
 * Формат входных данных
 * Одно целое число
 * Формат результата
 * Единственное слов: YES или NO
 */


#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


int main(int argc, char **argv)
{
    int32_t IN=0;                 //входные данные, максимальное значение = +- 2 147 483 647

    int32_t a, b;                 //два рядом стоящих числа, "a" старший разряд
    a=b=0;
    int64_t N = 1000000000;       // 10^9 для выделения старшего разряда (если N int32 то для максималных чисел ошибка)
    int8_t i=0;                   // счетчик цикла, нужен в 2х циклах


    scanf("%"SCNi32,&IN);          //считывание входных данных

    if ((IN>= -10) && (IN<=10)) // если входные даные от -10 до 10, то одинаковых нет
    {
        printf("NO");
    }
    else
    {
        for (i=1; i<=9; i++)                           //цикл для отброски старших нулей
        {
            if (  ((IN % (N*10)) / N) == 0  )           //выкидываем старшие нули
            {
                N /=10;                                 //уменьшаем N на порядок для выделения след разряда
                //printf("%" PRIi64 " ",((IN % (N*10)) / N));  //ОТЛАДКА
                //printf("N=");
                //printf("%" PRIi64 " ",N);
                //printf("i=");
                //printf("%" PRIi8 " \n",i);
            }
            else
            {
                i--;
                break;
            }
        }
        //printf("i =%" PRIi8 " N = %" PRIi64 "\n",i,N); //ОТЛАДКА

        for (; i<=9; i++)          //цикл выделения цифр, старший "a" автоматом = 0;
        {
            b = (IN % (N*10)) / N;  //выделяем 1й не нулевой разряд и сравниваем с "a"
            //printf("%" PRIi32 "\n",b); //ОТЛАДКА
            if (b==a)               // если b=a значит одинаковые 2 цифры подряд - печать и выходим
            {
                printf("YES");
                break;
            }
            else if (N>1)           //проверка условия дошли ли до самого младшего разряда
            {
                N /=10;             //уменьшаем N на порядок для выделения след разряда
                a=b;                //"a" теперь старший, "b" будет след младший
            }
            else printf("NO");

        }
    }

    return 0;
}
