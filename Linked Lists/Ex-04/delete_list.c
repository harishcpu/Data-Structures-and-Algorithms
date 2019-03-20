/*------------------------------------------------------------------------------ 
 *   Author         : HARISH 
 *   Date           : Feb 03
 *   File           : delete_list.c
 *   Title          : Function to delete the entire nodes in the list
 *   Description    : This function deletes all the nodes in existing 
					  double linked list.
 *----------------------------------------------------------------------------*/
#include "Dll.h"

int dl_delete_list(Dlist **head)
{
        /* Check whether list os empty or not */
        if (*head == NULL)
        {
                /* If empty */
                return LIST_EMPTY;
        }
        
        Dlist *temp; 
        /* If non-empty */
        while (*head != NULL)
        {
                temp = *head;
                *head = (*head)->next;
                free(temp);
//                printf("free ");
        }
        *head = NULL;
        
        return SUCCESS;
}
