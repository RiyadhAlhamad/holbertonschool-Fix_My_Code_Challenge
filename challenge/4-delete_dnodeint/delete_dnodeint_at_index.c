#include "lists.h"
#include <stdlib.h>

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *node;
    unsigned int i = 0;

    if (head == NULL || *head == NULL)
        return (-1);

    node = *head;
    while (node && i < index) {
        node = node->next;
        i++;
    }
    if (node == NULL)
        return (-1);

    if (node->prev)
        node->prev->next = node->next;
    else {
        *head = node->next;
        if (*head)
            (*head)->prev = NULL;
    }

    if (node->next)
        node->next->prev = node->prev;

    free(node);
    return (1);
}
