#include "Tree.h"

/* find_min: find the one node with minimum value in a tree */
BS_Tree *find_min(BS_Tree* root)
{
        if (root->left == NULL)
                return root;
        else
                return find_min(root->left);
}

/* find_max: find the one node with maximum value in a tree */
BS_Tree *find_max(BS_Tree* root)
{
        if (root->right == NULL)
                return root;
        else
                return find_max(root->right);
}
