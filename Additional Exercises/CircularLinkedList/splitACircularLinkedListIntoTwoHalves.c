#include <stdio.h>
#include <stdlib.h>

typedef int data_t;
typedef struct _node {
    data_t data;
    struct _node *next;
}Node;

void push(Node **head, data_t data);
void printList(Node *head);
void splitList(Node *head, Node **list1, Node **list2);

int main() {
    // initialize list as empty
    Node *head = NULL;
    Node *list1 = NULL;
    Node *list2 = NULL;

    // created linked list will be 11->2->56->12
    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);
    printList(head);

    splitList(head, &list1, &list2);
    
    printList(list1);
    printList(list2);

    return 0;
}

void push(Node **head, data_t data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *temp = *head;
    newNode->data = data;
    newNode->next = *head;

    if(*head != NULL) {
        while(temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
    } else {
        newNode->next = newNode;
    }
    *head = newNode;
}

void printList(Node *head) {
    Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != head);
    putc('\n', stdout);
}

void splitList(Node *head, Node **list1, Node **list2) {
    Node *slow = NULL;
    Node *fast = NULL;

    if(head == NULL)
        return;
    
    /* if there are odd nodes in the circular list then fast->next 
    becomes head and for even nodes fast->next->next becomes head */
    while(fast->next != head && fast->next->next != head)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    /* if there are even elements in list then move fast pointer */
    if(fast->next->next == head) {
        fast = fast->next;
    }

    /* set the head pointer of first half */
    *list1 = head;
    /* set the head pointer of second half */
    if(head->next != head) 
        *list2 = slow->next;

    /* make the second half circular */
    fast->next = slow->next;

    /* make the first half circular */
    slow->next = head;
}