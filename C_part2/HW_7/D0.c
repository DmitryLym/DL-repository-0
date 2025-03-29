/* D0.c
 * v0
 * 27.03.25
 *
 * Дана строка, состоящая из английских букв и пробелов. В конце строки
 * символ точка. Все слова разделены одним пробелом. Необходимо
 * составить из слов односвязный список и упорядочить по алфавиту.
 * Список необходимо удалить в конце программы. Для сравнение строк
 * можно использовать strcmp. Необходимо использовать данную структуры
 * организации списка.
 * struct list {
 * char word[20];
 * struct list *next;
 * }
 * Необходимо реализовать односвязный список и обслуживающие его функции.
 * add_to_list
 * swap_elements
 * print_list
 * delete_list
*/


#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
    char word[20];
    struct list *next;
} list;

//======================================================================

void swap_elements(list **head) //функция перестановки и сортировки
{
    int keySort=1; // ключ, если =1 значит еще есть что сортировать

    list *a,*b = NULL; //для удовства
    list *buff_1,*buff_2 = NULL; //буфер
    list *previous =NULL; //предыдущий элемент списка, необходимо помнить при перестановке 2х элементов в середине списка

    if ( (*head == NULL) || ((*head)->next == NULL) ) //если список пустой или из одного элемента
    {
        return;
    }

    else
    {

        while(keySort==1)
        {
            keySort=0;

            a=(*head)->next;

            if ( strcmp( (*head)->word,a->word )>0 ) // отдельно сортируем пару с заголовком списка
            {
                keySort=1;


                buff_1=*head;
                buff_2=a;

                ((*head)->next) = (a->next); //важен порядок чтобы не потерять указатель
                (a->next) = (*head);


                *head =buff_2;
                a=buff_1;

            }
            previous=*head;
            b = a->next;

            while((a->next)!= NULL) //сортируем весь остальной список
            {

                if (strcmp(a->word,b->word)>0)
                {
                    keySort=1;

                    buff_1=a;
                    buff_2=b;

                    (previous->next) = b;
                    (a->next) = (b->next);
                    (b->next) = a;

                    a=buff_2;
                    b=buff_1;

                }
                previous=a;
                a=b;
                b = a->next;

            }


        }

    }
}



void add_to_list(list **head) //функция создания списка
{
    int i=0;
    char c=0;


    while(c!='.')
    {
        c=getchar();
        list *new = calloc(1,sizeof(list));
        while(c!=' ' && c!='.')
        {
            new->word[i] = c;
            i++;
            c=getchar();
        }
        // new->word[i+1] = '\0';                                          /////////?????
        i=0;
        if (*head == NULL)
        {
            *head = new;
        }
        else
        {
            list *p =*head;
            while(p->next != NULL)
            {
                p = p->next;
            }
            p->next=new;
        }
    }
}

void printListIteration(list *p) //печать списка
{
    while(p)
    {
        printf("%s ",p->word);
        p = p->next;

    }
    printf("\n");
}

void freeMem(list *p) //освобождение памяти всех страниц списка
{
    list *buff = NULL;

    while(p)
    {
        buff=p;
        p = p->next;
        free(buff);
        buff=NULL; //дополнительно затираем информацию

    }
}

//======================================================================

int main(void)
{
    list* L=NULL;

    add_to_list(&L);

    swap_elements(&L);

    printListIteration(L);

    freeMem(L);

    return 0;
}

