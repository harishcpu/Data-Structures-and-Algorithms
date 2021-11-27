#include "queue.h"

int display(Q_ary *Q)
{
        if (Q->rear == -1)
                return Q_EMPTY;

        int i = Q->front;
        while (i <= Q->rear)
                printf("%d->", Q->Q_data[i++]);
        putchar('\n');
        return SUCCESS;
}
