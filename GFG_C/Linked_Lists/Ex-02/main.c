#include "Sll.h"

int main()
{
    system("clear");
    Slist *head = NULL;
    data_t g_data, n_data;
    int choice;
    int position, ret;

    do
    {
        choice = select_operation();
        switch(choice)
        {
            case 1:
                printf("Enter the number to insert: \n");
                scanf("%d", &n_data);
                if (insert_at_last(&head, n_data) == FAILURE)
                {
                    printf("Failed: Inserting new data at last\nTry again...\n");
                }
                break;
            case 2:
                printf("Enter g_data : \n");
                scanf("%d", &g_data);
                printf("Enter n_data: \n");
                scanf("%d", &n_data);
                if ((ret = sl_insert_after(head, g_data, n_data)) == DATA_NOT_FOUND)
                {
                    printf("Failed: The data is not found\nTry again...\n");
                } else if (ret == LIST_EMPTY)
                        printf("Failed: The list is empty\nTry again...\n");
                break;
            case 3:
                printf("Enter g_data : \n");
                scanf("%d", &g_data);
                printf("Enter n_data: \n");
                scanf("%d", &n_data);
                if ((ret = sl_insert_before(&head, g_data, n_data)) == DATA_NOT_FOUND)
                {
                    printf("Failed: The data is not found\nTry again...\n");
                } else if (ret == LIST_EMPTY)
                        printf("Failed: The list is empty\nTry again...\n");
                break;
            case 4:
                printf("Enter g_data : \n");
                scanf("%d", &g_data);
                if ((ret = delete_element(&head, g_data)) == DATA_NOT_FOUND)
                {
                    printf("Failed: The data is not found\nTry again...\n");
                } else if (ret == LIST_EMPTY)
                        printf("Failed: The list is empty\nTry again...\n");
                break;
            case 5:
                printf("Enter position : \n");
                scanf("%d", &position);
                printf("Enter n_data: \n");
                scanf("%d", &n_data);
                if ((ret = sl_insert_nth(&head, position, n_data)) == POSITION_NOT_FOUND)
                {
                    printf("Failed: The Position is not found\nTry again...\n");
                } else if (ret == LIST_EMPTY)
                        printf("Failed: The list is empty\nTry again...\n");
                break;
            case 6:
                print_list(head);
                break;
            case 7:
                if (FAILURE == delete_list(&head))
                {
                    printf("FAILURE: freeing list\nTry again...\n");
                }
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
    printf("\t1. Insert_last\n");
    printf("\t2. Insert_after\n");
    printf("\t3. Insert_before\n");
    printf("\t4. Delete_element\n");
    printf("\t5. Insert_nth\n");
    printf("\t6. Print list\n");
    printf("\t7. delete_list\n");
    scanf("%d", &choice);

    return choice;
}
