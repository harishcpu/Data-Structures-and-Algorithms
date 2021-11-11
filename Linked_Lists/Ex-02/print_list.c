/*------------------------------------------------------------------------------ 
 *   Author         : Emertxe (https://www.emertxe.com) 
 *   Date           : Mon 20 Mar 2017 9:10:04 IST
 *   File           : print_list.c
 *   Title          : Function to print the list
 *   Description    : This function prints the data in the list by traversing
					  first node to the last node.  
 *----------------------------------------------------------------------------*/
#include "Sll.h"

void print_list(Slist *head)
{
    if (head == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        while (head)
        {
            printf("%d ", head->data);
            head = head->link;
        }
        printf("\n");
    }
}
