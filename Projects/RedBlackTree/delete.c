/*************************************************************************************************************
* Title			: Deletion
* Description		: This function performs deleting of the given data from the given Red Black tree.
* Prototype		: int delete(tree_t **root, data_t item); 
* Input Parameters	: root – Pointer to the root node of the Red Black tree.
			: item – Data to be deleted from the Red Black tree.
* Output		: Status (SUCCESS / FAILURE)
**************************************************************************************************************/
#include "rbt.h"

#define TRUE 1
#define FALSE 0

void Rotate_right(tree_t **root, tree_t *node);
void Rotate_left(tree_t **root, tree_t *node);

tree_t *Successor(tree_t *node)
{
        return find_minimum(node);
}

int hasRedChild(tree_t *node)
{
        return ((node->left != NULL && node->left->color == RED) || (node->right != NULL && node->right->color == RED));
}

int isOnleft(tree_t *node)
{
        if (node->parent->left == node)
                return TRUE;
        else
                return FALSE;
}

void SwapColors(tree_t *x1, tree_t *x2)
{
        enum _node_color temp = x1->color;
        x1->color = x2->color;
        x2->color = temp;
}

void SwapValues(tree_t *u, tree_t *v)
{
        data_t temp = u->data;
        u->data = v->data;
        v->data = temp;
}

/* Sibling: */
tree_t *Sibling(tree_t *node)
{
        tree_t *p = node->parent;
        if ( p == NULL )
                return NULL;

        if ( p->left )
                return p->right;

        return p->left;
}

tree_t *Check_children(tree_t *node)
{
        /* if node has two children */
        if ( node->left != NULL && node->right != NULL )
                return Successor(node->right);
        
        /* when if only a leaf */
        if ( node->left == NULL && node->right == NULL )
                return NULL;
        
        /* if only a single child */
        if (node->left != NULL)
                return node->left;
        else
                return node->right;
}

void RB_delete_fixup(tree_t **root, tree_t *node)
{
#if 0
        if (node == *root)
                return;

        tree_t *sibling = Sibling(node);
        tree_t *p = node->parent;

        if (sibling == NULL)
                RB_delete_fixup(root, p);
        else
        {
                if (sibling->color == RED)
                {
                        p->color = RED;
                        sibling->color = BLACK;
                        if (isOnleft(sibling))
                                Rotate_right(root, p);
                        else
                                Rotate_left(root, p);
                        RB_delete_fixup(root, node);
                }
                else
                {
                        if (hasRedChild(sibling))
                        {
                                if (sibling->left != NULL && sibling->left->color == RED)
                                {
                                        if (isOnleft(sibling))
                                        {
                                                sibling->left->color = sibling->color;
                                                sibling->color = p->color;
                                                Rotate_right(root, p);
                                        }
                                        else
                                        {
                                                sibling->left->color = p->color;
                                                Rotate_right(root, sibling);
                                                Rotate_left(root, p);
                                        }
                                }
                                else
                                {
                                        if (isOnleft(sibling))
                                        {
                                                sibling->right->color = p->color;
                                                Rotate_left(root, sibling);
                                                Rotate_right(root, p);
                                        }
                                        else
                                        {
                                                sibling->right->color = sibling->color;
                                                sibling->color = p->color;
                                                Rotate_left(root, p);
                                        }
                                }
                                p->color = BLACK;
                        }
                        else
                        {
                                sibling->color = RED;
                                if (p->color == BLACK)
                                        RB_delete_fixup(root, p);
                                else
                                        p->color = BLACK;
                        }
                }
        }
#endif

        tree_t *sibling = NULL;
        while ( node != *root && node->color == BLACK )
        {
                if ( node == node->parent->left )
                {
                        sibling = node->parent->right;
                        if ( sibling->color == RED )
                        {
                                sibling->color = BLACK;
                                node->parent->color = RED;
                                Rotate_left(root, node->parent);
                                sibling = node->parent->right;
                        }
                        if ( sibling->left->color == BLACK && sibling->right->color == BLACK )
                        {
                                sibling->color = RED;
                                node = node->parent;
                        }
                        else if ( sibling->right->color == BLACK )
                        {
                                sibling->left->color = BLACK;
                                sibling->color = RED;
                                Rotate_right(root, sibling);
                                sibling = node->parent->right;
                        }
                        else
                        {
                                sibling->color == node->parent->color;
                                node->parent->color = BLACK;
                                sibling->right->color = BLACK;
                                Rotate_left(root, node->parent);
                                node = *root;
                        }
                }
                else
                {
                        sibling = node->parent->left;
                        if ( sibling->color == RED )
                        {
                                sibling->color = BLACK;
                                node->parent->color = RED;
                                Rotate_right(root, node->parent);
                                sibling = node->parent->left;
                        }
                        if ( sibling->right->color == BLACK && sibling->left->color == BLACK )
                        {
                                sibling->color = RED;
                                node = node->parent;
                        }
                        else if ( sibling->left->color == BLACK )
                        {
                                sibling->right->color = BLACK;
                                sibling->color = RED;
                                Rotate_left(root, sibling);
                                sibling = node->parent->left;
                        }
                        else
                        {
                                sibling->color == node->parent->color;
                                node->parent->color = BLACK;
                                sibling->left->color = BLACK;
                                Rotate_right(root, node->parent);
                                node = *root;
                        }
                }
        }
        node->color = BLACK;
}

/* RB_delete: Delete an element in a Red Black Tree */
void RB_delete(tree_t **root, tree_t *v)
{
        tree_t *u = Check_children(v);

        enum _node_color uvBlack = ((u == NULL || u->color == BLACK) && (v->color == BLACK));
        tree_t *p = v->parent;

        if (u == NULL)
        {
                if (v == NULL)
                        root = NULL;
                else
                {
                        if (uvBlack)
                        {
                                RB_delete_fixup(root, v);
                        }
                        else
                        {
                                if (Sibling(v) != NULL)
                                {
                                        Sibling(v)->color = RED;
                                }
                        }

                        if (isOnleft(v))
                                p->left = NULL;
                        else
                                p->right = NULL;
                }
                free(v);
                v = NULL;
                return;
        }
                        
        if (v->left == NULL || v->right == NULL)
        {
                if (v == *root)
                {
                        v->data = u->data;
                        v->left = v->right = NULL;
                        free(u);
                        u = NULL;
                }
                else
                {
                        if (isOnleft(v))
                                p->left = u;
                        else
                                p->right = u;
                        free(v);
                        v = NULL;
                        u->parent = p;
                        if (uvBlack)
                                RB_delete_fixup(root, u);
                        else
                                u->color = BLACK;
                }
                return;
        }

        SwapValues(u, v);
        RB_delete(root, u);
}

/* binarySearch: Search for an element in a binary search tree */
tree_t *binarySearch(tree_t *root, data_t item)
{
        while ( root != NULL )
        {
                if ( item < root->data ) {
                        if ( root->left == NULL )
                                break;
                        else
                                root = root->left;
                } else if ( item == root->data )
                        break;
                else {
                        if ( root->right == NULL )
                                break;
                        else
                                root = root->right;
                }
        }
        return root;
}

int delete(tree_t **root, data_t item)
{
	/* Definition goes here */
        if ( *root == NULL )
                return FAILURE;

        tree_t *node = binarySearch(*root, item);

        if ( node->data != item )
        {
                printf("\t\t\tNo such element is found\n");
                return FAILURE;
        }

        if (*root == node && node->left == NULL && node->right == NULL)
        {
                free(node);
                *root = NULL;
        }

        RB_delete(root, node);
        return SUCCESS;
}
