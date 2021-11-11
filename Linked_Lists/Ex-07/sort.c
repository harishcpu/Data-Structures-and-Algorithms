#include "Sll.h"

void link_last(Slist **head, Slist *min)
{
        /* connect nodes at the end each time */
        min->link = NULL;
        if (*head == NULL)
                *head = min;
        else
        {
                Slist *temp = *head;
                /* traverse till last node */
                while (temp->link)
                        temp = temp->link;
                temp->link = min;
        }
}

int sort_by_nodes(Slist **head)
{
        if ((*head)->link == NULL)
                return SUCCESS;

        Slist *temp1, *temp = *head;
        Slist *head2 = NULL;
        Slist *prev, *prev1, *min = *head;
        int count;
        while (temp->link)
        {
                count = 0;
                /* take first and next to first nodes */
                temp1 = temp->link;
                min = temp;
                prev = temp;
                while (temp1)
                {
                        /* compare first node data with next */
                        if (min->data > temp1->data)
                        {
                                prev1 = prev;
                                min = temp1;
                                ++count;
                        }
                        prev = temp1;
                        /* move to the next node */
                        temp1 = temp1->link;
                }

                /* pull out the small node fron list */
                if (count)
                {
                        prev1->link = min->link;
                        temp = *head;
                }
                else
                {
                        *head = (*head)->link;
                        temp = *head;
                }
                /* put it at the end of the new list */
                link_last(&head2, min);
        }
        
        temp = head2;
        while (temp->link)
                temp = temp->link;
        /* put last node at the end */
        temp->link = *head;
        *head = head2;
        return SUCCESS;
}

int sort_by_values(Slist **head)
{
        Slist *temp = *head;
        Slist *temp1;

        int x;
        while (temp)
        {
                temp1 = temp;
                while (temp1)
                {
                        /* comapare the two nodes data */
                        if (temp->data > temp1->data)
                        {
                                /* swap the nodes' data */
                                x = temp->data;
                                temp->data = temp1->data;
                                temp1->data = x;
                        }
                        temp1 = temp1->link;
                }
                temp = temp->link;
        }
        return SUCCESS;
}












//                                printf("\t\t\t\t\"\"%d - %d\"\"\n", min->data, temp1->data);
