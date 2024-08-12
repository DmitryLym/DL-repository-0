/*
 * G3.c
 * v0
 * 11.08.24
 *
 * В файле input.txt дана строка из 1000 символов. Показать номера символов, совпадающих с последним символом строки. Результат записать в файл output.txt
 * Формат входных данных
 * Строка не более 1000 символов
 * Формат результата
 * Целые числа через пробел - номера символа, который совпадает с последним символом строки.
 *
 */


#include <stdio.h>


static char fNameI[] = {"input.txt"}; // имя файла для чтения
static char fNameO[] = {"output.txt"}; // имя файла для записи
enum {N=1000}; // длина массива
int repeat[N] = {0}; // строковый массив индексов повторения

int kN =0; // кол-во элементов в массиве индексов после поиска

int readFind(char fNameI[],int repeat[]);
void writeFileRepeat(char fNameO[],int kN,int repeat[]);


//=============================================================================================================================

int main(int argc, char **argv)
{

    kN = readFind(fNameI,repeat);

    //printf("%s\n",repeat); //отладка

    //printf("%d\n",kN); //отладка

    writeFileRepeat(fNameO,kN,repeat);


    return 0;
}

//=============================================================================================================================

int readFind(char fNameI[],int repeat[]) //ФУНКЦИЯ - считываем и ищем повторения
{
    FILE *f;
    f = fopen(fNameI,"r"); // чтение

    long i = 0;
    int i2 =0;
    int k = 0;
    char c = 0;
    char last = 0;
    long NN = 0;

    size_t size = sizeof(char);

    fseek( f, -2*size, SEEK_END );   // считываем последний элемент массива
   //NN =6;


    //printf("%ld\n",NN); //отладка
    fscanf(f,"%c",&last);
 NN = ftell(f); //длина заполненого массива без последнего

    fseek( f, 0, SEEK_SET );   //возвращаемся к началу массива

    while ( ((c=fgetc(f))!=EOF) && i<NN-1) // считываем символы из файла и ищем повторения
    {
        if (c == last)
        {
            repeat[k] = i2;
            k++;
        }
        i++;
        i2++;
    }
    fclose (f);

    return k; // кол-во элементов в массиве индексов после поиска
}


void writeFileRepeat(char fNameO[],int kN,int repeat[]) //ФУНКЦИЯ - записываем результат в файл
{

    FILE *f;
    f = fopen(fNameO,"w"); // запись

    for (int i =0; i<kN; i++)
    {

        if (i<kN-1)
        {
            fprintf(f,"%d ",repeat[i]);
        }
        else
        {
            fprintf(f,"%d",repeat[i]);
        }
    }
    fclose (f);
}
