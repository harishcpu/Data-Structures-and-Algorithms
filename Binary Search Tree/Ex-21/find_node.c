#include "Tree.h"

/* find_a_node_iterative: find a node in a tree using iterative approach */
int find_a_node_iterative(BS_Tree *root, data_t data)
{
        if (root == NULL)
                return DATA_NOT_FOUND;
        while (root)
        {
                if (root->data > data)
                        root = root->left;
                else if (root->data < data)
                        root = root->right;
                else
                        return DATA_FOUND;
        }
        return DATA_NOT_FOUND;
}

/* find_a_node_recursive: find a node in a tree using recursive approach */
int find_a_node_recursive(BS_Tree *root, data_t data)
{
        if (root == NULL)
                return DATA_NOT_FOUND;
        else if (root->data > data)
                return find_a_node_recursive(root->left, data);
        else if (root->data < data)
                return find_a_node_recursive(root->right, data);
        else
                return DATA_FOUND;
}
