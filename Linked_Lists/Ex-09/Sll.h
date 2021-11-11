/*------------------------------------------------------------------------------ 
 *   Author         : HARISH 
 *   Date           : Feb 04 Mon 
 *   File           : Sll.h
 *   Title          : Header file 
 *   Description    : This file contains standard header files, macros, structure definition
 *                    and function prototypes required for single linked list	    
 *----------------------------------------------------------------------------*/

#ifndef SLL_H
#define SLL_L

/* header files from standard library */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/* a local header file */
#include "colors.h"

/* macro definitions */
#define SUCCESS 0
#define FAILURE -1
#define LIST_EMPTY INT_MAX
#define DATA_FOUND SUCCESS
#define DATA_NOT_FOUND FAILURE

typedef int data_t;
/* structure _node definition */
typedef struct _node
{
    data_t data;
    struct _node *link;
} Slist;

int select_operation();
int insert_at_last(Slist **head, data_t data);
int remove_duplicates(Slist **head);
void print_list(Slist *head);

#endif
