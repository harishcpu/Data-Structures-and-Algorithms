#include "Tree.h"

/* insert a node in a tree */
int insert(BS_Tree **root, data_t data)
{
        /* create a new node */
        BS_Tree* new = (BS_Tree *)malloc(sizeof(BS_Tree));
        if (new == NULL)
                exit(FAILURE);
        new->data = data;
        new->left = NULL;
        new->right = NULL;

        /* check if the tree is empty */
        if (*root == NULL)
        {
                *root = new;
                printf("%d\n", new->data);
                return SUCCESS;
        }
        
        /* if not empty */
        BS_Tree* temp = *root;
        BS_Tree* prev = NULL;
        while (temp)
        {
                prev = temp;

                /* move to the left */
                if (temp->data > data)
                {
                        temp = temp->left;
                        if (temp == NULL)
                        {
                                prev->left = new;
                                printf("%d\n", new->data);
                                return SUCCESS;
                        }
                }
                /* move to the right */
                else if (temp->data < data)
                {
                        temp = temp->right;
                        if (temp == NULL)
                        {
                                prev->right = new;
                                printf("%d\n", new->data);
                                return SUCCESS;
                        }
                }
                else
                        return SUCCESS;
        }
        return SUCCESS;
}

BS_Tree* create_node(data_t data)
{
        BS_Tree* new = (BS_Tree *)malloc(sizeof(BS_Tree));
        if (new == NULL)
                exit(FAILURE);
        new->data = data;
        new->left = NULL;
        new->right = NULL;

        return new;
}

BS_Tree *insert_node(BS_Tree* root, data_t data)
{
        if (root == NULL)
                root = create_node(data);
        else if (root->data > data)
                root->left = insert_node(root->left, data);
        else if (root->data < data)
                root->right = insert_node(root->right, data);
        else
                printf("Already present\n");
        return root;
}
