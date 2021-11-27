#include "Sll.h"

int delete_list(Slist **head)
{
        /* Check whether list os empty or not */
        if (*head == NULL)
        {
                /* If empty */
                return FAILURE;
        }

        Slist *temp = NULL;
        /* If non-empty */
        while (*head != NULL)
        {
                temp = *head;
                *head = (*head)->link;
                free(temp);
        }
        *head = NULL;

        return SUCCESS;
}
