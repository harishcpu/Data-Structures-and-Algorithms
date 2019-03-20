#include "queue.h"

int enqueue(Qlist **front, Qlist **rear, data_t data)
{
        /* Create a new node */
        Qlist *new = (Qlist *)malloc(sizeof(Qlist));
        if (new == NULL)
                return FAILURE;

        /* put in the data */
        new->data = data;
        new->link = NULL;

        if (*rear == NULL && *front == NULL)
        {
                *front = *rear = new;
                return SUCCESS;
        }

        (*rear)->link = new;
        *rear = new;

        return SUCCESS;
}
