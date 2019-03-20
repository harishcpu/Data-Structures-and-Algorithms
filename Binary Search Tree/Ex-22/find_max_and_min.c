#include "Tree.h"

/* find_min */
BS_Tree *find_min(BS_Tree* root)
{
        if (root->left == NULL)
                return root;
        else
                return find_min(root->left);
}

/* find max */
BS_Tree *find_max(BS_Tree* root)
{
        if (root->right == NULL)
                return root;
        else
                return find_max(root->right);
}
