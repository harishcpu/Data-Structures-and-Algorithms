#include "Stack.h"

int push(STACK_Sll **top, data_t data)
{
        /* Create a new node */
        STACK_Sll *new = malloc(sizeof(STACK_Sll));
        if (new == NULL)        /* Check if heap overflowed */
                return FAILURE;

        /* put in the data */
        new->data = data;
        new->link = *top;
        /* update top */
         *top = new;
        
         return SUCCESS;
}
