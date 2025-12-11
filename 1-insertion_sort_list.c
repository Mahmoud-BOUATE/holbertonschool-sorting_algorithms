#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort
 * @list: Double pointer to head of list
 *
 * You must swap NODES (not values).
 * You must print the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *tmp;

if (!list || !*list || !(*list)->next)
return;
current = (*list)->next;

while (current)
{
tmp = current->next;

while (current->prev && current->n < current->prev->n)
{
listint_t *prev = current->prev;

prev->next = current->next;
if (current->next)
current->next->prev = prev;

current->prev = prev->prev;
current->next = prev;

if (prev->prev)
prev->prev->next = current;

prev->prev = current;
if (current->prev == NULL)
*list = current;

print_list(*list);
}

current = tmp;
}
}
