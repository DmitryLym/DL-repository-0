#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>


#include "temp_function.h" //мой заголовочный файл

//#define DEBUG
#ifdef DEBUG
#define D if(1)
#else
#define D if(0)
#endif


//ФУНКЦИЯ - СРЕД температура за МЕСЯЦ
float midMonthT(struct sensorT DATA_T[],unsigned long int NN,uint16_t year,uint8_t month)
{
    float sum = 0; //температура сумма
    int total = 0; //количество найденных данных для усреднения

    if (month ==0)
    {
        printf("Temperature data for the month was not requested.\n");
        return (-222);
    }
    for (unsigned long int i =0; i < NN; i++)
    {
        if  ((DATA_T[i].year == year  || year==0) && DATA_T[i].month == month)
        {
            sum += DATA_T[i].temperature;
            total++;
        }

    }
    if (total ==0 && month !=0) //ОШИБКА - данные под запрос не найдены
    {
        printf("ERROR FOUND!\n");
        if (year!=0)
        {
            printf("For year = %04d and month = %02d NO data\n",year,month);
        }
        else
        {
            printf("For month = %02d NO data\n",month);
        }
        return (-333);
    }

    return ((float)sum/total);
}

//ФУНКЦИЯ - МИН температура за МЕСЯЦ
int minMonthT(struct sensorT DATA_T[],unsigned long int NN,uint16_t year,uint8_t month)
{

    int min = 333; //начальная установка минимума (нереальное значение)
    int total = 0; //количество найденных данных

    if (month ==0)
    {
        return (-222);
    }

    for (unsigned long int i =0; i < NN; i++)
    {
        if  ((DATA_T[i].year == year  || year==0) && DATA_T[i].month == month)
        {
            if( DATA_T[i].temperature < min)
            {
                min = DATA_T[i].temperature;
            }
            total++;
        }

    }
    if (total ==0) //ОШИБКА - данные под запрос не найдены
    {
        return (-333);
    }

    return (min);
}

//ФУНКЦИЯ - МАКС температура за МЕСЯЦ
int maxMonthT(struct sensorT DATA_T[],unsigned long int NN,uint16_t year,uint8_t month)
{

    int max = -333; //начальная установка максимума (нереальное значение)
    int total = 0; //количество найденных данных

    if (month ==0)
    {

        return (-222);
    }

    for (unsigned long int i =0; i < NN; i++)
    {
        if  ((DATA_T[i].year == year  || year==0) && DATA_T[i].month == month)
        {
            if( DATA_T[i].temperature > max)
            {
                max = DATA_T[i].temperature;
            }
            total++;
        }

    }
    if (total ==0) //ОШИБКА - данные под запрос не найдены
    {
        return (-333);
    }

    return (max);
}

//ФУНКЦИЯ - СРЕД температура за ГОД
float midYearT(struct sensorT DATA_T[],unsigned long int NN,uint16_t year)
{
    float sum = 0; //температура сумма
    int total = 0; //количество найденных данных для усреднения

    for (unsigned long int i =0; i < NN; i++)
    {
        if  (DATA_T[i].year == year || year==0)
        {
            sum += DATA_T[i].temperature;
            total++;
        }

    }
    if (total ==0) //ОШИБКА - данные под запрос не найдены
    {
        printf("ERROR FOUND!\n");
        printf("For year = %04d NO data\n",year);
        return (-333);
    }

    return ((float)sum/total);
}

//ФУНКЦИЯ - МИН температура за ГОД
int minYearT(struct sensorT DATA_T[],unsigned long int NN,uint16_t year)
{

    int min = 333; //начальная установка минимума (нереальное значение)
    int total = 0; //количество найденных данных

    for (unsigned long int i =0; i < NN; i++)
    {
        if  (DATA_T[i].year == year || year==0)
        {
            if( DATA_T[i].temperature < min)
            {
                min = DATA_T[i].temperature;
            }
            total++;
        }

    }
    if (total ==0) //ОШИБКА - данные под запрос не найдены
    {
        return (-333);
    }

    return (min);
}

