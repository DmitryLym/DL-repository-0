
#ifndef header_h  // если header_h не определена
#define header_h  // определяем header_h

#include <stdlib.h>
#include <stdint.h>

//======================================================================
//заданные функции
float f1(float x);
float f2(float x);
float f3(float x);
//первые производные
float df1(float x);
float df2(float x);
float df3(float x);
//вторые производные
float ddf1(float x);
float ddf2(float x);
float ddf3(float x);

//======================================================================
//функции проверки пересечений
float testR1(float x);
float testR2(float x);
//первые производные
float dtestR1(float x);
float dtestR2(float x);
//вторые производные
float ddtestR1(float x);
float ddtestR2(float x);

//======================================================================
//функции проверки интеграла
float testI1(float x);
float testI2(float x);

//======================================================================
typedef float(*function)(float);

//Функция вычисления корней уравнения комбинированным методом <хорд+касательных>
float root(function f,function g,float a, float b, float eps,function df, function ddf,function dg, function ddg, uint8_t iterations);

//Функция вычисления интеграла методом трапеций
float calcIntegralTrap(function f,function g,float a, float b, size_t n);

//Функция пользовательский интерфейс
int Interface(int argc, char *argv[],uint8_t *abscissa,uint8_t *iterations, float *eps1, float *eps2,uint8_t *test1,uint8_t *test2);



#endif    // конец конструкции ifndef
