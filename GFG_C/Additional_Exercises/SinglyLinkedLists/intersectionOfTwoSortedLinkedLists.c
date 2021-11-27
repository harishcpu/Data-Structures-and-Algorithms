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
void intersectionOfTwoSortedLinkedLists(Node **list1, Node *list2, Node *list3);
void addToTheList(Node **resList, data_t data);

int main() {
    Node *list1 = NULL;
    Node *list2 = NULL;
    Node *list3 = NULL;
    insertNode(&list1, 1);
    insertNode(&list1, 2);
    insertNode(&list1, 3);
    insertNode(&list1, 4);
    insertNode(&list1, 6);

    insertNode(&list2, 2);
    insertNode(&list2, 4);
    insertNode(&list2, 6);
    insertNode(&list2, 8);
    printList(list1);
    printList(list2);
    intersectionOfTwoSortedLinkedLists(&list3, list1, list2);
    printList(list3);
    return 0;
}

Node *createNode(data_t data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int insertNode(Node **head, data_t data) {
    if(*head == NULL) {
        *head = createNode(data);
        return 0;
    }
    Node *temp = *head;
    Node *newNode = createNode(data);
    while(temp->next) 
        temp = temp->next;
    temp->next = newNode;
}

void intersectionOfTwoSortedLinkedLists(Node **resList, Node *list1, Node *list2) {
    if(list1->data >= list2->data) {
        Node *temp = list1;
        list1 = list2;
        list2 = temp;
    }
    while(list1) {
        while(list2) {
            if(list1->data == list2->data)
                addToTheList(resList, list1->data);
            if(list2->data < list1->data)
                list2 = list2->next;
            else
                break;
        }
        list1 = list1->next;
    }
}

void addToTheList(Node **resList, data_t data) {
    if((*resList) == NULL) {
        *resList = createNode(data);
        return;
    }
    Node *temp = *resList;
    while(temp->next)
        temp = temp->next;
    temp->next = createNode(data);
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