/*------------------------------------------------------------------------------ 
 *   Author         : HARISH 
 *   Date           : Feb 03
 *   File           : remove_duplicates.c
 *   Title          : Function to remove the duplicate nodes from a list
 *   Description    : This function deletes the duplicate nodes from the existing
					  single linked list.  
 *----------------------------------------------------------------------------*/
#include "Sll.h"

int remove_duplicates(Slist **head)
{
        /* Check if list is empty */
        if (*head == NULL)
                return LIST_EMPTY;

        Slist *temp1, *temp2, *dup;
        temp1 = *head;

        /* pick elements one by one */
        while (temp1 != NULL && temp1->link != NULL)
        {
                temp2 = temp1;
                /* compare the picked with rest of the elements */
                while (temp2->link != NULL)
                {
                        /* check if duplicate */
                        if (temp1->data == temp2->link->data)
                        {
                                /* If yes, free it */
                                dup = temp2->link;
                                temp2->link = temp2->link->link;
                                free(dup);
                        }
                        else /* move to next node */
                        temp2 = temp2->link;
                }
                /* move to next node */
                temp1 = temp1->link;
        }
        return SUCCESS;
}
