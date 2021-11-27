#include "Stack.h"

int peap(STACK_ary *Stack)
{
        /* check if stack is empty */
        if (Stack->top == -1)
                return STACK_EMPTY;
        
        /* if not, print out all th elements in stack */
        int i = Stack->top;
        while (i > -1)
                printf("\t\t\t\t%d\n", Stack->data[i--]);
        return SUCCESS;
}
