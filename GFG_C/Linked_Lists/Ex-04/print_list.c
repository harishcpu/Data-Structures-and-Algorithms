/* ---------------------------------------------------------------------------- 
 *   Author         : HARISH
 *   Date           : Feb 6
 *   File           : print_list.c
 *   Title          : Function to print datas of all the nodes
 *   Description    : This function prints the data of each node in a list, accepts 
                        a pointer to the first node, returns SUCCESS on success.
 * ---------------------------------------------------------------------------- */
#include "Dll.h"

/* print_list_from_head: prints all the nodes data from head to tail */
void print_list_from_head(Dlist* head)
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
			head = head->next;
		}
                puts(BOLDMAGENTA "tail" RESET);
	}
}

/* print_list_from_tail: prints all the nodes data from tail to head */
void print_list_from_tail(Dlist* tail)
{
        printf("\t\t\t\t");
        /* Check if list is empty */
	if (tail == NULL)
		printf(BOLDRED "Failed" RESET ": Sorry, List is Empty\n");
	else
	{
		printf(BOLDMAGENTA "tail" RESET "->");
                /* traverse and print all the node datas */
		while (tail)
		{
			printf(BOLDGREEN "%d " BOLDBLUE "*" RESET "->", tail->data);
			tail = tail->prev;
		}
                puts(BOLDMAGENTA "head" RESET);
	}
}
