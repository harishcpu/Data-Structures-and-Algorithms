#include <stdio.h>
#include <stdlib.h>

typedef int data_t;
typedef struct _node {
    data_t data;
    struct _node *next;
}Node;

Node *addToEmpty(Node *last, int data) {
    // this function is only for empty list
    if (last != NULL)
        return last;
    
    // creating a node dynamically
    Node *temp = (Node *)malloc(sizeof(Node));

    // assigning the data
    temp->data = data;
    last = temp;

    // creating the link
    last->next = last;

    return last;
}

Node *addBegin(Node *last, int data) {
    if(last == NULL)
        return addToEmpty(last, data);
    
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = last->next;
    last->next = temp;

    return last;
}

Node *addEnd(Node *last, int data) {
    if(last == NULL)
        return addToEmpty(last, data);
    
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = last->data;
    last->next = temp;
    last = temp;

    return last;
}

Node *addAfter(Node *last, int data, int item) {
    if(last == NULL)
        return NULL;

    Node *temp, *p;
    p = last->next;
    do {
        if(p->data == item) {
            temp = (Node *)malloc(sizeof(Node));
            temp->data = data;
            temp->next = p->next;
            p->next = temp;

            if(p == last)
                last = temp;
            
            return last;
        }
        p = p->next;
    } while(p != last->next);

    printf("not present in the list.\n");
    return last;
}

void traverse(Node *last) {
    Node *p;
    // if list is empty, return
    if(last == NULL) {
        printf("list is empty.\n");
        return;
    }

    // pointing to first node of the list
    p =  last->next;

    // traverse the list
    do {
        printf("%d ",p->data);
        p = p->next;
    } while(p != last->next);
}

int main() {
    Node *last = NULL;

    last = addToEmpty(last, 6);
    last = addBegin(last, 4);
    last = addBegin(last, 2);
    last = addEnd(last, 8);
    last = addEnd(last, 12);
    last = addAfter(last, 10, 8);

    traverse(last);
    
    return 0;
}