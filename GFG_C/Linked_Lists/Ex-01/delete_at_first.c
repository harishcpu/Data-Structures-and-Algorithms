/*------------------------------------------------------------------------------ 
 *   Author         : HARISH 
 *   Date           : Feb 03
 *   File           : delete_at_first.c
 *   Title          : Function to delete the node in the begining
 *   Description    : This function deletes the first node of the existing 
					  single linked list.  
 *----------------------------------------------------------------------------*/
#include "Sll.h"

int delete_at_first(Slist **head)
{
    /* Check whether list is empty or not */
    if (*head == NULL)
    {
        /* If Empty */
        return LIST_EMPTY;
    }

    /* If non-empty */
    /* Update head to next node & free the first node */
    Slist *temp = *head;
    (*head) = (*head)->link;
    free(temp);

    return SUCCESS;
}
