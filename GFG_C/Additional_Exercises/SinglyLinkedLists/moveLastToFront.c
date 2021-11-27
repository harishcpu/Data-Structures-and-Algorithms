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
void moveLastToFront(Node **head);

int main() {
    Node *head = NULL;

    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);
    printList(head);
    moveLastToFront(&head);
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
    Node *temp = *head;
    *head = createNode(data);
    (*head)->next = temp;
}

void moveLastToFront(Node **head) {
    Node *last = *head;
    Node *secLast = NULL;
    while(last->next) {
        secLast = last;
        last = last->next;
    }
    last->next = (*head);
    secLast->next = NULL;
    *head = last;
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