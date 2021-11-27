#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SUCCESS 0
#define FAILURE 1
#define DATA_FOUND 0
#define DATA_NOT_FOUND 1

typedef int data_t;
typedef struct _node
{
        struct _node *left, *right;
        data_t data;
}BS_Tree;

BS_Tree* find_max(BS_Tree* root);

BS_Tree* find_min(BS_Tree* root);

BS_Tree *create_node(data_t data);

BS_Tree* insert_node(BS_Tree* root, data_t data);

int insert(BS_Tree **root, data_t data);

BS_Tree* delete_a_node(BS_Tree* root, data_t data);

int find_a_node_iterative(BS_Tree* root, data_t data);

int find_a_node_recursive(BS_Tree* root, data_t data);

void in_order(BS_Tree *root);

void pre_order(BS_Tree *root);

void post_order(BS_Tree *root);

void level_order(BS_Tree *root);

int max_nodes_in_a_tree(BS_Tree *root);

int max_depth(BS_Tree *root);
#endif
