/* ---------------------------------------------------------------------------- 
 *   Author         : HARISH
 *   Date           : Mon Jan 28
 *   File           : sl_insert_after.c
 *   Title          : Function to insert the new node after the given node
 *   Description    : This function inserts a new node after the given node 
 *                      of the existing linked list. Returns SUCCESS on success.
 * ---------------------------------------------------------------------------- */
#include "Sll.h"

/* sl_insert_after: insert a new node in the list after the given data */
int sl_insert_after(Slist *head, data_t g_data, data_t n_data)
{
        /* Check if list is empty */
        if (head == NULL)
                return LIST_EMPTY;
        
        /* If not empty */
        while (head != NULL && head->data != g_data)
                head = head->link;
        /* If the given data is not found */
        if (head == NULL)
                return DATA_NOT_FOUND;
        
        /* If g_data is found */
        Slist *new = (Slist *)malloc(sizeof(Slist));
        new->data = n_data;

        Slist *temp = head->link;
        head->link = new;
        new->link = temp;
        return SUCCESS;
}
