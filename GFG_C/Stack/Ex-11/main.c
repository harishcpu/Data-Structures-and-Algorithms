/* ------------------------------------------------------------------------------ 
 *   Author         : HARISH
 *   Date           : Feb 09
 *   File           : main.c
 *   Title          : Driver function
 *   Description    : This function acts like a driver function, it invokes all
                        other sub functions. It is user interactive.
 * ---------------------------------------------------------------------------- */
#include "Stack.h"

int main()
{               /* allocate the memory for stack */
        STACK_ary *Stack = malloc(sizeof(STACK_ary));
        if (Stack == NULL)
                return FAILURE;
        /* initialize the top */
        Stack->top = -1;
        int status;
        data_t data;
        do
        {
                switch (select_operation())
                {
                        case 1:         /* push */
                                printf("Enter the data to push: ");
                                scanf("%d", &data);
                                if ((status = push(Stack, data)) == STACK_EMPTY)
                                        printf("Failed: Stack is empty\n");
                                break;
                        case 2:         /* pop */
                                if ((status = pop(Stack, &data)) == STACK_EMPTY)
                                        printf("Failed: Stack is empty\n");
                                else if(status == SUCCESS)
                                        printf("\t\t\t\t%d\n", data);
                                break;
                        case 3:         /* peak */
                                if ((status = peak(Stack)) == STACK_EMPTY)
                                        printf("Failed: Stack is empty\n");
                                break;
                        case 4:         /* peap */
                                if ((status = peap(Stack)) == STACK_EMPTY)
                                        printf("Failed: Stack is empty\n");
                                break;
                        default:
                                printf("Wrong choice\nTry again...");
                                break;
                }
                printf("Do you want to continue?...(y/n)");
                getchar();
        } while ((getchar()) != 'n');
        return 0;
}

int select_operation()
{
        int choice;

        printf("Options:\n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. peak\n");
        printf("4. peap\n");
        scanf("%d", &choice);
        return choice;
}
