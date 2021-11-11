/* ------------------------------------------------------------------------------ 
 *   Author         : HARISH
 *   Date           : Mon Jan 28
 *   File           : delete_list.c
 *   Title          : Reverse a linked list 
 *   Description    : These functions will reverse a linked list in both 
                      recursive and iterative methods.
 * ---------------------------------------------------------------------------- */
#include "Sll.h"

void reverse_list_iterative(Slist **head)
{
        /* if the list is empty or has only one node */
        if (*head == NULL || (*head)->link == NULL)
                return;

        /* else if has more than one node */
        Slist *curr, *prev, *next;

        prev = NULL;
        curr = *head;
        while (curr != NULL)
        {
                /* make current node's link as next node */
                next = curr->link;
                /* store prev node's address in current node's link */
                curr->link = prev;

                /* update prev node to current node */
                prev = curr;
                /* update current node to next node */
                curr = next;
        }

        /* update head */
        *head = prev;
}

void reverse_list_recursive(Slist **head, Slist *prev, Slist *curr)
{
        /* if last node has found */
        if (curr->link == NULL) 
        {
                /* store prev node's address in curr node's link */
                curr->link = prev;
                /* update head */
                *head = curr;
                return;
        }
        /* move to the next node */
        Slist *next = curr->link;
        /* change the curr node link to point to prev */
        curr->link = prev;
        
        /* send curr node as prev and next node as curr */
        reverse_list_recursive(head, curr, next);
}
