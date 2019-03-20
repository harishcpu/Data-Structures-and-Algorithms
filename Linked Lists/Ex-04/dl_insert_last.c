/* ---------------------------------------------------------------------------- 
 *   Author         : HARISH
 *   Date           : Mon Jan 28
 *   File           : insert_last.c
 *   Title          : Function to insert the new node in the end
 *   Description    : This function inserts a new node at end of the 
                        existing linked list. Returns SUCCESS on success.
 * ---------------------------------------------------------------------------- */
#include "Dll.h"

int insert_last(Dlist **head, Dlist **tail, data_t data)
{
        Dlist *new = malloc(sizeof(Dlist));

        new->data = data;
        new->prev = *tail;
        new->next = NULL;

        if (*head == NULL)
        {
                *head = new;
                *tail = new;
                return SUCCESS;
        }
        (*tail)->next = new;
        *tail = new;
        return SUCCESS;
}
