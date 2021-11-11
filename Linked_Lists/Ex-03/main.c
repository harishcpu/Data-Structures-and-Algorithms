/* ------------------------------------------------------------------------------ 
 *   Author         : HARISH
 *   Date           : Mon Feb 6
 *   File           : main.c
 *   Title          : Driver function
 *   Description    : This function acts like a driver function, it invokes all
                        other sub functions. It is user interactive.
 * ---------------------------------------------------------------------------- */
#include "Dll.h"

int main()
{
    Dlist *head = NULL;
    Dlist *tail = NULL;

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
                if (insert_first(&head, &tail, data) == FAILURE)
			printf("\t\t\t\t" BOLDRED "Failed" RESET ": Inserting new data at first\n\t\t\t\t\tTry again...\n");
                break;

            case 2:	/* insert at last */
                printf("Enter the number to insert at last\n");
                scanf("%d", &data);
                if (insert_last(&head, &tail, data) == FAILURE)
			printf("\t\t\t\t" BOLDRED "Failed" RESET ": Inserting new data at last\n\t\t\t\t\tTry again...\n");
                break;

            case 3:	/* delete at first */
                if ((STATUS = delete_first(&head, &tail)) == LIST_EMPTY)
			printf("\t\t\t\t" BOLDRED "Failed" RESET ": List is empty. Please insert some nodes and try again...\n");

		else if (STATUS == FAILURE)
			printf("\t\t\t\t" BOLDRED "Failed" RESET ": Deleting a node at first\n\t\t\t\t\tTry again...\n");
                break;

            case 4:	/* delete at last */
                if ((STATUS = delete_last(&head, &tail)) == LIST_EMPTY)
			printf("\t\t\t\t" BOLDRED "Failed" RESET ": List is empty. Please insert some nodes and try again...\n");

		else if (STATUS == FAILURE)
			printf("\t\t\t\t" BOLDRED "Failed" RESET ": Deleting a node at last\n\t\t\t\t\tTry again...\n");
                break;
            
            case 5:	/* delete list */
                if (FAILURE == (STATUS = delete_list(&head, &tail)))
                    printf("\t\t\t\t" BOLDRED "Failed" RESET ": Deleting list. Try again...\n");
                
                else if (STATUS == LIST_EMPTY)
			printf("\t\t\t\t" BOLDRED "Failed" RESET ": List is empty. Please insert some nodes and try again...\n");
                break;

            case 6:	/* print list */
                        print_list_from_head(head);
                        print_list_from_tail(tail);
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
    printf("5. Delete list\n");
    printf("6. Print list\n");
    scanf("%d", &choice);

    switch(choice)
    {
            case 1: printf(BOLDBLUE "Insert at first" RESET "\n"); break;
            case 2: printf(BOLDBLUE "Insert at last" RESET "\n"); break;
            case 3: printf(BOLDBLUE "Delete at first" RESET "\n"); break;
            case 4: printf(BOLDBLUE "Delete at last" RESET "\n"); break;
            case 5: printf(BOLDBLUE "Delete list" RESET "\n"); break;
            case 6: printf(BOLDBLUE "Print list" RESET "\n"); break;
    }

    return choice;
}
