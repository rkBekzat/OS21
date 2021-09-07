#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node *nxt;
};

void print_list(struct node *head){
	struct node* cur = head;
	if(cur == NULL){
		printf("The linked list empty\n");
		return ;
	}
	printf("The linked lists: ");
	while(cur != NULL){
		printf("%d\n", cur->val);
		cur = cur->nxt;
	}
}

void insert_node(struct node **head, int newvalue, int prevnode){
	struct node* cur = *head;
	struct node* newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->val =  newvalue;
	if(cur == NULL){
		*head = newnode;
		(*head)->nxt = NULL;
		return ;
	}
	while(cur->val != prevnode){
		cur=cur->nxt;
		if(cur == NULL){
			printf("Failed: not added newnode, prevnode value doesn't exist in linked list\n");
			return ;
		}
	}
	if(cur->nxt == NULL){
		newnode->nxt = NULL;
	}
	else{
		newnode->nxt = cur->nxt->nxt;
	}
	cur->nxt = newnode;
}

void delete_node(struct node **head, int delnode){
	struct node* cur = *head;
	if(cur->val == delnode){
		*head = (*head)->nxt;
		return ;
	}
	if(cur->nxt == NULL){
		printf("In linked list doesn't exist value %d\n", delnode);
		return ;
	}
	while(cur->nxt->val != delnode){
		cur = cur->nxt;
		if(cur->nxt == NULL){
			printf("In linked list doesn's exist value %d\n", delnode);
			return ;
		}
	}
	if(cur->nxt->nxt != NULL){
		cur->nxt = cur->nxt->nxt;
	}
	else {
		cur->nxt = NULL;
	}
}

struct node* start = NULL;

int main(){
	while(1){
		printf("\n1 Print the linked list\n");
		printf("2 insert node\n");
		printf("3 delete node\n");

		int x;
		scanf("%d", &x);

		if(x == 1){
			print_list(start);
		}
		else if(x == 2){
			int a, b;
			printf("Enter the newnode value:\n");
			scanf("%d", &a);
			printf("\nEnter the prevnode value\n");
			scanf("%d", &b);
			insert_node(&start, a, b);
		}
		else {
			printf("Enter the delete node value\n");
			scanf("%d", &x);
			delete_node(&start, x);
		}
	}
}
