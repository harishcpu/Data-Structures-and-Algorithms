/*****************************************************************************************************
* Title			: Insertion
* Description		: This function performs inserting the new data into the given Red Black tree.
* Prototype		: int insert(tree_t **root, data_t item);
* Input Parameters	: root – Pointer to the root node of the Red Black tree.
			: item – New data to be inserted into the Red Black tree.
* Output		: Status (SUCCESS / FAILURE)
*****************************************************************************************************/
#include "rbt.h"

tree_t *create_node(data_t item)
{
        tree_t *new = (tree_t *)malloc(sizeof(tree_t));
        if (new == NULL)
                exit(FAILURE);
        new->parent = NULL;
        new->data = item;
        new->right = new->left = NULL;
        new->color = RED;

        return new;
}

tree_t *RB_insert(tree_t **root, data_t item)
{
	/* Definition goes here */
        
        /* check if the tree is empty */
        if ( *root == NULL ) {
                *root = create_node(item);
                return *root;
        }
        
        /* if not empty */
        tree_t* temp = *root;
        tree_t* prev = NULL;
        while ( temp ) {
                prev = temp;

                /* move to the left */
                if ( temp->data > item ) {
                        temp = temp->left;
                        if ( temp == NULL )
                        {
                                prev->left = create_node( item );
                                prev->left->parent = prev;
                                return prev->left;
                        }
                }
                /* move to the right */
                else if ( temp->data < item ) {
                        temp = temp->right;
                        if ( temp == NULL ) {
                                prev->right = create_node( item );
                                prev->right->parent = prev;
                                return prev->right;
                        }
                }
                else {
                        printf("\t\t\tItem is already present.\n");
                        return NULL;
                }
        }
}

void swap_colors(char *p, char *gp)
{
        char temp = *p;

        *p = *gp;
        *gp = temp;
}

void Rotate_right(tree_t **root, tree_t *node)
{
#if 0
        tree_t *node_left = node->left;

        node->left = node_left->right;
        if (node->left != NULL)
                node->left->parent = node;
        node_left->parent = node->parent;

        if (node->parent == NULL)
                *root = node_left;
        else if (node == node->parent->left)
                node->parent->left = node_left;
        else
                node->parent->right = node_left;

        node_left->right = node;
        node->parent = node_left;
#else
        tree_t *x = node->left;
        node->left = x->right;

        if (x->right != NULL)
                x->right->parent = node;
        x->parent = node->parent;

        if (node->parent == NULL)
                *root = x;
        else if (node->parent->left == node)
                node->parent->left = x;
        else 
                node->parent->right = x;
        x->right = node;
        node->parent = x;
#endif
}

void Rotate_left(tree_t **root, tree_t *node)
{
        tree_t *node_right = node->right;

        node->right = node_right->left;

        if (node->right != NULL)
                node->right->parent = node;
        node_right->parent = node->parent;

        if (node->parent == NULL)
                *root = node_right;
        else if (node == node->parent->left)
                node->parent->left = node_right;
        else
                node->parent->right = node_right;

        node_right->left = node;
        node->parent = node_right;
}

void RB_insert_fixup(tree_t **root, tree_t *node)
{
        tree_t *p = NULL;
        tree_t *gp = NULL;
        tree_t *uncle = NULL;
         
        while ( node != *root && node->color != BLACK && node->parent->color == RED )
        {
                p = node->parent;
                gp = node->parent->parent;
                /* case A */
                if ( p == gp->left ) {
                        uncle = gp->right;
#if 1
                        printf("\tCase A\n");
#endif
                        /* case 1 */
                        if ( uncle != NULL && uncle->color == RED ) {
                                p->color = BLACK;
                                uncle->color = BLACK;
                                gp->color = RED;
                                node = gp;
#if 1
                        printf("\t   -->Case 1  - recoloring\n");
#endif
                        } else if ( node == p->right ) {     /* case 2 */
                                Rotate_left( root, p );
                                node = p;
                                p = node->parent;
#if 1
                        printf("\t   -->Case 2  - rotate left\n");
#endif
                        }
                        else
                        {
                        /* case 3 */
                                Rotate_right( root, gp );
                                swap_colors( &p->color, &gp->color );
                                node = p;
#if 1
                        printf("\t   -->Case 3  - rotate right\n");
#endif
                        }
                }
                /* case B */
                else {
                        uncle = gp->left;
#if 1
                        printf("\tCase B\n");
#endif

                        /* case 1 */
                        if ( uncle != NULL && uncle->color == RED ) {
                                p->color = BLACK;
                                uncle->color = BLACK;
                                gp->color = RED;
                                node = gp;
#if 1
                        printf("\t   -->Case 1  - recoloring\n");
#endif
                        } else if ( node == p->left ) {   /* case 2 */
                                Rotate_right( root, p );
                                node = p;
                                p = p->parent;
#if 1
                        printf("\t   -->Case 2  - rotate right\n");
#endif
                        }
                        else {
                                /* case 3 */
                                Rotate_left( root, gp );
                                swap_colors( &p->color, &gp->color );
                                node = p;
#if 1
                        printf("\t   -->Case 3  - rotate left\n");
#endif
                        }
                }
        }
        (*root)->color = BLACK;
}

int insert(tree_t **root, data_t item)
{
        tree_t *node = RB_insert(root, item);
#if 0
        print_tree(*root);
#endif
        if (node != NULL)
                RB_insert_fixup(root, node);
        else
                return FAILURE;
#if 1 
        printf("Root: %d\n", (*root)->data);
#endif   
        return SUCCESS;
}
