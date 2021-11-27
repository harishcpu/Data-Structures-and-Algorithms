#include <stdio.h>
#include <stdlib.h>

typedef int data_t;
typedef struct _node {
    data_t data;
    struct _node* next;
}Node;

/* this function returns true if given linked list is circular, else false */
int isCircular(Node *head) {
    // an empty linked list is circular
    if(head == NULL) {
        return 1;
    }

    // next of head
    Node *node = head->next;

    // this loop would stop in on both cases (1) if 
    // circular (2) not circular
    while(node != NULL && node != head)
        node = node->next;

    // if loop stopped because of circular condition
    return (node == head);
}

// utility function to create a new node
Node *createNewNode(int data) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// driver program to test above function
int main() {
    // start with the empty list
    Node *head = createNewNode(1);
    head->next = createNewNode(2);
    head->next->next = createNewNode(3);
    head->next->next->next = createNewNode(4);

    isCircular(head) ? printf("Yes\n") : printf("No\n");

    // making linked list circular
    head->next->next->next->next = head;

    isCircular(head) ? printf("Yes\n") : printf("No\n");

    return 0;
}