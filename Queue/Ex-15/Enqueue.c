#include "queue.h"

int enqueue(Q_ary *Q, data_t data)
{
        /* Check if queue is full */
        if (Q->rear >= SIZE-1)
                return Q_FULL;
        if (Q->front == -1 && Q->rear == -1)
                ++Q->front; 
        
        ++Q->rear;
        /* put in the data */
        Q->Q_data[Q->rear] = data;

        return SUCCESS;
}
