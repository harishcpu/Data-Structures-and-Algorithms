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
void swapNodes(Node **head, data_t data1, data_t data2);
Node *createNode(data_t data);
void printList(Node *head);

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
    swapNodes(&head, 35, 5);
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

void swapNodes(Node **head, data_t data1, data_t data2) {
   Node *node1 = NULL;
   Node *node2 = NULL;

   Node *temp = *head;
   Node *prev = NULL;
   while(temp) {
       if(temp->data == data1)
            node1 = prev;
       if(temp->data == data2)
            node2 = prev;
       prev = temp;
       temp = temp->next;
   }
   temp = node1->next;
   node1->next = node2->next;
   node2->next = temp;
   temp = node1->next->next;
   node1->next->next = node2->next->next;
   node2->next->next = temp;
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