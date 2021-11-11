#include "Tree.h"

int count_nodes(BS_Tree *root)
{
        int count = 1;
        if (root == NULL)
                return 0;
        else
        {
                count += count_nodes(root->left);
                count += count_nodes(root->right);
                return count;
        }
}
