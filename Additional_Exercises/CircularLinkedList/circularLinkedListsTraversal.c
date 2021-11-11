#include <stdio.h>
#include <stdlib.h>

typedef int data_t;
typedef struct _node {
    data_t data;
    struct _node *next;
}Node;

void push(Node **head, data_t data);
void printList(Node *head);

int main() {
    // initialize list as empty
    Node *head = NULL;

    // created linked list will be 11->2->56->12
    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);

    printf("Contents of Circular Linked List: ");
    printList(head);

    return 0;
}

void push(Node **head, data_t data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *temp = *head;
    newNode->data = data;
    newNode->next = *head;

    if(*head != NULL) {
        while(temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
    } else {
        newNode->next = newNode;
    }
    *head = newNode;
}

void printList(Node *head) {
    Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != head);
    putc('\n', stdout);
}