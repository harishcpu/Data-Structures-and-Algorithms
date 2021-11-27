/*------------------------------------------------------------------------------ 
 *   Author         : HARISH
 *   Date           : Mon Jan 28
 *   File           : Sll.h
 *   Title          : Header file 
 *   Description    : This file contains standard header files, macros, structure definition
 *                    and function prototypes required for single linked list	    
 *----------------------------------------------------------------------------*/

#ifndef SLL_H
#define SLL_L

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define LIST_EMPTY 1
#define DATA_NOT_FOUND 2
#define POSITION_NOT_FOUND DATA_NOT_FOUND
#define FAILURE -1

typedef int data_t;
typedef struct node
{
    data_t data;
    struct node *link;
}Slist;

int select_operation();
int insert_at_last(Slist **head, data_t data);
int sl_insert_after(Slist *head, data_t g_data, data_t n_data);
int sl_insert_before(Slist **head, data_t g_data, data_t n_data);
int sl_insert_nth(Slist **head, int position, data_t n_data);
int delete_element(Slist **head, data_t data);
int delete_list(Slist **head);
void print_list(Slist *head);

#endif
