/*------------------------------------------------------------------------------ 
 *   Author         : HARISH 
 *   Date           : Feb 03
 *   File           : delete_at_last.c
 *   Title          : Function to delete the node in the end
 *   Description    : This function deletes the last node existing 
					  single linked list.  
 *----------------------------------------------------------------------------*/
#include "Sll.h"

int delete_at_last(Slist **head)
{
    /* Check whether list is empty or not */
    if (*head == NULL)
    {
        /* If empty */
        return LIST_EMPTY;
    }

    /* If non-empty */
    /* If list has only one node */
    if ((*head)->link == NULL)
    {
        free(*head);
        *head = NULL;
        return SUCCESS;
    }

    /* If list has more than one node */
    Slist *temp = *head;
    Slist *temp1 = temp->link;
    while(temp1->link)
    {
        temp = temp1;
        temp1 = temp1->link;
    }
    free(temp1);
    temp->link = NULL;

    return SUCCESS;
}
