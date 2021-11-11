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
void pairwiseSwap(Node **head);

int main() {
    Node *head = NULL;

    insertNode(&head, 5);
    insertNode(&head, 10);
    insertNode(&head, 15);
    insertNode(&head, 20);
    insertNode(&head, 25);
    insertNode(&head, 30);
    insertNode(&head, 35);
    insertNode(&head, 40);
    printList(head);
    pairwiseSwap(&head);
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

void pairwiseSwap(Node **head) {
    Node *temp = *head;
    while(temp && temp->next) {
        data_t data = temp->data;
        temp->data = temp->next->data;
        temp->next->data = data;

        temp = temp->next->next;
    }
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