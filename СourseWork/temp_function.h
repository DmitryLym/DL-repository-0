
//#pragma once    //(вариант 2 однократное подключение файла)

#ifndef header_h  // если header_h не определена
#define header_h  // определяем header_h

//======================================================================

struct sensorT //описание сртруктуры (обязательна в заголовке)
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
};

//======================================================================

float midMonthT(struct sensorT DATA_T[],unsigned long int NN,uint16_t year,uint8_t month); //среднемесячная температура
int minMonthT(struct sensorT DATA_T[],unsigned long int NN,uint16_t year,uint8_t month); //минимальная температура за месяц
int maxMonthT(struct sensorT DATA_T[],unsigned long int NN,uint16_t year,uint8_t month); //максимальная температура за месяц

float midYearT(struct sensorT DATA_T[],unsigned long int NN,uint16_t year); //среднегодовая
int minYearT(struct sensorT DATA_T[],unsigned long int NN,uint16_t year); //минимальная температура за год
int maxYearT(struct sensorT DATA_T[],unsigned long int NN,uint16_t year); //максимальная температура за год

//======================================================================

int Interface(int argc, char *argv[],char file[],uint16_t *pyear,uint8_t *pmonth,uint8_t *ptable,uint8_t *perr,char *psort); //пользовательский интерфейс

int LoadData(char file[],struct sensorT DATA_T[],unsigned long int *pNN,int Err_DATA[],unsigned long int *pKK); //загрузка данных из файла (с проверкой ошибок)

int SortData(struct sensorT DATA_T[],unsigned long int NN,char sort);//сортировка корректных данных

void cgangeIJ(struct sensorT DATA_T[],unsigned long int i,unsigned long int j); //обмен местами элемента массива типа структура sensorT

void PrintData(struct sensorT DATA_T[],unsigned long int NN,int Err_DATA[],unsigned long int KK,uint16_t year,uint8_t month,uint8_t table,uint8_t err,char sort); //обработка и печать результата

#endif    // конец конструкции ifndef
