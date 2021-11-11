/* ---------------------------------------------------------------------------- 
 *   Author         : HARISH
 *   Date           : Mon Jan 28
 *   File           : insert_first.c
 *   Title          : Function to insert the new node in the begining
 *   Description    : This function inserts a new node at begining of the 
                        existing linked list. Returns SUCCESS on success.
 * ---------------------------------------------------------------------------- */
#include "Dll.h"

int insert_first(Dlist **head, Dlist **tail, data_t data)
{
        /* create a new node */
        Dlist *new = malloc(sizeof(Dlist));
        /* put in the data */
        new->data = data;
        new->prev = NULL;
        new->next = NULL;

        /* if list is empty */
        if (*head == NULL)
        {
                /* make new node as the head and tail */
                *head = new;
                *tail = new;
                return SUCCESS;
        }
        /* else put in the address of the head in new's link */
        new->next = *head;
        (*head)->prev = new;
        *head = new;
        return SUCCESS;
}
