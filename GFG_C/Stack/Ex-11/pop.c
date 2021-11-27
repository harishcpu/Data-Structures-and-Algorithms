#include "Stack.h"

int pop(STACK_ary *Stack, data_t *data)
{
        /* check id stack is empty */
        if (Stack->top == -1)
                return STACK_EMPTY;

        /* if not, pop out the data and adjust the top */
        *data = Stack->data[Stack->top];
        --Stack->top;
        return SUCCESS;
}
