/* ------------------------------------------------------------------------------ 
 *   Author         : HARISH
 *   Date           : Mon Jan 28
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
        int n;

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
                                if (find_mid(&head) == LIST_EMPTY)
                                        printf("\t\t\tFalied: List is empty\n\t\t\tTry Again...\n");
                                break;
                        case 3:
                                printf("Enter the node position from last: ");
                                scanf("%d", &n);
                                if ((n = get_nth_last(head, n)) == LIST_EMPTY)
                                        printf("\t\t\tFalied: List is empty\n\t\t\tTry Again...\n");
                                else if (n == FAILURE)
                                        printf("Element not found\n");
                                break;
                                        
                        case 4:
                                print_list(head);
                                break;
                        case 5:
                                if (delete_list(&head) == LIST_EMPTY)
                                        printf("\t\t\tFalied: List is empty\n\t\t\tTry Again...\n");
                                break;
                        default:
                                printf("Wrong choice\n");
                                break;
                }
                printf("Want to continue? (y/n) "); getchar();
        } while ('n' != getchar());
}

int select_operation(void)
{
        int choice;

        printf("Options: \n");
        printf("\t1. Insert\n");
        printf("\t2. find mid\n");
        printf("\t3. get nth last\n");
        printf("\t4. Print list\n");
        printf("\t5. Delete list\n");

        printf("Your choice: ");
        scanf("%d", &choice);
        return choice;
}
