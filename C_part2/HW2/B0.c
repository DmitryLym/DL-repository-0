/* B0.c
 * v0
 * 01.03.25
 *
 * Описана структура данных
 * typedef struct list {
 * uint64_t address;
 * size_t size;
 * char comment[64];
 * struct list *next;
 * } list;
 * Требуется реализовать только одну функцию, которая в данном списке
 * находит адрес блока памяти занимающий больше всего места.
 * Адрес хранится в поле address, поле size - соответствующий размер
 * данного блока. Если список пустой, то функция должна возвращать 0.
 * Если есть несколько таких блоков, то вернуть адрес любого из них.
 * Прототип функции:

 * uint64_t findMaxBlock(list *head)
 *
 */



uint64_t findMaxBlock(list *head)
{
    size_t maxSize = 0;
    uint64_t maxAddres = 0;

    if (head->address == 0)
    {
        return 0;
    }
    else
    {
        do
        {
            if (head->size > maxSize)
            {
                maxSize = head->size;
                maxAddres = head->address;
            }
            head = head->next;
        }
        while ( head != NULL);
        return maxAddres;
    }
}
