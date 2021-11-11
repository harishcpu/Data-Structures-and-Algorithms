#include <stdio.h>
#include <stdlib.h>

typedef int data_t;
typedef struct _node {
    data_t data;
    struct _node *next;
}Node;

void sortedInsert(Node **head_ref, Node *new_node);
void printList(Node *start);

/* driver code */
int main() {
    int arr[] = {12, 56, 2, 11, 1, 90};
    int list_size, i;

    /* start with empty linked list */
    Node *start = NULL;
    Node *temp;

    /* create linked list from the array arr[].
       created linked list will be 1->2->11->12->56->90 */
    for(i = 0; i < 6; i++) {
        temp = (Node *)malloc(sizeof(Node));
        temp->data = arr[i];
        sortedInsert(&start, temp);
    }

    printList(start);

    return 0;
}

/* function to insert a new node in sorted way.
Note that this function expects a pointer to head node 
as this can modify the head of the input linked list */
void sortedInsert(Node **head, Node *newNode) {
    Node *curr = *head;

    /* case 1 of the above algorithm */
    if(curr == NULL) {
        newNode->next = newNode;
        *head = newNode;
    }

    /* case 2 of the above algorithm */
    else if (curr->data >= newNode->data) {
        /* if value is smaller than head's value then we need to change next of last node */
        while(curr->next != *head) {
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }

    /* case 3 of the above algorithm */
    else {
        /* locate the node before the point insertion */
        while(curr->next != *head && curr->next->data < newNode->data)
            curr = curr->next;

        newNode->next = curr->next;
        curr->next = newNode;
    }
}

/* function to print nodes in a given linked list */
void printList(Node *start) {
    Node *temp;
    
    if(start != NULL) {
        temp = start;
        printf("\n");
         do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while(temp != start);
    }
}