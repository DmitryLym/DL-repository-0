#include <stdio.h>
#include <stdint.h>
#include <string.h>


#include "temp_api.h" //мой заголовочный файл



//ФУНКЦИЯ - СРЕД температура за МЕСЯЦ
float midMonthT(struct sensorT CityT[],int NN,uint16_t year,uint8_t month)
{
    float sum = 0; //температура сумма
    int total = 0; //количество найденных данных для усреднения

    for (int i =0; i < NN; i++)
    {
        if  (CityT[i].year == year && CityT[i].month == month)
        {
            sum += CityT[i].temperature;
            total++;
        }

    }
    if (total ==0) //ОШИБКА - данные под запрос не найдены
    {
        printf("ERR func midMonthT; For year = %04d and month = %02d NO data\n",year,month);
        return (-333);
    }

    return ((float)sum/total);
}

//ФУНКЦИЯ - МИН температура за МЕСЯЦ
int minMonthT(struct sensorT CityT[],int NN,uint16_t year,uint8_t month)
{

    int min = 333; //начальная установка минимума (нереальное значение)
    int total = 0; //количество найденных данных

    for (int i =0; i < NN; i++)
    {
        if  (CityT[i].year == year && CityT[i].month == month)
        {
            if( CityT[i].temperature < min)
            {
                min = CityT[i].temperature;
            }
            total++;
        }

    }
    if (total ==0) //ОШИБКА - данные под запрос не найдены
    {
        printf("ERR func minMonthT; For year = %04d and month = %02d NO data\n",year,month);
        return (-333);
    }

    return (min);
}

//ФУНКЦИЯ - МАКС температура за МЕСЯЦ
int maxMonthT(struct sensorT CityT[],int NN,uint16_t year,uint8_t month)
{

    int max = -333; //начальная установка максимума (нереальное значение)
    int total = 0; //количество найденных данных

    for (int i =0; i < NN; i++)
    {
        if  (CityT[i].year == year && CityT[i].month == month)
        {
            if( CityT[i].temperature > max)
            {
                max = CityT[i].temperature;
            }
            total++;
        }

    }
    if (total ==0) //ОШИБКА - данные под запрос не найдены
    {
        printf("ERR func maxMonthT; For year = %04d and month = %02d NO data\n",year,month);
        return (-333);
    }

    return (max);
}

//ФУНКЦИЯ - СРЕД температура за ГОД
float midYearT(struct sensorT CityT[],int NN,uint16_t year)
{
    float sum = 0; //температура сумма
    int total = 0; //количество найденных данных для усреднения

    for (int i =0; i < NN; i++)
    {
        if  (CityT[i].year == year)
        {
            sum += CityT[i].temperature;
            total++;
        }

    }
    if (total ==0) //ОШИБКА - данные под запрос не найдены
    {
        printf("ERR func midYearT; For year = %04d NO data\n",year);
        return (-333);
    }

    return ((float)sum/total);
}

//ФУНКЦИЯ - МИН температура за ГОД
int minYearT(struct sensorT CityT[],int NN,uint16_t year)
{

    int min = 333; //начальная установка минимума (нереальное значение)
    int total = 0; //количество найденных данных

    for (int i =0; i < NN; i++)
    {
        if  (CityT[i].year == year)
        {
            if( CityT[i].temperature < min)
            {
                min = CityT[i].temperature;
            }
            total++;
        }

    }
    if (total ==0) //ОШИБКА - данные под запрос не найдены
    {
        printf("ERR func minYearT; For year = %04d NO data\n",year);
        return (-333);
    }

    return (min);
}

//ФУНКЦИЯ - МАКС температура за ГОД
int maxYearT(struct sensorT CityT[],int NN,uint16_t year)
{

    int max = -333; //начальная установка максимума (нереальное значение)
    int total = 0; //количество найденных данных

    for (int i =0; i < NN; i++)
    {
        if  (CityT[i].year == year)
        {
            if( CityT[i].temperature > max)
            {
                max = CityT[i].temperature;
            }
            total++;
        }

    }
    if (total ==0) //ОШИБКА - данные под запрос не найдены
    {
        printf("ERR func maxYearT; For year = %04d NO data\n",year);
        return (-333);
    }

    return (max);
}
