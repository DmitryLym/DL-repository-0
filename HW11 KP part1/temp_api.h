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

float midMonthT(struct sensorT CityT[],int NN,uint16_t year,uint8_t month); //среднемесячная температура
int minMonthT(struct sensorT CityT[],int NN,uint16_t year,uint8_t month); //минимальная температура за месяц
int maxMonthT(struct sensorT CityT[],int NN,uint16_t year,uint8_t month); //максимальная температура за месяц

float midYearT(struct sensorT CityT[],int NN,uint16_t year); //среднегодовая
int minYearT(struct sensorT CityT[],int NN,uint16_t year); //минимальная температура за год
int maxYearT(struct sensorT CityT[],int NN,uint16_t year); //максимальная температура за год

#endif    // конец конструкции ifndef
