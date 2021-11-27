/*------------------------------------------------------------------------------ 
 *   Author         : HARISH 
 *   Date           : Feb 4 
 *   File           : insert_at_last.c
 *   Title          : Function to insert the node to the last
 *   Description    : This function inserts the new node at the end of the 
 *                    existing linked list.	
 *----------------------------------------------------------------------------*/
#include "Sll.h"

int insert_at_last(Slist **head, data_t data)
{
    /* Creating the new node */
    Slist *new = (Slist *)malloc(sizeof(Slist));

    /* Check whether new node created or not */
    if (new == NULL)
        return FAILURE;

    /* Fill the data and link parts of the node */
    new->data = data;
    new->link = NULL;

    /* If list is empty */
    if (*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }

    /* If list is non-empty, traverse till the last node */
    Slist *temp = *head;
    while (temp->link)
        temp = temp->link;

    /* Establish link */
    temp->link = new;

    return SUCCESS;
}