//ФУНКЦИЯ - МАКС температура за ГОД
int maxYearT(struct sensorT DATA_T[],unsigned long int NN,uint16_t year)
{

    int max = -333; //начальная установка максимума (нереальное значение)
    int total = 0; //количество найденных данных

    for (unsigned long int i =0; i < NN; i++)
    {
        if  (DATA_T[i].year == year || year==0)
        {
            if( DATA_T[i].temperature > max)
            {
                max = DATA_T[i].temperature;
            }
            total++;
        }

    }
    if (total ==0) //ОШИБКА - данные под запрос не найдены
    {
        return (-333);
    }

    return (max);
}


//======================================================================
//======================================================================

//ФУНКЦИЯ пользовательский интерфейс
int Interface(int argc, char *argv[],char file[],uint16_t *pyear,uint8_t *pmonth,uint8_t *ptable,uint8_t *perr,char *psort)
{   //int *pyear - не используется
    int err =-1;//сразу присваиваем код ошибки (сбрасывается только если введено имя файла c данными) т.о. программа продолжает работать только если в запросе указан файл с которого считать данные
    int rez=0;
    int month =0;
    opterr=0;
    if (argc == 1) //если ничего не ввели - конец программы
    {
        printf("\n");
        printf("ERROR FOUND!\n");
        printf("No any parametr!\n");
        printf("Type [-h] for help\n");
        return -1;
    }
    else
    {
        while ( (rez = getopt(argc,argv,"hf:m:tes:")) != -1)
        {
            switch (rez) {
            case 'h': // Описание функционала приложения
            {
                printf("found argument \"h = %s\".\n",optarg);
                printf("\n""\n");
                printf("====== HELP ======\n");
                printf("[-h] help\n");
                printf("[-f][name of file] data from file\n");
                printf("    [name of file] the file containing the data must be in the same folder as the program being run\n");
                printf("[-m][month number] statistics for the specified month\n");
                printf("    [month number] must be a number from 1 to 12\n");
                printf("[-t] canceling the output of the data table\n");
                printf("[-e] canceling the output of error data indexes\n");
                printf("[-s][type of sorting] sorting the correct data\n");
                printf("    [type of sorting] 'd' sorting by date,'t' sorting by temperature\n");

                break;
            }
            case 'f': // входной файл csv для обработки
            {
                printf("found argument \"f = %s\".\n",optarg);
                strcpy(file,optarg);
                err =0;
                break;
            }
            case 'm': //статистика только за указанный месяц
            {
                printf("found argument \"m = %s\".\n",optarg);
                for (int i=0; optarg[i]!='\0'; i++) //переводим в число
                {
                    if (optarg[i]>='0' && optarg[i]<='9')
                    {

                        month*=10;
                        month+=((int)(optarg[i]-'0'));
                    }
                    else
                    {
                        month = -1;
                        break;
                    }

                }

                if (month >=1 && month <=12) //проверка что месяц введен правильно
                {
                    *pmonth = (uint8_t)(month);
                }
                else
                {
                    printf("\n");
                    printf("ERROR FOUND!\n");
                    printf("Invalid value of the variable \"month\"");
                    return -1;
                }

                break;
            }

            case 't': // отмена печати таблицы
            {
                printf("found argument \"t = %s\".\n",optarg);
                *ptable = 0;
                break;
            }

            case 'e': // отмена печати индексов ошибок
            {
                printf("found argument \"e = %s\".\n",optarg);
                *perr = 0;
                break;
            }

            case 's': //сортировка данных без ошибок
            {
                printf("found argument \"s = %s\".\n",optarg);

                if (optarg[0] == 't' || optarg[0]== 'd')
                {
                    *psort = optarg[0];
                }
                else
                {
                    printf("\n");
                    printf("ERROR FOUND!\n");
                    printf("Invalid parametr of key [-s]");
                    printf("Type [-h] for help\n");
                    return -1;
                }

                break;
            }

            case '?':
            {
                printf("\n");
                printf("ERROR FOUND!\n");
                printf("Unknown key! Or key without data!\n");
                printf("Type [-h] for help\n");
                return -1;
                break;
            }

            };
        };
    };
    if (err == -1)
    {
        printf("\n");
        printf("For the program to work correctly, enter the name of the data file!!!\n");
    }
    return err;
}

