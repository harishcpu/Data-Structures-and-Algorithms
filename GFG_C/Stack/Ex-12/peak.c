#include "Stack.h"

int peak(STACK_Sll *top)
{
        /* check if the stack is empty */
        if (top == NULL)
                return STACK_EMPTY;

        /* print the top data */
        printf("\t\t\t\t%d\n", top->data);

        return SUCCESS;
}
