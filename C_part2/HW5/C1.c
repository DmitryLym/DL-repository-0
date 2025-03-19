/* C1.c
 * v0
 * 15.03.25
 *
 * На стандартном потоке ввода задаются две символьные строки,
 * разделённые символом перевода строки. Каждая из строк не превышает
 * по длине 104. В строках не встречаются пробельные символы.
 *  На стандартный поток вывода напечатайте два числа, разделённых
 * пробелом: первое число — длина наибольшего префикса первойстроки,
 * являющегося суффиксом второй; второе число — наоборот, длина
 * наибольшего суффикса первой строки, являющегося префиксомвторой.
 * Сравнение символов проводите с учётом регистра (т.е. символы 'a'
 * и 'A' различны).
 *
 */

#include <stdio.h>
#include <string.h>



//#define DEBUG
#ifdef DEBUG
#define Deb if(1)
#else
#define Deb if(0)
#endif


#define MAXLEN 1040

char compare(char A[],char B[],size_t M,size_t K);
int  prefSuf(char A[],size_t N,char B[],size_t M);


int main(int argc, char **argv)
{
    size_t N,M=0;
    char c;
    char A[MAXLEN+1] = {0};
    char B[MAXLEN+1] = {0};


    scanf("%1040s",A);
    A[MAXLEN+1] =  '\0';
    N = strlen(A);
    if(N!=0)
    {
        while((c=getchar())!='\n');
    }

    scanf("%1040s",B);
    B[MAXLEN+1] =  '\0';
    M = strlen(B);
    if(M!=0)
    {
        while((c=getchar())!='\n');
    }

    Deb printf("\n");
    Deb printf("%s\n",A);
    Deb printf("%s\n",B);




    Deb printf("N = %zu\n",N);
    Deb printf("M = %zu\n",M);


    if ((N!=0)&&(M!=0))
    {
        printf("%d %d\n",prefSuf(A,N,B,M),prefSuf(B,M,A,N));
    }

    else if((N==0)||(M==0))
    {
        printf("0 0");
    }

    return 0;
}


//=====================================================================


char compare(char A[],char B[],size_t M,size_t K)
{
    char flag =1;

    for (size_t i = 0; i<=K; i++)
    {
        if (A[i]!=B[M-1-K+i])
        {
            flag=0;
            break;
        }
    }
    return flag;
}

int prefSuf(char A[],size_t N,char B[],size_t M)
{
    int check[MAXLEN] = {0}; //массив совпадений
    int A_in_B=0;
    size_t upLimit;

    if(N<=M)
    {
        upLimit = N;
    }
    else
    {
        upLimit = M;
    }

    for (size_t i = 0; i<=upLimit-1; i++)
    {
        if (compare(A,B,M,i))
        {
            check[i]=1;
        }
    }
    /*
        for (int n=0; n<MAXLEN; n++)
        {
            printf("%d",check[n]);
        }
        printf("\n");
    */
    for (int n=MAXLEN-1; n>=0; n--)
    {
        if (check[n] == 1)
        {
            A_in_B = n+1;
            break;
        }
    }
    return A_in_B;
}
