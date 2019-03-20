#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>

typedef int data_t;
typedef struct _node
{
        int index;
        data_t data;
        struct _node *link;
} Hash_table;

#define SIZE 10

#define SUCCESS 0
#define FAILURE 1

#define DATA_NOT_FOUND -1
#define DATA_FOUND 0

Hash_table Hash_ary[SIZE];

int select_operation(void);

int create_hash_table(Hash_table *ary, int size);

int insert_node(Hash_table *ary, data_t data);

int delete_node(Hash_table *ary, data_t data);

void print_hash_table(Hash_table *ary);

int search_node(Hash_table *ary, data_t data);

int delete_table(Hash_table *ary);

#endif
