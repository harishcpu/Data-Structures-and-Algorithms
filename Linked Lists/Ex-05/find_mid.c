/* ------------------------------------------------------------------------------ 
 *   Author         : HARISH
 *   Date           : Mon Jan 28
 *   File           : find_mid.c
 *   Title          : Find the middle node in a list
 *   Description    : This function finds the middle node of a linked list by 
 *                      using two pointers, one is slow ptr, one is fast ptr.
 *                      Returns SUCCESS on success and LIST_EMPTY if so.
 * ---------------------------------------------------------------------------- */
#include "Sll.h"

int find_mid(Slist **head)
{
        /* check if head is list is empty */
        if (*head == NULL)
                return LIST_EMPTY;
        /* if not empty, find the mid using slow and fast pointers*/
        Slist *slow = *head, *fast = *head;
        while (fast->link != NULL && fast->link->link != NULL)
        {
                /* move slow one by one */
                slow = slow->link;
                /* move fast by two nodes each time */
                fast = fast->link->link;
        }
        /* print the middle node's data */
        printf("\t\t\t\t" BOLDRED "%d" RESET "\n", slow->data);
        return SUCCESS;
}
