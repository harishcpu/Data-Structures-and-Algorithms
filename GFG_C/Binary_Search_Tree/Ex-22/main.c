#include "Tree.h"

BS_Tree *create_node(data_t data);
BS_Tree* insert_node(BS_Tree* root, data_t data);

int insert(BS_Tree **root, data_t data);
void display(BS_Tree *left);

int main()
{
        BS_Tree* root = NULL;
        data_t data;

        do
        {
                int choice;
                printf("Options:\n");

                printf("\t1. Insert\n");
                printf("\t2. Delete\n");
                printf("\t3. Display\n");
                printf("Your choice: ");
                scanf("%d", &choice);

                switch(choice)
                {
                        case 1:
                                /* insertion */
                                printf("Enter the data: ");
                                scanf("%d", &data);
                                insert(&root, data);
                                //insert_node(root, data);
                                break;
                        case 2:
                                /* deletion */
                                printf("Enter the data: ");
                                scanf("%d", &data);
                                root = delete_a_node(root, data);
                                break;
                        case 3:
                                /* print nodes in a tree */
                                printf("In Order: ");
                                in_order(root);
                                putchar('\n');
                                printf("Pre Order: ");
                                pre_order(root);
                                putchar('\n');
                                printf("Post Order: ");
                                post_order(root);
                                putchar('\n');
                                
                                printf("Level Order: "); 
                                if (root)
                                        printf("%d->", root->data);
                                level_order(root);
                                putchar('\n');
                                break;
                }
        }while (1);
}

#if 1
int insert(BS_Tree **root, data_t data)
{
        BS_Tree* new = (BS_Tree *)malloc(sizeof(BS_Tree));
        if (new == NULL)
                exit(FAILURE);
        new->data = data;
        new->left = NULL;
        new->right = NULL;

        if (*root == NULL)
        {
                *root = new;
                printf("%d\n", new->data);
                return SUCCESS;
        }
        
        BS_Tree* temp = *root;
        BS_Tree* prev = NULL;
        while (temp)
        {
                prev = temp;
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
#else
BS_Tree* create_node(data_t data)
{
        BS_Tree* new = (BS_Tree *)malloc(sizeof(BS_Tree));
        if (new == NULL)
                exit(FAILURE);
        new->data = data;
                                printf("%d\n", new->data);
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
#endif