//ФУНКЦИЯ загрузка данных из файла (с проверкой ошибок)
int LoadData(char file[],struct sensorT DATA_T[],unsigned long int *pNN,int Err_DATA[],unsigned long int *pKK)
{
    struct sensorT data_NULL= {0}; //инициализатор и стерка
    struct sensorT temp_data = data_NULL; // буфер


    unsigned long int i =0; // индекс исходных данных датчика

    unsigned long int j =0; // индекс корректных (очищенных) данных датчика
    unsigned long int k =0; // индекс данных ошибок


    int err =0; // флаг ошибки в данных
    int type=0; // индекс типа данных (год, месяц....температура)
    signed char c =0;
    int minus =1;

    FILE *f;
    f = fopen(file,"r"); // INPUT чтение
    if (f==NULL)
    {
        printf("\n");
        printf("File opening error\n");
        return -1;
    }
    while ( (c=fgetc(f))!=EOF) //считываем весь файл
    {
        if (c == ' ') c='0'; //замена для массива больших данных (в файле вместо нулей пробелы)

        if ((c<'0' || c>'9') &&c!=';'&&c!='\n'&& c!='-'&& c!=EOF) //если попадается символ отличный от числа, знака "-"  ";"  "\n" строка данных битая и вычитываем ее до "\n"
        {
            Err_DATA[k] = i+1;
            k++;
            while ( c != '\n' && c != EOF) // вычитываем неверную строку данных
            {
                c=fgetc(f);
                if (c == ' ') c='0'; //замена для массива больших данных
            }
            err=1; //поднимаем флаг ошибки - данные не следует копировать в основной массив DATA_T
            i++; //увеличиваем индекс исходных данных
        }

        else
        {
            if (c == EOF)  break; //если вычитали строку и наткнулись на коней файла

            while (c != '\n' && c != EOF) // считываем показание датчика (строка, до \n)
            {
                while (c != ';' && c != '\n' && c != EOF ) // считываем данные датчика (данные в строке, разделитель ;)
                {
                    switch (type)
                    {
                    case 0:
                    {
                        temp_data.year = temp_data.year*10 + (uint16_t)(c-'0');
                        break;
                    }
                    case 1:
                    {
                        temp_data.month = temp_data.month*10 + (uint8_t)(c-'0');
                        break;
                    }
                    case 2:
                    {
                        temp_data.day = temp_data.day*10 + (uint8_t)(c-'0');
                        break;
                    }
                    case 3:
                    {
                        temp_data.hour = temp_data.hour*10 + (uint8_t)(c-'0');
                        break;
                    }
                    case 4:
                    {
                        temp_data.minute = temp_data.minute*10 + (uint8_t)(c-'0');
                        break;
                    }
                    case 5:
                    {
                        if (c == '-') //обрабатываем отрицательное значение температуры
                        {
                            minus = -1;
                            break;
                        }

                        temp_data.temperature = temp_data.temperature*10 + (int8_t)(c-'0');
                        break;
                    }
                    }
                    c=fgetc(f); //считываем следующий символ в поле данных датчика до ;
                    if (c == ' ') c='0'; //замена для массива больших данных

                    if ((c<'0' || c>'9') &&c!=';'&&c!='\n'&& c!='-'&& c!=EOF) //если попадается символ отличный от числа, знака "-"  ";"  "\n" строка данных битая и вычитываем ее до "\n"
                    {
                        Err_DATA[k] = i+1;
                        k++;
                        while ( c != '\n' && c != EOF) // вычитываем неверную строку данных
                        {
                            c=fgetc(f);
                            if (c == ' ') c='0'; //замена для массива больших данных
                        }
                        err=1; //поднимаем флаг ошибки - данные не следует копировать в основной массив DATA_T
                        i++; //увеличиваем индекс исходных данных
                    }
                }
                if (c == ';')
                {
                    c=fgetc(f); //необходимо пропустить ;
                    if (c == ' ') c='0'; //замена для массива больших данных
                    if ((c<'0' || c>'9') &&c!=';'&&c!='\n'&& c!='-'&& c!=EOF) //если попадается символ отличный от числа, знака "-"  ";"  "\n" строка данных битая и вычитываем ее до "\n"
                    {
                        Err_DATA[k] = i+1;
                        k++;
                        while ( c != '\n' && c != EOF) // вычитываем неверную строку данных
                        {
                            c=fgetc(f);
                            if (c == ' ') c='0'; //замена для массива больших данных
                        }
                        err=1; //поднимаем флаг ошибки - данные не следует копировать в основной массив DATA_T
                        i++; //увеличиваем индекс исходных данных
                    }
                }
                type++; //переходим к заполнению следующего параметра датчика
                if (type == 6) //если = 6 значит пробежали все данные строки и можно подправить температуру на "-"
                {
                    temp_data.temperature*=minus; //корректируем если температура отрицательная
                }
                minus = 1;
            }

            if (err == 0 ) //данные корректны
            {
                DATA_T[j] = temp_data;
                j++;
            }
            if (err==0) i++; //заполняем следующее показанее датчика
            temp_data = data_NULL; //очищаем буфер
            err=0; //сбрасываем флаг ошибки данных
            type=0;//обнуляем индекс типа данных
        }


    }


    fclose (f);
    //возвращаем данные из функции
    *pNN = j; //кол-во корректных данных
    *pKK = k; //кол-во ошибочных данных

    return 0;

}

