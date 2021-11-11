#include <stdio.h>
#include <stdlib.h>

#define TRUE 0
#define SUCCESS 0
#define FALSE 1

typedef int data_t;
typedef struct _node {
    data_t data;
    struct _node *next;
}Node;

Node *createNode(data_t data);
int insert(Node** head, data_t data);
void printList(Node* head);

int main() {
    // declare a pointer to hold the address of head
    // create a node with data 5
    Node* head = createNode(5);

    insert(&head, 10);
    insert(&head, 25);
    insert(&head, 20);
    insert(&head, 40);
    insert(&head, 30);
    insert(&head, 15);

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

int insert(Node **head, data_t data) {
    Node *temp = *head;

    // if list has only one node
    // if(temp->next == NULL) {
    //     if(temp->data <= data) {
    //         temp->next = createNode(data);
    //     } else if(temp->data > data) {
    //         Node *temp1 = createNode(data);
    //         temp1->next = temp;
    //     }
    //     return TRUE;
    // }
    
    Node *temp1 = temp;
    // traverse till you find the node which has lesser value than the argument 'data'
    while(temp && temp->data <= data) {
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = createNode(data);
    temp1->next->next = temp;

    return TRUE;
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