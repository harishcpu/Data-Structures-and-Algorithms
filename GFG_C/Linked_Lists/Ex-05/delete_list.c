/* ------------------------------------------------------------------------------ 
 *   Author         : HARISH
 *   Date           : Mon Jan 28
 *   File           : delete_list.c
 *   Title          : 
 *   Description    : 
 * ---------------------------------------------------------------------------- */
#include "Sll.h"

/* delete_list: deletes all nodes in the list */
int delete_list(Slist **head)
{
        Slist *temp = *head;

        /* Check whether list os empty or not */
        if (*head == NULL)
                return LIST_EMPTY;

        /* If non-empty */
        while (temp != NULL)
        {
                temp = *head = (*head)->link;
                free(*head);
        }
        *head = NULL;
        
        return SUCCESS;
}
