/* ------------------------------------------------------------------------------ 
 *   Author         : HARISH
 *   Date           : Feb 6
 *   File           : main.c
 *   Title          : Driver function
 *   Description    : This function acts like a driver function, it is user 
					  interactive.  
 * ---------------------------------------------------------------------------- */
#include "Dll.h"

int main()
{
    system("clear");

    Dlist *head = NULL;
    Dlist *tail = NULL;

    int choice;
    int g_data, n_data;
    char status;
    data_t data;

    do
    {
        choice = select_operation();
        switch(choice)
        {
            case 1:
                printf("Enter the n_data\n");
                scanf("%d", &n_data);
                printf("Enter the g_data\n");
                scanf("%d", &g_data);
                if ((status = dl_insert_after(&head, &tail, g_data, n_data)) == LIST_EMPTY)
                    printf("Failed: List is empty\nTry again...\n");
                else if (status == DATA_NOT_FOUND)
                        printf("Failed: The n_data is not found\nTry again\n");
                break;

            case 2:
                printf("Enter the n_data\n");
                scanf("%d", &n_data);
                printf("Enter the g_data\n");
                scanf("%d", &g_data);
                if ((status = dl_insert_before(&head, &tail, g_data, n_data)) == LIST_EMPTY)
                    printf("Failed: List is empty\nTry again...\n");
                else if (status == DATA_NOT_FOUND)
                        printf("Failed: The n_data is not found\nTry again\n");
                break;
            case 3:
                if (dl_delete_list(&head) == LIST_EMPTY)
                {
                    printf("Failed: Deleting list\nTry again...\n");
                }
                break;
            case 4:
                printf("Enter the element: ");
                scanf("%d", &data);
                insert_last(&head, &tail, data);
                break;
            case 5:
                print_list_from_head(head);
                break;
            default:
                printf("Wrong choice\nTry again...\n");
                break;
        }
        printf("Do you want to continue...y/n ");
        getchar();
    } while (getchar() != 'n');
    return 0;
}

int select_operation(void)
{
    int choice;

    printf("Options: \n");
    printf("1. Insert after\n");
    printf("2. Insert before\n");
    printf("3. Delete list\n");
    printf("4. Insert\n");
    printf("5. Print list\n");
    scanf("%d", &choice);

    return choice;
}
