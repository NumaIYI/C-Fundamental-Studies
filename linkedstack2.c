#include<stdio.h>
#include<stdlib.h>
struct n{
	struct n* next;
	int data;
};
typedef struct n node;

void yazStack(node * root){
	printf("\n[ROOT] -> ");
	while (root != NULL) {
        printf("%d -> ", root->data);
        root = root->next;
    }
    printf("[NULL]\n");
}

int pop(node *root){
	if(root == NULL){
		printf("\nWARNING: stack bos\n");
		return -1;
	}
	else if (root->next == NULL){
		int rvalue = root->data;
		root->data = -1;
		root = NULL;
		return rvalue;
	}else{
		node * iter = root;
		while (iter->next->next != NULL){
			iter = iter->next;
		}
		node *temp = iter->next;
		int rvalue = temp->data;
		iter->next=NULL;
		free(temp);
		return rvalue;
	}
	
}

node * push(node * root,int a){
	if (root==NULL){
		root = (node *) malloc(sizeof(node));
		root->data=a;
		root->next=NULL;
		return root;
	}
	node * iter = root;
	while(iter->next != NULL){
		iter = iter->next;	
	}
	node * temp = (node *) malloc(sizeof(node));
	temp -> data = a;
	temp -> next = NULL;
	iter -> next = temp;
	return root;
}


int main(){
	
	node * s = NULL;
	printf("|%d -> trash| ",pop(s));
	s = push(s,20);
	s = push(s,30);
	s = push(s,40);
	s = push(s,50);
	s = push(s,60);
	s = push(s,70);
	printf("|%d -> trash| ",pop(s));
	printf("|%d -> trash| ",pop(s));
	s = push(s,500);
	s = push(s,550);
	s = push(s,560);
	s = push(s,570);
	//yazStack(s);
	printf("|%d -> trash| ",pop(s));
	printf("|%d -> trash| ",pop(s));
	printf("|%d -> trash| ",pop(s));
	printf("|%d -> trash| ",pop(s));
	printf("|%d -> trash| ",pop(s));
	printf("|%d -> trash| ",pop(s));
	printf("|%d -> trash| ",pop(s));
	printf("|%d -> trash| ",pop(s));
	printf("|%d -> trash| ",pop(s));
	printf("|%d -> trash| ",pop(s));

	printf("hello");
	
	return 0;
}
