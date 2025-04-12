#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#include "header.h"

//ФУНКЦИЯ пользовательский интерфейс
int Interface(int argc, char *argv[],uint8_t *abscissa,uint8_t *iterations, float *eps1, float *eps2,uint8_t *test1,uint8_t *test2)
{
    int i,rez=0;
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
        while ( (rez = getopt(argc,argv,"hxce:n:ri")) != -1)
        {
            switch (rez) {


            case 'h': // Описание функционала приложения
            {
                printf("found argument \"h = %s\".\n",optarg);
                printf("\n""\n");
                printf("====== HELP ======\n");
                printf("[-h] help\n");
                printf("[-x] Print points of intersection\n");
                printf("[-c] Print number of iterations\n");
                printf("[-e] Calculating with precision [e] the root x of the equation\n");
                printf("[-n] Calculating with precision [n] the value of integral\n");
                printf("[-r] Test root function\n");
                printf("[-i] Test integral function\n");

                break;
            }


            case 'x': // печатаем точки пересечения функций
            {
                printf("found argument \"x = %s\".\n",optarg);
                *abscissa = 1;
                break;
            }


            case 'c': //печатаем количество итераций нахождения корня
            {
                printf("found argument \"c = %s\".\n",optarg);
                *iterations = 1;
                break;
            }


            case 'e': // точность по абциссе для поиска корня
            {
                printf("found argument \"e = %s\".\n",optarg);
                if((optarg[0] == '0') && (optarg[1] == '.'))
                {
                    for (i=2; optarg[i]!='\0'; i++) //переводим в число
                    {
                        if (optarg[i]>='0' && optarg[i]<='9')
                        {

                            *eps1*=10;
                            *eps1+=((int)(optarg[i]-'0'));
                        }
                        else
                        {
                            printf("\n");
                            printf("ERROR FOUND!\n");
                            printf("Invalid parametr e <precision the root x>\n");
                            printf("not a number\n");
                            return -1;

                        }
                    }
                    for (int j=2; j<=i-1; j++)
                    {
                        *eps1/=10;
                    }
                }
                else
                {
                    printf("\n");
                    printf("ERROR FOUND!\n");
                    printf("Invalid parametr e <precision the root x>\n");
                    printf("value of precision must be 0<[e]<1 (0.xxxx)\n");
                    return -1;
                }

                break;
            }


            case 'n': // точность вычисления интеграла
            {
                printf("found argument \"n = %s\".\n",optarg);
                for (i=0; optarg[i]!='\0'; i++) //переводим в число
                {
                    if (optarg[i]>='0' && optarg[i]<='9')
                    {

                        *eps2=*eps2*10+((int)(optarg[i]-'0'));

                    }
                    else
                    {
                        printf("\n");
                        printf("ERROR FOUND!\n");
                        printf("Invalid parametr n <precision of integral>\n");
                        printf("not a number\n");
                        return -1;

                    }
                }


                break;
            }


            case 'r': // проверка функции root
            {
                printf("found argument \"r = %s\".\n",optarg);
                *test1 = 1;
                break;
            }


            case 'i': // проверка функции integral
            {
                printf("found argument \"i = %s\".\n",optarg);
                *test2 = 1;
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
    return 0;
}
