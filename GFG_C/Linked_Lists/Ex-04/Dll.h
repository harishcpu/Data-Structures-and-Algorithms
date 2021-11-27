#ifndef DLL_H
#define DLL_H

#include <stdio.h>
#include <stdlib.h>
#include "colors.h"

#define SUCCESS 0
#define FAILURE -1
#define LIST_EMPTY 1
#define DATA_NOT_FOUND 1
typedef int data_t;
typedef struct node
{
        data_t data;
        struct node *prev, *next;
}Dlist;

int select_operation(void);
int dl_insert_after(Dlist **head, Dlist **tail, int g_data, int n_data);
int dl_insert_before(Dlist **head, Dlist **tail, int g_data, int n_data);
int dl_delete_list(Dlist **head);
void print_list_from_head(Dlist* head);
int insert_last(Dlist **head, Dlist **tail, int g_data);
#endif
