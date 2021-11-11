/*------------------------------------------------------------------------------ 
 *   Author         : HARISH 
 *   Date           : Feb 03
 *   File           : delete_at_first.c
 *   Title          : Function to delete the node in the begining
 *   Description    : This function deletes the first node of the existing 
					  doubly linked list.  
 *----------------------------------------------------------------------------*/
#include "Dll.h"

int delete_first(Dlist **head, Dlist **tail)
{
        /* if list is empty */
        if (*head == NULL)
                return LIST_EMPTY;
        /* if list has only one node */
        if (*head == *tail)
        {
                free(*head);
                *head = *tail = NULL;
                return SUCCESS;
        }

        /* else free the head, next node will be the head */
        *head = (*head)->next;
        free((*head)->prev);
        (*head)->prev = NULL;
        return SUCCESS;
}
