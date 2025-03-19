/* C2.c
 * v0
 * 19.03.25
 *
 * Необходимо вычислить выражение написанное в обратной польской записи.
 * На вход подается строка состоящая из целых, неотрицательных чисел и
 * арифметических символов. В ответ единственное целое число - результат.
 */

#include <stdio.h>
#include <string.h>



//#define DEBUG
#ifdef DEBUG
#define Deb if(1)
#else
#define Deb if(0)
#endif


#define STACKSIZE 1024



void push(double stack[],int *p_sp,double number);
double pop(double stack[],int *p_sp);

char isDigit(char c);
char isOperator(char c);
double compute(char c,double stack[],int *p_sp);
double comp=0; //промежуточные вычисления
int main(int argc, char **argv)
{
    double stack[STACKSIZE] = {0}; //стек
    double number=0;

    int sp =0;   //указатель стека
    int *p_sp;
    p_sp = &sp;

    char str[2048]; //строка
    char c; //символ строки
    int len = 0; //длина строки входных данных



    scanf("%[^\n]",str);
    len=strlen(str);


    for (int i=0; i<len; i++)
    {
        c=str[i];

        if (isDigit(c))
        {
            while(isDigit(c))
            {
                number = number*10+(c-'0');
                i++;
                c=str[i];
            }
            push(stack,p_sp,number);
            number=0;
            Deb   printf("sp= %d STACK = %f\n",*p_sp,stack[*p_sp-1]);
        }


        if (isOperator(c))
        {
            Deb printf("Operator = %c\n",c);
            comp = compute(c,stack,p_sp);
            Deb printf("comp = %f\n",comp);
            push(stack,p_sp,comp);
            comp=0;
        }
    }

    Deb printf("FINAL\n");
    Deb printf("sp= %d STACK = %f\n",(*p_sp)-1,stack[(*p_sp)-1]);

    printf("%d\n",(int)stack[(*p_sp)-1]);


    return 0;
}


//=====================================================================

char isDigit(char c)
{
    if( (c>='0') && (c<='9') )
    {
        return 1;
    }
    return 0;
}

void push(double stack[],int *p_sp,double number)
{
    stack[*p_sp]=number;
    (*p_sp)++;
}

char isOperator(char c)
{
    if( (c=='+') || (c=='-') || (c=='*') || (c=='/'))
    {
        return 1;
    }
    return 0;
}

double pop(double stack[],int *p_sp)
{
    (*p_sp)--;
    double out = stack[*p_sp];

    return out;
}

double compute(char c,double stack[],int *p_sp)
{
    double a,b =0;
    Deb printf("sp = %d\n",*p_sp);

    b = pop(stack,p_sp);
    Deb printf("b = %f\n",b);
    Deb printf("sp = %d\n",*p_sp);

    a = pop(stack,p_sp);
    Deb printf("a = %f\n",a);
    Deb printf("sp = %d\n",*p_sp);

    switch (c)
    {

    case '+':
    {
        return (a+b);
    }
    case '-':
    {
        return (a-b);
    }
    case '*':
    {
        return (a*b);
    }
    case '/':
    {
        return (a/b);
    }
    default:
    {
        printf("Err func compute");
        return 1;
    }
    }

}



