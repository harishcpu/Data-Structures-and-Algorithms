#include "Stack.h"

int peak(STACK_ary *Stack)
{
        /* check if stack is empty */
        if (Stack->top == -1)
                return STACK_EMPTY;
        /* if not, peak an element which is on top of the stack */
        printf("\t\t\t\t%d\n", Stack->data[Stack->top]);
        return SUCCESS;
}
