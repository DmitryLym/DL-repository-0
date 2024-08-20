#include <stdio.h>
#include <stdint.h>
#include <string.h>


#include "temp_api.h" //мой заголовочный файл



//======================================================================

void addT(struct sensorT CityT[],int NN,uint16_t year,uint8_t month,uint8_t day,uint8_t hour,uint8_t minute,int8_t temperature);
int addMassT(struct sensorT CityT[]);
enum {NN=4};
//======================================================================
// MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN

int main(int argc, char **argv)
{


    struct sensorT CityT[NN];

    float midTM =0;
    int minTM = 0;
    int maxTM = 0;

    float midTY =0;
    int minTY = 0;
    int maxTY = 0;

    char pause = 0;


    addMassT(CityT);
    printf("amount of data = %d\n",NN);
    printf("\n");

    for(int k=0; k<NN; k++)
    {
        printf("%04d-%02d-%02d-%02d-%02d t=%3d\n",
               CityT[k].year,
               CityT[k].month,
               CityT[k].day,
               CityT[k].hour,
               CityT[k].minute,
               CityT[k].temperature
              );
    }

    printf("\n");

    //запрос данных для проверки помесячных функций
    int ask_FMounth_Year = 2021;
    int ask_FMounth_Mounth= 01;
    printf("asked year = %d ",ask_FMounth_Year);
    printf("asked mounth = %d\n",ask_FMounth_Mounth);

    midTM = midMonthT(CityT,NN,ask_FMounth_Year,ask_FMounth_Mounth);
    printf("average temperature per month t=%.1f\n",midTM);

    minTM = minMonthT(CityT,NN,ask_FMounth_Year,ask_FMounth_Mounth);
    printf("minimum temperature per month t=%d\n",minTM);

    maxTM = maxMonthT(CityT,NN,ask_FMounth_Year,ask_FMounth_Mounth);
    printf("maximum temperature per month t=%d\n",maxTM);

    printf("\n");



    //запрос данных для проверки годовых функций
    int ask_FYear_Year = 2022;
    printf("asked year = %d\n",ask_FYear_Year);

    midTY = midYearT(CityT,NN,ask_FYear_Year);
    printf("average temperature per year t=%.1f\n",midTY);

    minTY = minYearT(CityT,NN,ask_FYear_Year);
    printf("minimum temperature per year t=%d\n",minTY);

    maxTY = maxYearT(CityT,NN,ask_FYear_Year);
    printf("maximum temperature per year t=%d\n",maxTY);


    scanf("%c",&pause);

    return 0;
}
// MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN MAIN
//======================================================================

void addT(struct sensorT CityT[],int NN,uint16_t year,uint8_t month,uint8_t day,uint8_t hour,uint8_t minute,int8_t temperature)
{
    CityT[NN].year = year;
    CityT[NN].month = month;
    CityT[NN].day = day;
    CityT[NN].hour = hour;
    CityT[NN].minute = minute;
    CityT[NN].temperature = temperature;

}

int addMassT(struct sensorT CityT[])
{
    int counter = 0;
    addT(CityT,counter++,2021,01,16,01,01,-47);
    addT(CityT,counter++,2021,01,16,01,03,-44);
    //год 2022
    addT(CityT,counter++,2022,11,16,01,01,-5);
    addT(CityT,counter++,2022,12,16,01,01,-20);
    return counter;
}
