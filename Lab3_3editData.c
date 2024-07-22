#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}node;

node *head;
node *newnode;

void showLL() {
	node *ptr = head;
	while(ptr!=NULL) {
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}


void main() {
	int i;
	srand((unsigned)time(NULL));
	for(i=0; i<5; i++) {
		newnode = (node *)malloc(sizeof(node));
		newnode->data = rand()%100+1;
		node *ptr = head, *preptr;
		
		if(head == NULL) {
			head = newnode;
			newnode->next = NULL;
		}else if(newnode->data<head->data) {
			newnode->next = head;
			head = newnode;
		}else{
			while(ptr!=NULL && newnode->data > ptr->data) {
				preptr = ptr;
				ptr = ptr->next;
			}	
			newnode->next = ptr;
			preptr->next = newnode;
		}
		showLL();
		printf("\n\n");
	}
	
	int n;
	scanf("%d",&n);
	node *ptr=head, *preptr;
	newnode = (node *)malloc(sizeof(node));
	newnode->data = n;
	if(newnode->data<head->data) {
		newnode->next = head;
		head = newnode;
	}else{
		while(ptr!=NULL && newnode->data > ptr->data) {
			preptr = ptr;
			ptr = ptr->next;
		}	
		newnode->next = ptr;
		preptr->next = newnode;
	}
	printf("\n");
	showLL();
}
