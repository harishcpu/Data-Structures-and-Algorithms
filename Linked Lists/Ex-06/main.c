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
                printf("Enter the number to insert: ");
                scanf("%d", &data);
                if (insert_at_last(&head, data) == FAILURE)
			printf("\t\t\t\t" BOLDRED "Failed" RESET ": Inserting new data at last\n\t\t\t\t\tTry again...\n");
                break;

            case 2:	/* create loop */
                printf("Enter the position: ");
                scanf("%d", &choice);
                if ((STATUS = create_loop(&head, choice)) == LIST_EMPTY)
			printf("\t\t\t\t" BOLDRED "Failed" RESET ": List is empty. Please insert some nodes and try again...\n");

		else if (STATUS == FAILURE)
			printf("\t\t\t\t" BOLDRED "Failed" RESET ": Creating loop in the list. Try again...\n");
                break;

            case 3:	/* find loop */
                if ((STATUS = find_loop(head)) == LOOP_DETECTED)
			printf("\t\t\t\t LOOP is detected.\n");

		else if (STATUS == LOOP_NOT_DETECTED)
			printf("\t\t\t\t LOOP is not detected.\n");
                break;

            case 4:	/* insert sorted */
                printf("Enter element: ");
                scanf("%d", &data);
                if (LIST_EMPTY == (STATUS = insert_sorted(&head, data)))
			printf("\t\t\t\t" BOLDRED "Failed" RESET ": List is empty. Please insert some nodes and try again...\n");

                else if (STATUS == FAILURE)
			printf("\t\t\t\t" BOLDRED "Failed" RESET ": inserting element\n\t\t\t\t\tTry again...\n");
                break;
#if 0
            case 6:	/* delete list */
                if (FAILURE == (STATUS = delete_list(&head)))
                    printf("\t\t\t\t" BOLDRED "Failed" RESET ": Deleting list. Try again...\n");
                
                else if (STATUS == LIST_EMPTY)
			printf("\t\t\t\t" BOLDRED "Failed" RESET ": List is empty. Please insert some nodes and try again...\n");
                break;

#endif
            case 5:	/* print list */
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
    printf("1. Insert \n");
    printf("2. Create loop\n");
    printf("3. Find loop\n");
    printf("4. insert sorted\n");
    printf("5. print list\n");
    scanf("%d", &choice);

    switch(choice)
    {
            case 1: printf(BOLDBLUE "Insert" RESET "\n"); break;
            case 2: printf(BOLDBLUE "Create loop" RESET "\n"); break;
            case 3: printf(BOLDBLUE "Find loop" RESET "\n"); break;
            case 4: printf(BOLDBLUE "Insert sorted" RESET "\n"); break;
            case 5: printf(BOLDBLUE "print list" RESET "\n"); break;
    }

    return choice;
}
