/*
 * B7.c
 * v0
 * 29.06.24
 *
 * Ввести целое число и определить, верно ли, что в нём ровно одна цифра «9».
 * Формат входных данных
 * Одно целое число
 * Формат результата
 * Ответ: YES или NO
 */


#include <stdio.h>

int main(int argc, char **argv)
{
    int IN=0;                 //входные данные
    int n9 = 0;               //выделенная цифра 9

    scanf("%d",&IN);             //считывание входных данных

    while(IN>0)                                //цикл выделения цифр
    {
        if ( (IN%10) == 9)      //если йифра = 9, увеличиваем счетчик 9к
            n9++;
        if (n9>1)               //встретилась ли 2я 9ка ???
        {
            printf("NO");
            break;
        }
        IN /=10;
    }
        if (n9==1)              //встретилась ли 9ка один раз ???
            printf("YES");
        else if (n9 ==0)        //9ток небыло ???
            printf("NO");


    return 0;
}
