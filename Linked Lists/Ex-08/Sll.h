/*------------------------------------------------------------------------------ 
 *   Author         : HARISH 
 *   Date           : FEB 2
 *   File           : Sll.h
 *   Title          : Header file 
 *   Description    : This file contains standard header files, macros, structure definition
 *                    and function prototypes required for single linked list	    
 *----------------------------------------------------------------------------*/

#ifndef SLL_H
#define SLL_L

#include <stdio.h>
#include <stdlib.h>
#include "colors.h"

#define SUCCESS 0
#define FAILURE -1

typedef int data_t;
typedef struct node
{
    data_t data;
    struct node *link;
}Slist;

int select_operation();
int insert_at_last(Slist **head, data_t data);
void reverse_list_iterative(Slist **head);
void reverse_list_recursive(Slist **head, Slist *prev, Slist *curr);
int delete_list(Slist **head);
void print_list(Slist *head);

#endif
