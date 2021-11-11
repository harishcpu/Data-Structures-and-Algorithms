#include "Sll.h"

/* sl_insert_before: insert a new node in the list before the given data */
int sl_insert_before(Slist **head, data_t g_data, data_t n_data)
{
        /* Check if list is empty */
        if (*head == NULL)
                return LIST_EMPTY;
        
        Slist *g_node;
        
        Slist *new = (Slist *)malloc(sizeof(Slist));
        new->data = n_data;
        
        if((*head)->data == g_data)
        {
                new->link = *head;
                *head = new;
//                printf("yes");
                return SUCCESS;
        }
        /* If not empty */
        while (*head != NULL && (*head)->data != g_data)
        {
                g_node = *head;
                *head = (*head)->link;
        }
        /* If the given data is not found */
        if (*head == NULL)
                return DATA_NOT_FOUND;

        /* If g_data is found */
        g_node->link = new;
        new->link = *head;
        return SUCCESS;
}
