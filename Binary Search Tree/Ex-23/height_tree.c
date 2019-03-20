#include "Tree.h"

int max_depth(BS_Tree *root)
{
        if (root == NULL)
                return 0;
        else
        {
                int left_height = max_depth(root->left);
                int right_height = max_depth(root->right);

                if (left_height > right_height)
                        return left_height + 1;
                else 
                        return right_height + 1;
        }
}
