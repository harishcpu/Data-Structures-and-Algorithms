#include "inc/tree.h"

void preOrder(node *root) {
	if(root) {
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main(void) {
	node *root = newNode(1);

    root->left = newNode(2);	
    root->right = newNode(3);

	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);	
	
	// traverse the tree in pre-order
	preOrder(root);
	putc('\n', stdout);
}
