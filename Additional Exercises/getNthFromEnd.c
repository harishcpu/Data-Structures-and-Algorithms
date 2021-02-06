#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0

typedef int data_t;
typedef struct _node {
    data_t data;
    struct _node *next;
}Node;

int createALinkedList(Node **head);
int printList(Node *head);
int getNthNodeFromEnd(Node* head, int n);

int main() {
    // create a linked list
    Node *head = NULL;
    createALinkedList(&head);
    printList(head);
    
    printf("Nth node from end: %d\n", getNthNodeFromEnd(head, 10));
    return SUCCESS;
}

int printList(Node *head) {
    while(head) {
        printf("%d->", head->data);
        head = head->next;
    }
    puts("NULL");
    putc('\n', stdout);
}

int createALinkedList(Node **head) {
    int i = 0;
    (*head) = (Node *)malloc(sizeof(Node));
    Node *temp = *head;
    while(i < 9) {
        (temp)->data = i++;
        (temp)->next = (Node *)malloc(sizeof(Node));
        temp = temp->next;
    }
    temp->data = i;
    temp->next = NULL;

    return SUCCESS;
}

int getNthNodeFromEnd(Node *head, int n) {
    int count = 0;
    Node *temp = head;
    
    while(temp) {
        temp = temp->next;
        ++count;
    }

    if(count < n)
        return EXIT_FAILURE;

    temp = head;

    for(int i = 0; i < count - n; i++) {
        temp = temp->next;
    }

    return temp->data;
}