#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE 1
#define TRUE 1
#define FALSE 0

typedef int data_t;
typedef struct _node {
    data_t data;
    struct _node *next;
}Node;

Node *createNode(data_t data);
int insertNode(Node **head, data_t data);
int deleteNode(Node **head, data_t data);
void printList(Node *head);

int main() {
    Node *head = createNode(10);

    insertNode(&head, 15);
    insertNode(&head, 20);
    insertNode(&head, 30);
    puts("The list: ");
    printList(head);

    deleteNode(&head, 15);
    puts("List after deleting the node with data 15 is ");
    printList(head);

    return SUCCESS;
}

Node *createNode(data_t data) {
    Node *newNode = (Node  *)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

int insertNode(Node **head, data_t data) {
    Node *temp = *head;
    while(temp->next)
        temp = temp->next;   
    temp->next = createNode(data);

    return SUCCESS;
}

int deleteNode(Node **head, data_t data) {
    Node *temp = *head;
    Node *temp1 = NULL;
    while(temp && temp->data != data) {
        temp1 = temp;
        temp = temp->next;
    }
    
    if(!temp)
        return FAILURE;

    temp1->next = temp->next;
    free(temp);

    return SUCCESS;
}

void printList(Node *head) {
    while(head) {
        printf("%d->", head->data);
        head = head->next;
    }
    puts("NULL");
    putc('\n', stdout);
}