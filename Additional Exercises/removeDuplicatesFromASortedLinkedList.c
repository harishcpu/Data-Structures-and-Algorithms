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
int removeDuplicates(Node **head);
Node *createNode(data_t data);
void printList(Node *head);

int main() {
    Node *head = NULL;

    insertNode(&head, 10);
    printList(head);
    insertNode(&head, 30);
    insertNode(&head, 10);
    printList(head);
    insertNode(&head, 20);
    printList(head);
    insertNode(&head, 10);
    insertNode(&head, 30);
    insertNode(&head, 20);
    insertNode(&head, 30);
    insertNode(&head, 20);
    printList(head);
    removeDuplicates(&head);
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
    Node *temp = NULL;
    // if the list is empty or has one node
    if(*head == NULL || (*head)->data >= data) {
        temp = createNode(data);
        temp->next = *head;
        *head = temp;
        return SUCCESS;
    }
    // if has more than one node
    temp = *head;
    while(temp->next && temp->next->data < data)
        temp = temp->next;
    Node *newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

int removeDuplicates(Node **head) {
    Node *current = *head;
    while(current->next) {
        if(current->data == current->next->data) {
            Node *temp = current->next;
            current->next = current->next->next;
            free(temp);
            continue;
        }
        current = current->next;
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