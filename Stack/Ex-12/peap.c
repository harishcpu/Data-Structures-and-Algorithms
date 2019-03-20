#include "Stack.h"

int peap(STACK_Sll *top)
{
        /* check if the stack is empty */
        if (top == NULL)
                return STACK_EMPTY;

        /* print all the nodes' data */
        while (top != NULL)
        {
                printf("\t\t\t\t%d\n", top->data);
                top = top->link;
        }
        return SUCCESS;
}
