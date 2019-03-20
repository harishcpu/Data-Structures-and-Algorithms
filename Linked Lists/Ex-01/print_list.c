/* ---------------------------------------------------------------------------- 
 *   Author         : HARISH
 *   Date           : Mon Jan 28
 *   File           : print_list.c
 *   Title          : Function to print datas of all the nodes
 *   Description    : This function prints the data of each node in a list, accepts 
                        a pointer to the first node, returns SUCCESS on success.
 * ---------------------------------------------------------------------------- */
#include "Sll.h"

void print_list(Slist* head)
{
        printf("\t\t\t\t");
        /* Check if list is empty */
	if (head == NULL)
		printf(BOLDRED "Failed" RESET ": Sorry, List is Empty\n");
	else
	{
		printf(BOLDMAGENTA "head" RESET "->");
                /* traverse and print all the node datas */
		while (head)
		{
			printf(BOLDGREEN "%d " BOLDBLUE "*" RESET "->", head->data);
			head = head->link;
		}
                puts(BOLDRED "NULL" RESET);
	}
}
