#include "queue.h"

int main()
{
        Qlist *front = NULL;
        Qlist *rear = NULL;
        data_t data;
        
        do
        {
                switch (select_operation())
                {
                        case 1:         /* enqueue */
                                printf("Enter the data: ");
                                scanf("%d", &data);
                                if (enqueue(&front, &rear, data) == Q_FULL)
                                        printf("Queue is full\n");
                                break;
                        case 2:         /* dequeue */
                                if (dequeue(&front, &rear, &data) == Q_EMPTY)
                                        printf("Queue is empty\n");
                                else
                                        printf("\t\t\t\t%d\n", data);
                                break;
                        case 3:         /* display */
                                if (display(front) == Q_EMPTY)
                                        printf("Queue is empty\n");
                                break;
                        default:
                                printf("Invalid choice...Try again...\n");
                }
                printf("Do you want to continue?... (y/n) "); getchar();
        } while (getchar() != 'n');
}

int select_operation()
{
        int choice;

        printf("\t1. Enqueue\n");
        printf("\t2. Dequeue\n");
        printf("\t3. Display\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        return choice;
}
