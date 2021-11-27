/* ------------------------------------------------------------------------------ 
 *   Author         : HARISH
 *   Date           : Mon Jan 28
 *   File           : main.c
 *   Title          : Driver function
 *   Description    : This function acts like a driver function, it invokes all
                        other sub functions. It is user interactive.
 * ---------------------------------------------------------------------------- */
#include "Sll.h"

int main()
{
    Slist *head = NULL;
    int choice;
    int STATUS;
    data_t data;

    /* clear the terminal screen */
    system("clear");
    do
    {
        choice = select_operation();
        /* Go to the case choosen by the user */
        switch(choice)
        {
            case 1:	/* insert at last */
                printf("Enter the number to insert at last\n");
                scanf("%d", &data);
                if (insert_at_last(&head, data) == FAILURE)
			printf("\t\t\t\t" BOLDRED "Failed" RESET ": Inserting new data at last\n\t\t\t\t\tTry again...\n");
                break;

            case 2:	/* sort list */
                sort_by_values(&head);
                break;
            case 3:	/* sort list */
                sort_by_nodes(&head);
                break;
            case 4:	/* print list */
                        print_list(head);
                break;

            default:
                        printf(RED "Wrong choice" RESET "\nTry again...\n");
                break;
        }
        printf("Do you want to continue?...y/n  ");
        getchar();
    } while (getchar() != 'n');
    return 0;
}

/* select_operation: prints the available operations and
                     returns user's' choice to the caller */
int select_operation(void)
{
    int choice;

    printf("Options: \n");
    printf("\t1. Insert\n");
    printf("\t2. Sort by values\n");
    printf("\t3. Sort by nodes\n");
    printf("\t4. Print list\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    return choice;
}
