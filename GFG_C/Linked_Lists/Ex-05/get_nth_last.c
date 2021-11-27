/* ------------------------------------------------------------------------------ 
 *   Author         : HARISH
 *   Date           : Mon Jan 28
 *   File           : get_nth_last.c
 *   Title          : Find Nth last node from of the list
 *   Description    : This function finds Nth last node from the end of the list
 *                              in a singly linked list.
 * ---------------------------------------------------------------------------- */
#include "Sll.h"

int get_nth_last(Slist *head, int n)
{
#if 1
        Slist *p1, *p2;
        int count = 1;

        /* take two pointers */
        p1 = p2 = head;
        
        /* move p2 n-1 nodes forward */
        while (count <= n - 1 && p2 != NULL)
        {
                p2 = p2->link;
                ++count;
        }
        if (p2 == NULL)
                return FAILURE;

        /* move both p1 and p2 till p2 reaches null */
        while (p2->link != NULL)
        {
                p1 = p1->link;
                p2 = p2->link;
        }
        /* The node where p1 stops is the nth last node */
        printf("\t\t\t" BOLDRED "%d" RESET "\n", p1->data);
        return SUCCESS;



#elif 0
        /*check if list is empty */
        if (head == NULL)
                return LIST_EMPTY;
        /* check if n is at least 1 */
        if (n < 1)
                return FAILURE;

        /* if not empty, find the middle node */
        Slist *slow = head, *fast = head;
        int leftHalf = 1, rightHalf;
        while (fast->link != NULL && fast->link->link != NULL)
        {
                ++leftHalf;
                slow = slow->link;
                fast = fast->link->link;
        }
printf("mid: %d\n", leftHalf); 

        Slist *temp = head;
        if (n > leftHalf)
        {
                if (fast->link == NULL)
                {
                        rightHalf = 2 * leftHalf + 1 - n;
                        printf("fast->link is null");
                }
                else if (fast->link->link == NULL)
                {
                        rightHalf = 2 * leftHalf - n ;
                        printf("fast->link->link is null");
                }

                while (rightHalf != 0)
                {
                        --rightHalf;
                        temp = temp->link;
                }
                printf("\t\t\t" BOLDRED "%d" RESET "\n", temp->data);
                return SUCCESS;
        }
        rightHalf = leftHalf - n;
        while (slow != NULL && rightHalf != 0)
        {
                --rightHalf;
                slow = slow->link;
        }
        printf("\t\t\t" BOLDRED "%d" RESET "\n", slow->data);
        return SUCCESS;
#else
        Slist *temp = head;
        int len = 0;
        /* find length of the list */
        while (temp != NULL)
        {
                ++len;
                temp = temp->link;
        }
        /* check if list has at least n number of nodes */
        if (n > len)
                return FAILURE;

        temp = head;
        /* traverse till the node */
        for (int i = 1; i < len - n + 1; ++i)
                temp = temp->link;
        printf("\t\t\t" BOLDRED "%d" RESET "\n", temp->data);
        return SUCCESS;
#endif
}
