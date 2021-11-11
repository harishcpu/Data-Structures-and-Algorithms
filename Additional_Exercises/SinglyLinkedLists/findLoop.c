#include <stdio.h>
#include <stdlib.h>

#define LOOP_FOUND 1
#define LOOP_NOT_FOUND 0

typedef int data_t;
typedef struct _node {
    data_t data;
    struct _node *next;
}Node;

int createALinkedList(Node **head);
int printList(Node *head);
int findLoop(Node *head);

int main() {
    // create a linked list
    Node *head = NULL;
    createALinkedList(&head);
   // printList(head);
    
    findLoop(head) ? printf("Loop found\n") : printf("loop not found");
    return 0;
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
    temp->next = *head;
}

int findLoop(Node *head) {
    Node *slow = head;
    Node *fast = head;

    while(slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return LOOP_FOUND;
    }
    return LOOP_NOT_FOUND;
}