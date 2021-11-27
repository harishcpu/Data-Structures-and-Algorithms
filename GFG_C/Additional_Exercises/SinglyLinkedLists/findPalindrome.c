#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

typedef int data_t;
typedef struct _node {
    data_t data;
    struct _node *next;
}Node;

int createALinkedList(Node **head);
int printList(Node *head);
int findPalindrome(Node *head);

int main() {
    // create a linked list
    Node *head = NULL;
    createALinkedList(&head);
   // printList(head);
    
    findPalindrome(head) ? printf("Palindrome. ") : printf("Not a Palindrome. ");
   // printf("loop length: %d\n", findLoop(head));
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
    int j = 0;
    (*head) = (Node *)malloc(sizeof(Node));
    Node *temp = *head;
    while(i < 9) {
        if(i == 5)
            j = 0;
        (temp)->data = j++;
        (temp)->next = (Node *)malloc(sizeof(Node));
        temp = temp->next;
    }
    temp->data = i;
    temp->next = *head;
}

int findPalindrome(Node *head) {
    Node *slow = head;
    Node *fast = head;

    while(slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = head;
    while(fast && slow) {
        if(fast->data != slow->data) {
            return FALSE;
        }
        fast = fast->next;
        slow = slow->next;
    }
    return TRUE;
}