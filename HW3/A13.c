/*
 * A13.c
 * v0
 * 23.06.24
 * 
 * На вход подается произвольное трехзначное число, напечать произведение цифр  
 * 
 * Формат входных данных
   Трехзначное целое положительное число 
 * 
 * Формат результата
   Одно целое число 
 * 
 */


#include <stdio.h>

int main(int argc, char **argv)
{                                        
	                 
    char STRING[3];                       //входные данные 
    
    scanf("%3s",STRING);                  //считывание входных данных
    printf("%u",((int)STRING[0]-(int)('0')) * ((int)STRING[1]-(int)('0')) * ((int)STRING[2]-(int)('0')));      //вывод
	return 0;
}

