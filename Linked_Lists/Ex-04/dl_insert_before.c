#include "Dll.h"

/* dl_insert_before: insert a new node in the list before the given data */
int dl_insert_before(Dlist **head, Dlist **tail, data_t g_data, data_t n_data)
{
        /* Check if list is empty */
        if (*head == NULL)
                return LIST_EMPTY;
	
        Dlist *temp = *head;
        /* If not empty */

        /* If n_data is found */
        /* Create a new node */
        Dlist *new = (Dlist *)malloc(sizeof(Dlist));
	new->data = g_data;
        new->prev = NULL;
        new->next = NULL; 
        
        if (temp->data == n_data)
        {
                new->next = temp;
                temp->prev = new;
                *head = new;
                return SUCCESS;
        }
        while (temp != NULL && temp->data != n_data)
		temp = temp->next;
        /* If the given data is not found */
        if (temp == NULL)
                return DATA_NOT_FOUND;


        temp = temp->prev;

        /* Establish the links */
        Dlist *temp1 = temp->next;
        temp->next = new;
        new->prev = temp;

        new->next = temp1;
        temp1->prev = new;
        return SUCCESS;
}
