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
int intersectionPoint(Node *list1, Node *list2);

int main() {
    Node *list1 = NULL;
    Node *list2 = NULL;
    insertNode(&list1, 1);
    insertNode(&list1, 2);
    insertNode(&list1, 3);
    insertNode(&list1, 4);
    insertNode(&list1, 6);

    insertNode(&list2, 1);
    list2->next = list1->next->next->next;
    printList(list1);
    printList(list2);
    printf("The intersection point is %d\n", intersectionPoint(list1, list2));
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

// returns the intersection point of two linked lists. Uses hash technique.
int intersectionPoint(Node *list1, Node *list2) {
    Node *hashSet[10];
    int i = 0;
    while(list1) {
        hashSet[i++] = list1;
        list1 = list1->next;
    }
    int j;
    while(list2) {
        j = 0;
        while(j < i) {
            if(hashSet[j] == list2)
                return list2->data;
            j++;
        }
        list2 = list2->next;
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