/*******************************************************************************************************************************************************************
*Title			: Delete Maximum
*Description		: This function deletes the maximum data from the given Red Black tree.
*Prototype		: int delete_maximum(tree_t **root);
*Input Parameters	: root – Pointer to the root node of the Red Black tree.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "rbt.h"

int delete_maximum(tree_t **root)
{
	/* Definition goes here */
        tree_t *max = find_maximum(*root);
        printf("The node with maximum key is %d.\n", max->data);
        delete(root, max->data);
}
