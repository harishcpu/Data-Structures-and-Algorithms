#include "Sll.h"

int create_loop(Slist **head, int n)
{
        if (*head == NULL)
                return LIST_EMPTY;

        Slist *temp = *head;
        Slist *pick;
        int i = 0;
        while (temp->link)
        {
                if (i == n)
                        pick = temp;
                temp = temp->link;
                ++i;
        }
        temp->link = pick;
        return SUCCESS;
}
