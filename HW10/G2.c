/*
 * G2.c
 * v0
 * 11.08.24
 *
 * Считать число N из файла input.txt. Сформировать строку из N символов. N четное число, не превосходящее 26.
 * На четных позициях должны находится четные цифры в порядке возрастания, кроме 0,
 * на нечетных позициях - заглавные буквы в порядке следования в английском алфавите. Результат записать в файл output.txt
 * Формат входных данных
 * Четное N ≤ 26
 * Формат результата
 * Строка из английских букв и цифр
 *
 */


#include <stdio.h>


static char fNameI[] = {"input.txt"}; // имя файла для чтения
static char fNameO[] = {"output.txt"}; // имя файла для записи
char string[27] = {0}; // строковый массив

int readFileNumber(char fNameI[]);
void writeFileString(char fNameO[],char string[]);
void makeString(int number,char string[]);

//=============================================================================================================================

int main(int argc, char **argv)
{
    int number =0;
    number = readFileNumber(fNameI);
    // printf("%d\n",number); //отладка

    makeString(number,string);
    //printf("%s\n",string); //отладка

    writeFileString(fNameO,string);


    return 0;
}

//=============================================================================================================================

int readFileNumber(char fNameI[]) //ФУНКЦИЯ - считываем число из файла
{
    int number =0;
    FILE *f;
    f = fopen(fNameI,"r"); // чтение
    fscanf(f,"%d",&number);
    fclose (f);
    return number;
}


void writeFileString(char fNameO[],char string[]) //ФУНКЦИЯ - записываем строку в файл
{
    FILE *f;
    f = fopen(fNameO,"w"); // запись
    fprintf (f, "%s", string);
    fclose (f);
}


void makeString(int number,char string[]) //ФУНКЦИЯ - формируем строку по правилу
{
    int k = 0; //перебор букв
    int t = 2; //перебор цифр

    for(int i=0; i<number; i+=2) //НЕчетные позиции
    {
        string[i]='A'+k;
        k++;
    }
    for(int i=1; i<number; i+=2) //четные позиции
    {
        if (t%10 == 0)
        {
            t = 2;
            string[i] = t+'0';
        }
        else
        {
            string [i] = t + '0';
        }
        t+=2;
    }

}
