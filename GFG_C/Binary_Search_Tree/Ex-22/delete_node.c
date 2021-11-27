#include "Tree.h"

BS_Tree *delete_a_node(BS_Tree *root, data_t data)
{
        if (root == NULL)
                return NULL;
        else if (root->data < data)
                root->right = delete_a_node(root->right, data);
        else if (root->data > data)
                root->left = delete_a_node(root->left, data);
        else
        {
                if(root->left == NULL && root->right == NULL)
                {
                        free(root);
                        root = NULL;
                        return root;
                }
                else if (root->left != NULL && root->right == NULL)
                {
                        BS_Tree *temp = root;
                        root = root->left;
                        free(temp);
                        return root;
                }
                else if (root->right != NULL && root->left == NULL)
                {
                        BS_Tree *temp = root;
                        root = root->right;
                        free(temp);
                        return root;
                }
                else
                {
                        BS_Tree *temp;
                        root->data = (temp = find_min(root->right))->data;
                        delete_a_node(root->right, temp->data);
                        return root;
                }
        }
        return root;
}
