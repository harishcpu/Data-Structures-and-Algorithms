#include "Tree.h"

BS_Tree *create_node(data_t data);
BS_Tree* insert_node(BS_Tree* root, data_t data);

int insert(BS_Tree **root, data_t data);

int main()
{
        BS_Tree* root = NULL;
        data_t data;

        do
        {
                int choice;
                printf("Options:\n");

                printf("\t1. Insert\n");
                printf("\t2. Display\n");
                printf("\t3. Tree height\n");
                printf("\t4. no. of nodes\n");
                
                printf("Your choice: ");
                scanf("%d", &choice);

                switch(choice)
                {
                        case 1:         /* insert a node */
                                printf("Enter the data: ");
                                scanf("%d", &data);
                                insert(&root, data);
                                //insert_node(root, data);
                                break;
                        case 2:         /* print the nodes in tree */
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
                        case 3:
                                printf("height of the tree: %d\n", max_depth(root));
                                break;
                        case 4:
                                printf("The no. of nodes in this tree is %d\n", count_nodes(root));
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
