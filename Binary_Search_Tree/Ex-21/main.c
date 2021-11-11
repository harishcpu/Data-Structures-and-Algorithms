#include "Tree.h"

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
                printf("\t4. find a node\n");
                printf("\t5. find max & min\n");
                printf("Your choice: ");
                scanf("%d", &choice);

                switch(choice)
                {
                        case 1:         /* insertion */
                                printf("Enter the data: ");
                                scanf("%d", &data);
                                insert(&root, data);
				insert_node(root, data);
                                break;
                        
			case 2:         /* deletion */
                                printf("Enter the data: ");
                                scanf("%d", &data);
                                root = delete_a_node(root, data);
                                break;

                        case 3:         /* print tree */
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

                        case 4:         /* find node */
                                printf("Enter a node data: ");
                                scanf("%d", &data);

                                printf("\t\t\t\tRecursive: ");
                                if (DATA_NOT_FOUND == find_a_node_recursive(root, data))
                                        printf("DATA NOT FOUND\n");
                                else
                                        printf("Data found\n");
                                
                                printf("\t\t\t\tIterative: ");
                                if (DATA_NOT_FOUND == find_a_node_iterative(root, data))
                                        printf("DATA NOT FOUND\n");
                                else
                                        printf("Data found\n");
                                break;

                        case 5:         /* find max and min nodes */
                                printf("max: %d\n", find_max(root)->data);
                                printf("min: %d\n", find_min(root)->data);
                                break;
                }
        }while (1);
}
