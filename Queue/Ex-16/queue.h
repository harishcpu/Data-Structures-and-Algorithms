#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* macro definitions */
#define SUCCESS 0
#define FAILURE 1
#define Q_EMPTY INT_MIN
#define Q_FULL INT_MAX

typedef int data_t;
/* structure definitions */
typedef struct _queue
{
        data_t data;
        struct _queue* link;
} Qlist;

int select_operation();
int enqueue(Qlist **front, Qlist **rear, data_t data);
int dequeue(Qlist **front, Qlist **rear, data_t *data);
int display(Qlist *front);

#endif
