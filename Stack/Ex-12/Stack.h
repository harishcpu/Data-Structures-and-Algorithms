#ifndef STACK_H
#define STACK_L

#include <stdio.h>
#include <stdlib.h>

/* macro definitions */
#define SUCCESS 0
#define FAILURE -1
#define STACK_EMPTY 1
#define STACK_FULL 2

typedef int data_t;
/* Stucture definition of stack implemented using linked list */
typedef struct _node
{
        struct _node *link;
        data_t data;
} STACK_Sll;

int select_operation();
int push(STACK_Sll **top, data_t data);
int pop(STACK_Sll **top, data_t *data);
int peak(STACK_Sll *top);
int peap(STACK_Sll *top);

#endif
