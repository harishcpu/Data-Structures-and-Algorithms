#include "Sll.h"

int sl_insert_nth(Slist **head, int position, data_t n_data)
{
        /* Check if the list is empty */
        if (*head == NULL)
        {
                return FAILURE;
        }
        /* If not empty */
        int i = 1;
        while ((*head)->link != NULL && i < position-1)
        {
                head = &(*head)->link;
                ++i;
        }

        if ((*head)->link == NULL)
                return POSITION_NOT_FOUND;
        Slist *temp;
        Slist *new = (Slist *)malloc(sizeof(Slist));
        new->data = n_data;

        temp = (*head)->link;
        (*head)->link = new;
        new->link = temp;

        return SUCCESS;
}
