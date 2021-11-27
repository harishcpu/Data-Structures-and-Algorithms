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
    Slist *head, *head1, *head2;
    
    head = head1 = head2 = NULL;
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
                scanf("%d", &data); getchar();
                printf("Add this element to list 1/2?...enter(1 or 2) ");
                if (getchar() == '1')
                {
                        if (insert_at_last(&head1, data) == FAILURE)
			        printf("\t\t\t\t" BOLDRED "Failed" RESET ": Inserting new data at last\n\t\t\t\t\tTry again...\n");
                }
                else
                        if (insert_at_last(&head2, data) == FAILURE)
			        printf("\t\t\t\t" BOLDRED "Failed" RESET ": Inserting new data at last\n\t\t\t\t\tTry again...\n");
                break;

            case 2:	/* sort list */
                sort_by_values(&head1);
                sort_by_values(&head2);
                break;
            case 3:
                sorted_merge(&head, &head1, &head2);
                head1=NULL;
                head2=NULL;
                break;
            case 4:	/* print list */
                printf("YOu want to print which list 0/1/2?...enter(0 or 1 or 2) ");
                if ((STATUS = getchar()) == '1')
                        print_list(head1);
                else if (STATUS == '2')
                        print_list(head2);
                else
                        print_list(head);
                break;

            default:
                        printf(RED "Wrong choice" RESET "\nTry again...\n");
                break;
        }
        printf("Do you want to continue?...y/n  ");
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
    printf("\t3. Sorted merge\n");
    printf("\t4. Print list\n");
    printf("Your choice: ");
    scanf("%d", &choice); getchar();

    return choice;
}
