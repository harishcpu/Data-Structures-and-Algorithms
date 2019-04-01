/*******************************************************************************************************************************************************************
*Title			: Delete Minimum
*Description		: This function deletes the minimum data from the given Red Black tree.
*Prototype		: int delete_minimum(tree_t **root);
*Input Parameters	: root – Pointer to the root node of the Red Black tree.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "rbt.h"

int delete_minimum(tree_t **root)
{
	/* Definition goes here */
        tree_t *min = find_minimum(*root);
        printf("The node with minimum key is %d.\n", min->data);
        delete(root, min->data);
}
