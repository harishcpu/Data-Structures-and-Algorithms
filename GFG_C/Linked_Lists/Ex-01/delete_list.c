/*------------------------------------------------------------------------------ 
 *   Author         : HARISH 
 *   Date           : Feb 03
 *   File           : delete_list.c
 *   Title          : Function to delete the entire nodes in the list
 *   Description    : This function deletes all the nodes in existing 
					  single linked list.
 *----------------------------------------------------------------------------*/
#include "Sll.h"

int delete_list(Slist **head)
{
        /* Check whether list os empty or not */
        if (*head == NULL)
        {
                /* If empty */
                return LIST_EMPTY;
        }
        
        Slist *temp; 
        /* If non-empty */
        while (*head != NULL)
        {
                temp = *head;
                *head = (*head)->link;
                free(temp);
//                printf("free ");
        }
        *head = NULL;
        
        return SUCCESS;
}
