/*------------------------------------------------------------------------------ 
 *   Author         : HARISH 
 *   Date           : Feb 03
 *   File           : find_node.c
 *   Title          : Function to find a node in a given linked list
 *   Description    : This function searches for a node using given data existing
					  single linked list.
                        Returns DATA_FOUND if it found the node, else returns DATA_NOT_FOUND.
 *-----------------------------------------------------------------------------*/
#include "Sll.h"

int find_node(data_t element, Slist *head)
{
        int position = 1;

        /* Check if the list is empty */
        if (head == NULL)
        {
                /* If empty */
                return LIST_EMPTY;
        }
        /* If non-empty */
        while(head != NULL)
        {
                if (head->data == element)
                {
                      //  return DATA_FOUND;
                        return position;
                }
                head = head->link;
                ++position;
        }
        /* If element is not found */
        return DATA_NOT_FOUND;
}
