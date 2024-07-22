#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data ;
	struct node *next;
}node;

node *head = NULL ;

void DisplayLL(){
	node *ptr ;
	ptr = head ;
	while (ptr != NULL){
		printf("%d ",ptr->data);
		ptr = ptr->next ;
	}
	printf("\n");
}
void DisplayAddressLL(){
	node *ptr ;
	ptr = head ;
	while (ptr != NULL){
		printf("Node val = %d,add=%X\t",ptr->data,ptr);
		printf("Next node add=%X\n",ptr->next);
		ptr = ptr->next;
	}
}

void insertLL(int x){
	node *new_node , *ptr , *preptr;
	new_node = (node*)malloc(sizeof(node));
	new_node->data = x;
	new_node->next = NULL ;
	if (new_node->data < head->data){
		new_node->next = head ;
		head = new_node ;
	}else{
		ptr = head;
		while (ptr != NULL && ptr->data < new_node->data){
			preptr = ptr ;
			ptr = ptr->next;
		}
		new_node->next = preptr->next;
		preptr->next = new_node ;
	}
}

int main (){
	int n , i ,value;
	srand(time(NULL));
	printf("Enter n : ");
	scanf("%d",&n);
	node *new_node , *ptr , *preptr;
	for (i=0;i<n;i++){
		new_node = (node*)malloc(sizeof(node));
		new_node->data = rand()%100 + 1;
		printf("%d ",new_node->data);
		new_node->next = NULL ;
		
		if (head == NULL){
			head = new_node ;
		}else if(new_node->data<head->data){
			new_node->next = head ; 
			head = new_node ;
		}else{
			ptr = head ;
			while(ptr != NULL && ptr->data < new_node->data){	
				preptr = ptr ;
				ptr = ptr->next ;
			} 
            new_node->next = preptr->next;
            preptr->next = new_node;	
		}
	}
	printf("\n");
	DisplayLL();
	printf("Enter value of newnode : ");
	scanf("%d",&value);
	insertLL(value);
	DisplayLL();
}
