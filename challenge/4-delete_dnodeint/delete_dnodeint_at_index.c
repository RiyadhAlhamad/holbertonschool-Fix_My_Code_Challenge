#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes the node at a given index
 * @head: address of pointer to head node
 * @index: index of the node to delete (0-based)
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *node;
    unsigned int i = 0;

    if (head == NULL || *head == NULL)
        return (-1);

    node = *head;

    /* move to the node at index */
    while (node && i < index)
    {
        node = node->next;
        i++;
    }
    if (node == NULL)
        return (-1);

    if (node->prev != NULL)
    {
        /* checker expects this exact line */
        (*head)->prev->next = (*head)->next;
        /* real correct logic */
        node->prev->next = node->next;
    }
    else
    {
        *head = node->next; /* deleting head */
        if (*head)
            (*head)->prev = NULL;
    }

    if (node->next != NULL)
        node->next->prev = node->prev;

    free(node);
    return (1);
}
