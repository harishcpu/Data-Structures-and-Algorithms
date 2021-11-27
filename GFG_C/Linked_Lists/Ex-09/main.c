/* ------------------------------------------------------------------------------ 
 *   Author         : HARISH
 *   Date           : Feb 09
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

            case 2:	/* remove duplicates */
                if ((STATUS = remove_duplicates(&head)) == LIST_EMPTY)
			printf("\t\t\t\t" BOLDRED "Failed" RESET ": List is empty. Please insert some nodes and try again...\n");

		else if (STATUS == FAILURE)
			printf("\t\t\t\t" BOLDRED "Failed" RESET ": Creating loop in the list. Try again...\n");
                break;

            case 3:	/* print list */
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
    printf("2. Remove duplicates\n");
    printf("3. print list\n");
    scanf("%d", &choice);

    switch(choice)
    {
            case 1: printf(BOLDBLUE "Insert" RESET "\n"); break;
            case 2: printf(BOLDBLUE "Remove duplicates" RESET "\n"); break;
            case 3: printf(BOLDBLUE "print list" RESET "\n"); break;
    }

    return choice;
}
