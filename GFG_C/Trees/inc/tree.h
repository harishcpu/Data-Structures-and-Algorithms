#ifndef TREE_H
#define	TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node *left, *right;
}node;

node *newNode(int data);

#endif
