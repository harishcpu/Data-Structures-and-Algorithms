#include "Dll.h"

/* dl_insert_after: insert a new node in the list after the given data */
int dl_insert_after(Dlist **head, Dlist **tail, data_t g_data, data_t n_data)
{
        /* Check if list is empty */
        if (*head == NULL)
                return LIST_EMPTY;

        /* If n_data is found */
        /* Create a new node */
        Dlist *new = (Dlist *)malloc(sizeof(Dlist));
	new->data = g_data;
        new->prev = NULL;
        new->next = NULL; 

        if ((*head)->data == n_data)
        {
                (*head)->next = new;
                new->next = NULL;
                new->prev = *head;
                *tail = new;
                return SUCCESS;
        }
#if 1	
        Dlist *temp = *head;
        /* If not empty */
        while (temp != NULL && temp->data != n_data)
		temp = temp->next;
        /* If the given data is not found */
        if (temp == NULL)
                return DATA_NOT_FOUND;

        /* Establish the links */
        Dlist *temp1 = temp->next;
        temp->next = new;
        new->prev = temp;

        new->next = temp1;
        temp1->prev = new;
        return SUCCESS;
#endif

}
