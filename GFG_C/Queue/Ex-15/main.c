#include "queue.h"

int main()
{
        Q_ary *Q = (Q_ary *)malloc(sizeof(Q_ary));
        if (Q == NULL)
                return FAILURE;
        Q->front = -1;
        Q->rear = -1;
        data_t data;
        do
        {
                switch (select_operation())
                {
                        case 1:         /* enqueue */
                                printf("Enter the data: ");
                                scanf("%d", &data);
                                if (enqueue(Q, data) == Q_FULL)
                                        printf("Queue is full\n");
                                else
                                        printf("Success\n");
                                break;
                        case 2:         /* dequeue */
                                if (dequeue(Q, &data) == Q_EMPTY)
                                        printf("Queue is empty\n");
                                else
                                        printf("\t\t\t\t%d\n", data);
                                break;
                        case 3:         /* display */
                                if (display(Q) == Q_EMPTY)
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
