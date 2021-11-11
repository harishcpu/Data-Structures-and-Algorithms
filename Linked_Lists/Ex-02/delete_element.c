#include "Sll.h"

int delete_element(Slist **head, data_t g_data)
{ 
        /* Check if list is empty */
        if (*head == NULL)
                return LIST_EMPTY;
        
        Slist *temp = NULL, *temp1 = NULL;
        temp = *head;
        /* If not empty */
        while (temp != NULL && temp->data != g_data)
        {
                temp1 = temp;
                temp = temp->link;
        }
        /* If the given data is not found */
        if (temp == NULL)
                return DATA_NOT_FOUND;

        /* If the given data is the first element */
        if (temp1 == NULL) 
        {
                temp1 = temp;
                temp = temp->link;
                free(temp1);
                *head = temp;
            return SUCCESS;
        } /* If given data is the last element */
        else if (temp->link == NULL) 
        {
            temp1->link = NULL;
            free(temp);
            return SUCCESS;
        } /* If it's in middle */
        else
        {
                (temp1)->link = temp->link;
                free(temp);
                return SUCCESS;
        }
}
