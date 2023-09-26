#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 * using the Insertion sort algorithm.
 * @list: Pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *temp;

    if (!list || !*list)
        return;

    current = (*list)->next;
    while (current)
    {
        temp = current;
        current = current->next;

        while (temp && temp->prev && temp->prev->n > temp->n)
        {
            temp->prev->next = temp->next;
            if (temp->next)
                temp->next->prev = temp->prev;

            temp->next = temp->prev;
            temp->prev = temp->next->prev;
            temp->next->prev = temp;

            if (temp->prev)
                temp->prev->next = temp;
            else
                *list = temp;

            print_list(*list);
        }
    }
}
