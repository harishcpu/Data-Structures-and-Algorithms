/* ---------------------------------------------------------------------------- 
 *   Author         : HARISH
 *   Date           : Mon Feb 04
 *   File           : insert_sorted.c
 *   Title          : Function to insert a node in a sorted list
 *   Description    : This function inserts a new node in between the two nodes
 *                    where left node would have smaller data than n_data and 
 *                    right node would have larger data than the n_data.
 *                    This function returns either SUCCESS or FAILURE with resepect to the result. 
 * ---------------------------------------------------------------------------- */
#include "Sll.h"

int insert_sorted(Slist **head, data_t n_data)
{
#if 1        /* Check if list is empty */
        if ((*head) == NULL)
        {
                insert_at_last(head, n_data);
                return SUCCESS;
        }
        /* Create a new node */
        Slist *new = (Slist *)malloc(sizeof(Slist));
        /* Check if malloc returned NULL */
        if (new == NULL)
                return FAILURE;
        /* put in the data */
        new->data = n_data;
        new->link = NULL;

        Slist *temp = *head;
        Slist *temp1 = (*head)->link;
        /* Traverse till you find the right position */
        while (temp != NULL && temp1 != NULL)
        {
                if (n_data >= temp->data && n_data <= temp1->data)
                {
                        temp->link = new;
                        new->link = temp1;
                        return SUCCESS;
                }
                temp = temp->link;
                temp1 = temp->link;
        }
        if (n_data > temp->data)
        {
                temp->link = new;
                new->link = temp1;
                return SUCCESS;
        }
        if (n_data < temp->data)
        {
                //temp->link = new;
                new->link = *head;
                *head = new;
                return SUCCESS;
        }
        free(new);
        return FAILURE;
#else
        Slist *new = (Slist *)malloc(sizeof(Slist));
        new->data = data;
        new->link = NULL;

        if (*head == NULL)
        {
                *head = new;
                return SUCCESS;
        }

        if ((*head)->link == NULL)
        {
                if ((*head)->data > data)
                {
                        *head
                }
        }
#endif
}
