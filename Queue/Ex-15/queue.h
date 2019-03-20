#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* macro definitions */
#define SIZE 5
#define SUCCESS 0
#define FAILURE 1
#define Q_EMPTY INT_MIN
#define Q_FULL INT_MAX

typedef int data_t;
/* structure definitions */
typedef struct _queue
{
        data_t Q_data[SIZE];
        int front, rear;
}Q_ary;

int select_operation();
int enqueue(Q_ary *Q, data_t data);
int dequeue(Q_ary *Q, data_t *data);
int display(Q_ary *Q);

#endif
