/*------------------------------------------------------------------------------ 
 *   Author         : HARISH 
 *   Date           : Feb 03
 *   File           : delete_at_last.c
 *   Title          : Function to delete the node in the begining
 *   Description    : This function deletes the first node of the existing 
		      doubly linked list.  
 *----------------------------------------------------------------------------*/
#include "Dll.h"

int delete_last(Dlist **head, Dlist **tail)
{
        /* if the list is empty */
        if (*head == NULL)
                return LIST_EMPTY;
        /* if the list has only one node */
        if (*head == *tail)
        {
                free (*tail);
                *head = *tail = NULL;
                return SUCCESS;
        }

        /* else free the tail, the prev will be the next tail */
        *tail = (*tail)->prev;
        free((*tail)->next);
        (*tail)->next = NULL;
        return SUCCESS;
}
