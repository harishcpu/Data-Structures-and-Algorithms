/* ------------------------------------------------------------------------------ 
 *   Author         : HARISH
 *   Date           : Feb 3
 *   File           : main.c
 *   Title          : Driver function
 *   Description    : This function acts like a driver function, it is user 
					  interactive.  
 * ---------------------------------------------------------------------------- */
#include "Sll.h"

int main()
{
        Slist *head = NULL;
        data_t data;
        do
        {
                switch(select_operation())
                {
                        case 1:
                                printf("Enter the data: ");
                                scanf("%d", &data);
                                if (insert_at_last(&head, data) == FAILURE)
                                        printf("Failed: inserting at last\n");
                                break;
                        case 2:
                                reverse_list_iterative(&head);
                                break;
                        case 3:
                                reverse_list_recursive(&head, NULL, head);
                                break;
                        case 4:
                                delete_list(&head);
                                break;
                        case 5:
                                print_list(head);
                                break;
                        default:
                                printf("Wrong choice\n");
                                break;
                }
        } while (1);
}

int select_operation(void)
{
        int choice;

        printf("Options: \n");
        printf("\t1. Insert\n");
        printf("\t2. Reverse list iterative\n");
        printf("\t3. Reverse list recursive\n");
        printf("\t4. Delete list\n");
        printf("\t5. Print list\n");

        printf("Your choice: ");
        scanf("%d", &choice);
        return choice;
}
