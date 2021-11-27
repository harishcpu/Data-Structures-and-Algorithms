#include "Tree.h"

void in_order(BS_Tree* root)
{
        if (root == NULL)
                return;
        in_order(root->left);
        printf("%d->", root->data);
        in_order(root->right);
}

void pre_order(BS_Tree *root)
{
        if (root == NULL)
                return;
        printf("%d->", root->data);
        pre_order(root->left);
        pre_order(root->right);
}

void post_order(BS_Tree *root)
{
        if (root == NULL)
                return;
        printf("%d->", root->data);
        pre_order(root->right);
        pre_order(root->left);
}

void level_order(BS_Tree* root)
{
        if (root == NULL)
                return;
        //printf("%d->\n", root->data);

        if (root->left)
                printf("%d->", root->left->data);
        if (root->right)
                printf("%d->", root->right->data);
        level_order(root->left);
        level_order(root->right);
}