//ФУНКЦИЯ сортировки корректных данных
int SortData(struct sensorT DATA_T[],unsigned long int NN,char sort)
{
    int unsorted =1; // флаг отсортированности массива
    switch (sort)
    {
    case '0': // отсутствие сортировки
    {
        return 0;
    }
    case 'd': // сортировка по дате (date)
    {
        while (unsorted) // сортируем по возрастанию даты
        {
            unsorted =0;
            for (unsigned long int i=0; i<NN-1; i++)
            {
                if (DATA_T[i+1].year > DATA_T[i].year)
                {
                    continue;
                }
                if (DATA_T[i+1].year < DATA_T[i].year)
                {
                    cgangeIJ(DATA_T,i+1,i);
                    unsorted =1;
                    continue;
                }
                if (DATA_T[i+1].year == DATA_T[i].year)
                {
                    if (DATA_T[i+1].month > DATA_T[i].month)
                    {
                        continue;
                    }
                    if (DATA_T[i+1].month < DATA_T[i].month)
                    {
                        cgangeIJ(DATA_T,i+1,i);
                        unsorted =1;
                        continue;
                    }
                    if (DATA_T[i+1].month == DATA_T[i].month)
                    {
                        if (DATA_T[i+1].day > DATA_T[i].day)
                        {
                            continue;
                        }
                        if (DATA_T[i+1].day < DATA_T[i].day)
                        {
                            cgangeIJ(DATA_T,i+1,i);
                            unsorted =1;
                            continue;
                        }
                        if (DATA_T[i+1].day == DATA_T[i].day)
                        {
                            if (DATA_T[i+1].minute > DATA_T[i].minute)
                            {
                                continue;
                            }
                            if (DATA_T[i+1].minute < DATA_T[i].minute)
                            {
                                cgangeIJ(DATA_T,i+1,i);
                                unsorted =1;
                                continue;
                            }
                            if (DATA_T[i+1].minute == DATA_T[i].minute)
                            {
                                continue;
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }

    case 't': // сортировка по температуре (temperature)
    {
        while (unsorted) // сортируем по возрастанию температуры
        {
            unsorted =0;
            for (unsigned long int i=0; i<NN-1; i++)
            {
                if (DATA_T[i+1].temperature < DATA_T[i].temperature)
                {
                    cgangeIJ(DATA_T,i+1,i);
                    unsorted =1;
                }
            }
        }
        return 0;
    }

    case '?':
    {
        printf("\n");
        printf("ERROR FOUND!\n");
        printf("Invalid parametr of key [-s]");
        printf("Type [-h] for help\n");
        return -1;
    }
    }
}

//ФУНКЦИЯ обмен местами элемента массива типа структура sensorT
void cgangeIJ(struct sensorT DATA_T[],unsigned long int i,unsigned long int j)
{
    struct sensorT temp;
    temp=DATA_T[i];
    DATA_T[i]=DATA_T[j];
    DATA_T[j]=temp;
}

//ФУНКЦИЯ-обработка данных и печать результата
void PrintData(struct sensorT DATA_T[],unsigned long int NN,int Err_DATA[],unsigned long int KK,uint16_t year,uint8_t month,uint8_t table,uint8_t err,char sort)
{
    float midTM =0; //средняя температура за месяц
    int minTM = 0;  //минимальная температура за месяц
    int maxTM = 0;  //максимальная температура за месяц

    float midTY =0; //средняя температура за год
    int minTY = 0;  //средняя температура за год
    int maxTY = 0;  //средняя температура за год


    printf("\n");

    printf("The amount of valid data uploaded = %d  \n",NN);
    printf("The amount of errors = %d  \n",KK);

    printf("\n");





    if (table) // флаг печати таблицы с данными (если пользователь вводит параметр -t то нет вывода данных)
    {
        //печать заголовка таблицы
        printf("TEMPERATURE SENSOR INPUT DATA\n");
        if (sort == 'd')
        {
            printf("(((Data sorted by date)))\n");
        }
        if (sort == 't')
        {
            printf("(((Data sorted by temperature)))\n");
        }
        printf("---------------------------------------------------------- \n");
        printf("DATA N | year | month | day | hour | minute | temperature |\n");
        printf("-------|------|-------|-----|------|--------|-------------|\n");

        //печать данных
        for (unsigned long int i=0; i<NN; i++)
        {
            printf("%6ld | ",i+1);
            printf("%4d | ",DATA_T[i].year);
            printf("%5d | ",DATA_T[i].month);
            printf("%3d | ",DATA_T[i].day);
            printf("%4d | ",DATA_T[i].hour);
            printf("%6d | ",DATA_T[i].minute);
            printf("%7d     |",DATA_T[i].temperature);
            printf("\n");
        }

        printf("\n");
    }
    if (err) // флаг печати индексов битых данных (если пользователь вводит параметр -e то нет вывода)
    {
        //печать индексов данных с ошибками
        printf("ERROR IDEXES\n");
        for (unsigned long int t=0; t<KK ; t++)
            if (Err_DATA[t]>0) printf("%d\n",Err_DATA[t]);

        printf("\n");
    }
    printf("STATISTICS\n");

    //печать годовых данных
    if (year >0)
    {
        printf("asked year = %d ",year);
    }
    midTY = midYearT(DATA_T,NN,year);
    printf("average temperature per year t=%.1f\n",midTY);

    minTY = minYearT(DATA_T,NN,year);
    printf("minimum temperature per year t=%d\n",minTY);

    maxTY = maxYearT(DATA_T,NN,year);
    printf("maximum temperature per year t=%d\n",maxTY);

    printf("\n");


    //печать месячных данных
    if (month >0)
    {
        printf("Asked month = %d\n",month);

        midTM = midMonthT(DATA_T,NN,year,month);
        if (midTM !=-333) //код ошибки когда в файле нет данных за запрошенный месяц (если одна возвращает то и остальные тоже)
        {
            printf("average temperature per month t=%.1f\n",midTM);

            minTM = minMonthT(DATA_T,NN,year,month);
            printf("minimum temperature per month t=%d\n",minTM);

            maxTM = maxMonthT(DATA_T,NN,year,month);
            printf("maximum temperature per month t=%d\n",maxTM);
        }
    }

    printf("\n");
}




