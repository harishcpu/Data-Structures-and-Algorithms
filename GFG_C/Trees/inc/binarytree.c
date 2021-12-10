#include "tree.h"

node *newNode(int data) {
	node *new = (node *)malloc(sizeof(node));
	new->data = data;
	new->left = NULL;
	new->right = NULL;

	return new;
}
