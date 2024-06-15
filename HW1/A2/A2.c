/*
 * A2.c
 * v0
 * 15.06.12
 * 
 * Вывести на экран рисунок из букв

     *
    ***
   *****
  *******
   HHOHH
   ZZZZZ

 */


#include <stdio.h>

int main(int argc, char **argv)
{
    char s[][9]= {"   *   ","  ***  "," ***** ","*******"," HHOHH "," ZZZZZ "};
    
    for (int i = 0; i <= 5; i++)
    {
        printf("%7.7s", s[i]);
        printf("\n");
    }   
	return 0;
}

