/***************************************************************************************************
* Title		: This the header file for the Red Black Tree
****************************************************************************************************/
#ifndef RBT_H
#define RBT_H

#define SUCCESS 0
#define FAILURE -1

#include <stdio.h>
#include <stdlib.h>
#include "colors.h"

typedef int data_t;

typedef struct node
{
	char color;
	data_t data;
	struct node *left, *right, *parent;
}tree_t;

enum _node_color {BLACK, RED};

/* keep all the prototypes of the functions here */

int insert(tree_t **root, data_t item);
int delete(tree_t **root, data_t item);
tree_t *find_maximum(tree_t *root);
tree_t *find_minimum(tree_t *root);
int delete_maximum(tree_t **root);
int delete_minimum(tree_t **root);
void print_tree(tree_t *root);

#endif
