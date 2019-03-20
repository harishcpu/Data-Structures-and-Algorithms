#include "queue.h"

int display(Qlist *front)
{
        if (front == NULL)
                return Q_EMPTY;

        while (front)
        {
                printf("%d->", front->data);
                front = front->link;
        }
        putchar('\n');
        return SUCCESS;
}
