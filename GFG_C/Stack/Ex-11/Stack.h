#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

/* macro definitions */
#define SIZE 5
#define SUCCESS 0
#define FAILURE -1
#define STACK_EMPTY 1
#define STACK_FULL 2

typedef int data_t;

/*structure definition for stack using array */
typedef struct
{
        data_t data[SIZE];
        int top;
} STACK_ary;

int select_operation();
int push(STACK_ary *Stack, data_t data);
int pop(STACK_ary *Stack, data_t *data);
int peak(STACK_ary *Stack);
int peap(STACK_ary *Stack);

#endif
