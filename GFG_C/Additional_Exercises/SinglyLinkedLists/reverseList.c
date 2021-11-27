#include <stdio.h>
#include <stdlib.h>

#define TRUE 0
#define SUCCESS 0
#define FALSE 1
#define FAILURE 1

typedef int data_t;
typedef struct _node {
    data_t data;
    struct _node *next;
}Node;

int insertNode(Node **head, data_t data);
Node *createNode(data_t data);
void printList(Node *head);
void reverseList(Node **head);

int main() {
    Node *head = NULL;

    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);
    insertNode(&head, 6);
    insertNode(&head, 7);
    printList(head);
    
    reverseList(&head);
    printList(head);
    
    return 0;
}

Node *createNode(data_t data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int insertNode(Node **head, data_t data) {
    if(*head == NULL) {
        *head = createNode(data);
        return 0;
    }
    Node *temp = *head;
    Node *newNode = createNode(data);
    while(temp->next) 
        temp = temp->next;
    temp->next = newNode;
}

void printList(Node *head) {
    while(head) {
        printf("%d->", head->data);
        head = head->next;
    }
    puts("NULL");
    putc('\n', stdout);
    return;
}

void reverseList(Node **head) {
    Node *prev = NULL;
    Node *curr = *head;
    Node *next = NULL;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}
