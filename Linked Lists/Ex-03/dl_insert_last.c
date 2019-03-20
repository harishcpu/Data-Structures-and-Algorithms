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
        /* create a new node */
        Dlist *new = (Dlist *)malloc(sizeof(Dlist));
        if (new == NULL)
        {       /* do the error checking */
                printf("\t\t\t malloc has failed in insert_last\n");
                return FAILURE;
        }
        /* put in the data */
        new->data = data;
        new->prev = *tail;
        new->next = NULL;

        /* if list is empty make new as head and tail */
        if (*head == NULL)
        {
                *head = new;
                *tail = new;
                return SUCCESS;
        }
        /* else update the tail with new */
        (*tail)->next = new;
        *tail = new;
        return SUCCESS;
}
