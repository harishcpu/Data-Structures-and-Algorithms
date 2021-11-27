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

Node *createNode(data_t data);
int insertFirst(Node **head, data_t data);
int insertLast(Node **head, data_t data);
int insertAfter(Node **head, data_t data1, data_t data2);
int insertLast();
void printList(Node* head);

int main() {
    Node *head = createNode(10);
    insertFirst(&head, 5);
    insertLast(&head, 15);
    insertAfter(&head, 12, 10);
    insertAfter(&head, 13, 12);
    insertAfter(&head, 20, 15);
    printList(head);

    return SUCCESS;
}

Node *createNode(data_t data) {
    // allocate memory for the new node
    Node *newNode = (Node *)malloc(sizeof(Node));

    // store the data in the members of the node
    newNode->data = data;
    newNode->next = NULL;

    // return the node
    return newNode;
}

int insertFirst(Node **head, data_t data) {
    Node *newNode = createNode(data);
    Node *temp = *head;
    *head = newNode;
    newNode->next = temp;

    return SUCCESS;
}

int insertLast(Node **head, data_t data) {
    Node *temp = *head;
    while((*head)->next) {
        (*head) = (*head)->next;
    }
    (*head)->next = createNode(data);

    *head = temp;
    return SUCCESS;
}

int insertAfter(Node **head, data_t data1, data_t data2) {
    Node *temp = *head;

    while(temp != NULL && temp->data != data2) {
        temp = temp->next;
    }

    if(temp != NULL) {
        Node *temp1 = temp->next;
        temp->next = createNode(data1);
        temp->next->next = temp1;
    }

    return SUCCESS;
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