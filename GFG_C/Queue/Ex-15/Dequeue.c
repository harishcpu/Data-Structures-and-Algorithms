#include "queue.h"

int dequeue(Q_ary *Q, data_t *data)
{
        /* check if Q is empty */
        if (Q->rear == -1)
                return Q_EMPTY;

        /* Get the data */
        *data = Q->Q_data[Q->front];
        /* Increment count */
        ++(Q->front);

        if (Q->front > Q->rear)
                Q->front = Q->rear = -1;
        
        return SUCCESS;
}
