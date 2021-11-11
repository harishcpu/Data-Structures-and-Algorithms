/* C program to delete a given key from linked list */
#include <stdio.h>
#include <stdlib.h>

/* structure for a node */
typedef int data_t;
typedef struct _node {
    data_t data;
    struct _node *next;
}Node;

/* function to insert a node at the beginnig of a circular linked list */
void push(Node **head, data_t data) {
    // create a new node and make head as next of it
    Node *ptr1 = (Node *)malloc(sizeof(Node));
    ptr1->data = data;
    ptr1->next = *head;

    /* if linked list is not NULL then set the next of last node */
    if(*head != NULL) {
        // find the node before head and update next of it
        Node *temp = *head;
        while(temp->next != *head)
            temp = temp->next;
        temp->next = ptr1;
    } else {
        /* for the first node */
        ptr1->next = ptr1;
    }

    *head = ptr1;
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

    printf("\n");
}

/* function to delete a given node from the list */
void deleteNode(Node *head, data_t key) {
    if(head == NULL)
        return;

    // find the required node
    Node *curr = head, *prev;
    while(curr->data != key) {
        if(curr->data != key) {
            printf("\nGiven node is not found in the list!!!\n");
            break;
        }

        prev = curr;
        curr = curr->next;
    }

    // check if node is only node
    if(curr->next == head) {
        head = NULL;
        free(curr);
        return;
    }

    // if more than one node, check if it is first node
    if (curr == head) {
        prev = head;
        while(prev->next != head)
            prev = prev->next;
        head = curr->next;
        prev->next = head;
        free(curr);
    }

    // check if node is last node
    else if(curr->next == head && curr == head) {
        prev->next = head;
        free(curr);
    } else {
        prev->next = curr->next;
        free(curr);
    }
}

int main() {
    /* initialize lists as empty */
    Node *head = NULL;

    /* created linked list will be 2->5->7->8->10 */
    push(&head, 2);
    push(&head, 5);
    push(&head, 7);
    push(&head, 8);
    push(&head, 10);

    printf("list before deletion: ");
    printList(head);

    deleteNode(head, 7);

    printf("list after deletion: ");
    printList(head);

    return 0;
}