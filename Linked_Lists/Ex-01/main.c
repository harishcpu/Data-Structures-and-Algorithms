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
            case 1:	/* insert first */
                printf("Enter the number to insert at first\n");
                scanf("%d", &data);
                if (insert_at_first(&head, data) == FAILURE)
			printf("\t\t\t\t" BOLDRED "Failed" RESET ": Inserting new data at first\n\t\t\t\t\tTry again...\n");
                break;

            case 2:	/* insert at last */
                printf("Enter the number to insert at last\n");
                scanf("%d", &data);
                if (insert_at_last(&head, data) == FAILURE)
			printf("\t\t\t\t" BOLDRED "Failed" RESET ": Inserting new data at last\n\t\t\t\t\tTry again...\n");
                break;

            case 3:	/* delete at first */
                if ((STATUS = delete_at_first(&head)) == LIST_EMPTY)
			printf("\t\t\t\t" BOLDRED "Failed" RESET ": List is empty. Please insert some nodes and try again...\n");

		else if (STATUS == FAILURE)
			printf("\t\t\t\t" BOLDRED "Failed" RESET ": Deleting a node at first\n\t\t\t\t\tTry again...\n");
                break;

            case 4:	/* delete at last */
                if ((STATUS = delete_at_last(&head)) == LIST_EMPTY)
			printf("\t\t\t\t" BOLDRED "Failed" RESET ": List is empty. Please insert some nodes and try again...\n");

		else if (STATUS == FAILURE)
			printf("\t\t\t\t" BOLDRED "Failed" RESET ": Deleting a node at last\n\t\t\t\t\tTry again...\n");
                break;

            case 5:	/* find node */
                printf("Enter an element to find: ");
                scanf("%d", &data);
                if (LIST_EMPTY == (STATUS = find_node(data, head)))
			printf("\t\t\t\t" BOLDRED "Failed" RESET ": List is empty. Please insert some nodes and try again...\n");

                else if (STATUS == DATA_NOT_FOUND)
			printf("\t\t\t\t" BOLDRED "Failed" RESET ": Element is not found\n\t\t\t\t\tTry again...\n");

                else
			printf("\t\t\t\t" BOLDGREEN "Success" RESET ": Element %d is found at pos %d in the list\n", data, STATUS);
                break;

            case 6:	/* delete list */
                if (FAILURE == (STATUS = delete_list(&head)))
                    printf("\t\t\t\t" BOLDRED "Failed" RESET ": Deleting list. Try again...\n");
                
                else if (STATUS == LIST_EMPTY)
			printf("\t\t\t\t" BOLDRED "Failed" RESET ": List is empty. Please insert some nodes and try again...\n");
                break;

            case 7:	/* print list */
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
    printf("1. Insert at first\n");
    printf("2. Insert at last\n");
    printf("3. Delete at first\n");
    printf("4. Delete at last\n");
    printf("5. Find node\n");
    printf("6. Delete list\n");
    printf("7. Print list\n");
    scanf("%d", &choice);

    switch(choice)
    {
            case 1: printf(BOLDBLUE "Insert at first" RESET "\n"); break;
            case 2: printf(BOLDBLUE "Insert at last" RESET "\n"); break;
            case 3: printf(BOLDBLUE "Delete at first" RESET "\n"); break;
            case 4: printf(BOLDBLUE "Delete at last" RESET "\n"); break;
            case 5: printf(BOLDBLUE "Find node" RESET "\n"); break;
            case 6: printf(BOLDBLUE "Delete list" RESET "\n"); break;
            case 7: printf(BOLDBLUE "Print list" RESET "\n"); break;
    }

    return choice;
}
