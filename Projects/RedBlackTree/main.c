/**************************************************************************************************************************************************************
*Title		: main function(Driver function)
*Description	: This function is used as the driver function for the all the functions
***************************************************************************************************************************************************************/
#include "rbt.h"

int main()
{
	/* Declare the pointers */
	tree_t *root = NULL;
	data_t data;
	data_t minimum;
	data_t maximum;

        int operation;
        char option;
	do
	{
		/* Display the menu */
		printf("1. Insert\n2. Delete\n3. Find Minimum\n4. Find Maximum\n5. Delete Minimum\n6. Delete Maximum\n");

		/* Read the option for performing the operation */
                scanf("%d", &operation);

		/* Jump to the option entered by the user */
		switch (operation)
		{
			case 1:
				printf("Enter the data to be inserted into the RB Tree: ");
				scanf("%d", &data);
				if ( insert(&root, data) == FAILURE )
                                        printf("\t\t\tSorry, It failed.\n");
				/* Modify the above line to handle the error */
				print_tree(root);
				break;
			case 2:
				printf("Enter the data to be deleted from the RB Tree: ");
				scanf("%d", &data);
				if ( delete(&root, data) == FAILURE )
                                        printf("\t\t\tSorry, It failed.\n");
				/* Modify the above line to handle the error */
				print_tree(root);
				break;
			case 3:
				printf("Minimum data: %d\n", find_minimum(root)->data);
				print_tree(root);
				break;
			case 5:
				delete_minimum(&root);
				/* Modify the above line to handle the error */
				print_tree(root);
				break;
			case 4:
				
				/* Modify the above line to handle the error */
				printf("Maximum data: %d\n", find_maximum(root)->data);
				print_tree(root);
				break;				
			case 6:
				delete_maximum(&root);
				/* Modify the above line to handle the error */
				print_tree(root);
				break;	
                        case 7:
                                print_tree(root);
                                break;
		}
		printf("Want to continue? Press [yY | nN]: ");
                getchar();
		scanf("%c", &option);
	}while (option != 'n' && option != 'N');

	return 0;
}
