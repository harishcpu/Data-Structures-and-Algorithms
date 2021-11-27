/* ------------------------------------------------------------------------------ 
 *   Author         : HARISH
 *   Date           : Mon Jan 28
 *   File           : print_list.c
 *   Title          : 
 *   Description    : 
 * ---------------------------------------------------------------------------- */
#include "Sll.h"

void print_list(Slist* head)
{
        printf("\t\t\t\t");
	if (head == NULL)
		printf("List is Empty\n");
	else
	{
		while (head)
		{
			printf(BOLDRED "%d" RESET "->", head->data);
			head = head->link;
		}
                puts(BOLDRED "(nil)" RESET);
	}
}

