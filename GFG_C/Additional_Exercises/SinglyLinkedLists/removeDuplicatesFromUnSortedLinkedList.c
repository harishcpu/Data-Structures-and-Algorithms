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
    insertNode(&head, 30);
    insertNode(&head, 20);
    insertNode(&head, 30);
    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);
    insertNode(&head, 30);
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
    Node *temp = *head;
    *head = createNode(data);
    (*head)->next = temp;
}

// remove duplicates from an unsorted linked list
int removeDuplicates(Node **head) {
    Node *i = *head;
    Node *j = i;

    Node *prev = NULL;
    while(i) {
        j = i->next;
        prev = i;
        while(j) {
            if(i->data == j->data) {
                prev->next = j->next;
                free(j);
                j = prev;
            }
            prev = j;
            j = j->next;
        }
        i = i->next;
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