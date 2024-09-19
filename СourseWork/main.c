#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

#include "temp_function.h" //мой заголовочный файл


//======================================================================
// MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN
int main(int argc, char **argv)
{
    enum {SIZE=518401}; //кол-во данных
    static struct sensorT DATA_T[SIZE] = {0}; //массив данных датчика температуры
    static int Err_DATA[SIZE] = {0}; //массив индексов ошибок (номера строк в файле данных)

    char file[255]; // имя файла для считывания данных

    uint16_t year = 0; // запрашиваемый год для сортировки
    uint8_t month = 0; // запрашиваемый месяц для сортировки

    uint8_t table = 1; // флаг печати таблицы с данными
    uint8_t err = 1; // флаг печати таблицы с данными

    unsigned long int NN =0; //количество правильных данных
    unsigned long int KK =0; //количество битых данных

    char sort ='0';//тип сортировки

    char pause = 0; //просто переменная для паузы в конце работы программы

    printf("\n");

    int r = Interface(argc,argv,file,&year,&month,&table,&err,&sort);

    if (r < 0) //конец программы - неправильно введены данные
    {
    }
    else
    {
        int ld=LoadData(file,DATA_T,&NN,Err_DATA,&KK);
        if (ld<0) //конец программы - ошибка открытия файла
        {
        }
        else
        {
            SortData(DATA_T,NN,sort);
            PrintData(DATA_T,NN,Err_DATA,KK,year,month,table,err,sort);
        }

    }
    printf("\n");
    printf("Press \"Enter\" for exit.\n");
    scanf("%c",&pause);
    return 0;
}

// MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN
//======================================================================

