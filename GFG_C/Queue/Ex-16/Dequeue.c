#include "queue.h"

int dequeue(Qlist **front, Qlist **rear, data_t *data)
{
        /* check if Q is empty */
        if (*rear == NULL || *front == NULL)
                return Q_EMPTY;

        /* Get the data */
        *data = (*front)->data;

        Qlist *temp = *front;

        if ((*front)->link == NULL)
        {
                free(*front);
                *front = *rear = NULL;
                return SUCCESS;
        }
        (*front) = (*front)->link;
        free(temp);

        return SUCCESS;
}
