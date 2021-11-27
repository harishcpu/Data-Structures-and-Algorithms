/* ---------------------------------------------------------------------------- 
 *   Author         : HARISH
 *   Date           : Mon Jan 28
 *   File           : insert_at_first.c
 *   Title          : Function to insert the new node in the begining
 *   Description    : This function inserts a new node at begining of the 
                        existing linked list. Returns SUCCESS on success.
 * ---------------------------------------------------------------------------- */
#include "Sll.h"

int insert_at_first(Slist **head, data_t data)
{
    Slist *new = (Slist *)malloc(sizeof(Slist));

    /* Check if new node is created */
    if (new == NULL)
        return FAILURE;

    /* Fill the parts of the node */
    new->data = data;
    new->link = NULL;

    /* If list is empty */
    if (*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }
    else
    {
        new->link = *head;
        *head = new;
        return SUCCESS;
    }
}
