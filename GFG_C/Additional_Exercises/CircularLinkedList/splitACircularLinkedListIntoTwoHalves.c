#include <stdio.h>
#include <stdlib.h>

/* structure of a node */
typedef struct _node {
    int data;
    struct _node *next;
}Node;

/* function to split a list(starting with head) into two lists. 
  list1 and list2 are references to head nodes of the two resultant linked lists */
void splitList(Node *head, Node **list1, Node **list2) {
    Node *slow = head;
    Node *fast = head;

    if(head == NULL)
        return;

    /* If there are odd nodes in the circular list then 
       fast->next becomes head and for even nodes fast->next->next 
       becomes head */
    while(fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

    /* If there are even elements in list then move fast */
    if(fast->next->next == head) {
        fast = fast->next;
    }

    /* set the head pointer of first half */
    *list1 = head;

    /* set the head pointer of second half */
    if (head->next != head) {
        *list2 = slow->next;
    }

    /* make second half circular */
    fast->next = slow->next;

    /* make first half circular */
    slow->next = head;
}

/* Utility functions */
/* Function to insert a node at the beginning of a circular 
   linked list */
void push(Node **head, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *temp = *head;
    newNode->data = data;
    newNode->next = *head;

    /* If linked list is not NULL then set the next of last node */
    if(*head != NULL) {
        while(temp->next != *head)
            temp = temp->next;
        temp->next = newNode;
    } else {
        newNode->next = newNode; /* for the first node */
    }

    *head = newNode;
}

/* function to print nodes in a given circular linked list */
void printList(Node *head) {
    Node *temp = head;
    if(head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while(temp != head);
    }
}

/* Driver program to test above functions */
int main() {
    int list_size, i;

    /* initialize lists as empty */
    Node *head = NULL;
    Node *head1 = NULL;
    Node *head2 = NULL;

    /* created linked list will be 12->56->2->11 */
    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);

    printf("Original Circular Linked List: ");
    printList(head);

    /* Split the list */
    splitList(head, &head1, &head2);

    printf("\nFirst Circular Linked List: ");
    printList(head1);
    printf("\nSecond Circular Linked List: ");
    printList(head2);
    
    return 0;
}