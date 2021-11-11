#include <stdio.h>
#include <stdlib.h>

typedef int data_t;
typedef struct _node {
	data_t data;
	struct _node *next;
}Node;

void push(Node **head, data_t data);
void printList(Node *head);
void deleteNode(Node **head, data_t key);
Node *newNode(data_t data);

Node *newNode(data_t data) {
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void push(Node **head, data_t data) {
	Node *curr = *head;

	// check if list if empty
	if(curr == NULL) {
		curr = (Node *)malloc(sizeof(Node));
		curr->data = data;
		curr->next = NULL;
		*head = curr;
		return;
	}

	// if not empty
	while(curr->next != NULL)
		curr = curr->next;

	curr->next = newNode(data);
	return;
}

void printList(Node *head) {
	if(head == NULL){
                printf("list is empty\n");
                return;
        }
        while(head) {
		printf("%d ", head->data);
		head = head->next;
	}
        putc('\n', stdout);
}

void deleteNode(Node **head, data_t data) {
       // check if list is empty
       if(*head == NULL) {
               printf("the list is empty\n");
               return;
       }
       // if not empty
       // if list has only one node
                if((*head)->data == data){
                        Node *temp = *head;
                        *head = (*head)->next;
                        free(temp);
                        return;
                }

       // if list has more than one node
       Node *curr = *head;
       Node *prev = NULL;
       while(curr->data != data) {
               prev = curr;
               curr = curr->next;
               if(curr == NULL) {
                       printf("key is not found in the list\n");
                       return;
               }
       }
       prev->next = curr->next;
       free(curr);
}

int main() {
	Node *head = NULL;
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	printList(head);
	deleteNode(&head, 13);
        printList(head);
	deleteNode(&head, 1);
        printList(head);
	deleteNode(&head, 3);
        printList(head);
	deleteNode(&head, 2);
        printList(head);
}
