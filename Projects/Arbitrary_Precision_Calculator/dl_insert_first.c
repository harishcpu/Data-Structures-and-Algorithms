/* ---------------------------------------------------------------------------- 
 *   Author         : HARISH
 *   Date           : Mon Jan 28
 *   File           : insert_first.c
 *   Title          : Function to insert the new node in the begining
 *   Description    : This function inserts a new node at begining of the 
                        existing linked list. Returns SUCCESS on success.
 * ---------------------------------------------------------------------------- */
#include "hahaha.h"

int dl_insert_first(node **head, node **tail, data_t data)
{
        node *new = malloc(sizeof(node));

        new->data = data;
        new->prev = NULL;
        new->next = NULL;

        if (*head == NULL)
        {
                *head = new;
                *tail = new;
                return SUCCESS;
        }
        new->next = *head;
        (*head)->prev = new;
        *head = new;
        return SUCCESS;
}
