#include "Sll.h"

extern void link_last(Slist **, Slist *);

int sorted_merge(Slist **head, Slist **head1, Slist **head2)
{
        /* Check if any of the lists is empty */
        if (*head1 == NULL && *head2 == NULL)
                return LIST_EMPTY;

        if (*head1 == NULL && *head2 != NULL)
        {
                link_last(head, *head2);
                return SUCCESS;
        }

        if (*head2 == NULL && *head1 != NULL)
        {
                link_last(head, *head1);
                return SUCCESS;
        }
        /* If both lists are not empty, merge them into one */
        Slist *prev = NULL, *prev1 = NULL;
        Slist *temp1 = *head1;
        Slist *temp2 = *head2;

        while (temp1)
        {
                temp2 = *head2;
                while (temp2)
                {
                        if ((temp2)->data <= temp1->data)
                        {
                                if (temp2 == *head2)
                                {
                                        *head2 = temp2->link;
                                        link_last(head, temp2);
                                        temp2 = *head2;
                                        continue;
                                }
                                prev1->link = temp2->link;
                                link_last(head, temp2);
                                temp2 = prev1->link;
                                continue;
                        }
                        prev1 = temp2;
                        temp2 = temp2->link;
                }
                prev = temp1;
                temp1 = temp1->link;
                link_last(head, prev);
        }

        temp2 = *head2;
        while (temp2)
        {
                prev1 = temp2;
                temp2 = temp2->link;
                link_last(head, prev1);
        }
        *head1 = *head2 = NULL;
        print_list(*head);
        return SUCCESS;
}
