/* B1.c
 * v0
 * 02.03.25
 *
 * Описана структура данных для хранения информации об использованной памяти:
 * typedef struct list {
 * void *address;
 * size_t size;
 * char comment[64];
 * struct list *next;
 * } list;
 * Требуется реализовать только одну функцию, которая анализирует данный список и возвращает сколько всего памяти используется. Адрес хранится в поле address, поле size - соответствующий размер данного блока. Если список пустой, то функция должна возвращать 0.
 * Прототип функции:
 *
 * size_t totalMemoryUsage(list *head)
 *
 */



size_t totalMemoryUsage(list *head)
{
    size_t memory = 0;

    if (head->address == 0)
    {
        return 0;
    }
    else
    {
        do
        {
            memory += head->size;
            head = head->next;
        }
        while ( head != NULL);
        return memory;
    }
}
