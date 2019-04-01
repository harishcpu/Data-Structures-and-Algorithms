#include "rbt.h"

void in_order(tree_t* root)
{
        if (root == NULL)
                return;
        in_order(root->left);
        root->color == RED ? printf(BOLDRED "") : printf(BOLDWHITE "");
        printf("%d" RESET "->", root->data);
        in_order(root->right);
}

void pre_order(tree_t *root)
{
        if (root == NULL)
                return;
        root->color == RED ? printf(BOLDRED "") : printf(BOLDWHITE "");
        printf("%d" RESET "->", root->data);
        pre_order(root->left);
        pre_order(root->right);
}

void post_order(tree_t *root)
{
        if (root == NULL)
                return;
        root->color == RED ? printf(BOLDRED "") : printf(BOLDWHITE "");
        printf("%d" RESET "->", root->data);
        pre_order(root->right);
        pre_order(root->left);
}

void level_order(tree_t* root)
{
        if (root == NULL)
                return;
        //printf("%d->\n", root->data);

        if (root->left)
        {
                root->left->color == RED ? printf(BOLDRED "") : printf(BOLDWHITE "");
                printf("%d" RESET "->", root->left->data);
        }
        if (root->right)
        {
                root->right->color == RED ? printf(BOLDRED "") : printf(BOLDWHITE "");
                printf("%d" RESET "->", root->right->data);
        }
        level_order(root->left);
        level_order(root->right);
}

void print_tree(tree_t *root)
{
        in_order(root);
        putchar('\n');
        
        pre_order(root);
        putchar('\n');
        
        post_order(root);
        putchar('\n');
        
        if (root != NULL)
        {
                root->color == RED ? printf(BOLDRED "") : printf(BOLDWHITE "");
                printf("%d" RESET "->", root->data);
        }
        level_order(root);
        putchar('\n');
}
