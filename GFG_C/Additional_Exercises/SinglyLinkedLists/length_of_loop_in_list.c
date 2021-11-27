#include <stdio.h>
#include <stdlib.h>

struct _node
{
        int data;
        struct _node* next;
};

int countNodes(struct _node *node)
{
        int n = 1;
        struct _node *temp = node;

        /* count the nodes in the found loop */
        while (temp->next != node)
        {
                ++n;
                temp = temp->next;
        }
        return n;
}

int countNodesinLoop(struct _node *head)
{
        struct _node *slow, *fast;
        slow = fast = head;

        while (slow && fast && fast->next)
        {
                /* if loop found */
                if (slow == fast)
                        return countNodes(slow);

                slow = slow->next;
                fast = fast->next->next;
        }
        /* if there is no loop */
        return 0;
}

struct _node* newNode(int key)
{
        struct _node* new = (struct _node*)malloc(sizeof (struct _node));
        if (new == NULL)
        {
                printf("Error: heap overflow\n");
                exit(0);
        }

        new->data = key;
        new->next = NULL;

        return new;
}

int main(void)
{
    struct _node *head = newNode(1); 
    head->next = newNode(2); 
    head->next->next = newNode(3); 
    head->next->next->next = newNode(4); 
    head->next->next->next->next = newNode(5); 
  
    struct _node *temp = head;
    printf("The list: ");
    while (temp)
    {
            printf("%d->", temp->data);
            temp = temp->next;
    }
    putchar('\n');

    /* Create a loop for testing */
    head->next->next->next->next = head; 

    printf("No. of nodes in loop: %d\n", countNodesinLoop(head));
    return 0;
}
