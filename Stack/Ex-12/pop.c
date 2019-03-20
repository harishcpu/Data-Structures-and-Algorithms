#include "Stack.h"

int pop(STACK_Sll **top, data_t *data)
{
        /* check if list is empty */
        if (*top == NULL)
                return STACK_EMPTY;

        STACK_Sll *temp = *top;
        
        /* pop out the data */
        *data = (*top)->data;

        /* update top (move top to prev node)*/
        *top = (*top)->link;

        /* free the top node */
        free(temp);

        return SUCCESS;
}
