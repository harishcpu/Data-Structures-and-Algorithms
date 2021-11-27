#include "Stack.h"

int push(STACK_ary *Stack, data_t data)
{       
        /* check if stack full */
        if (Stack->top == SIZE - 1)
                return STACK_FULL;

        /* if not, push the data onto stack and adjust top */
        Stack->top = Stack->top + 1;
        Stack->data[Stack->top] = data;
        return SUCCESS;
}
