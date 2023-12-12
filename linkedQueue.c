#include<stdio.h>
#include<stdlib.h>

struct n{
	int data;
	struct n * next;
};
typedef struct n node;

node * root=NULL;
node * son = NULL;
void enqueue(int x){
	if(root==NULL){ //first node
		root = (node*)malloc(sizeof(node));
		root->data = x;
		root->next = NULL;
		son = root;
	}
	else{
		son->next = (node *)malloc(sizeof(node));
		son->next->data = x;	
		son = son->next;
		son->next=NULL;
	}
}

int dequeue(){
	if(root==NULL){
		printf("NULL");
		return -1;
	}
	int rvalue = root->data;
	node *temp = root;
	root = root->next;
	free(temp);
	return rvalue;
}

int main(){
	
	int i;
	for(i=0;i<20;i++){
		enqueue(i*10);
	}
	printf("20 tane ekledik\n");
	
	printf("Cikanlar [");
	for(i=0;i<13;i++){
		if(i==12){
			printf("%d",dequeue());
		}else{
			printf("%d,",dequeue());
		}
	}
	printf("]");
	printf("===>13 tane cikardik\n");

	for(i=0;i<20;i++){
		enqueue(i*10);
	}
	printf("20 tane ekledik\n");
	
	printf("Cikanlar [");
	for(i=0;i<30;i++){
		if(i==29){
			printf("%d",dequeue());
		}else{
			printf("%d,",dequeue());
		}
	}
	printf("]");
	printf("===>30 tane cikardik\n");
	printf("30 tane cikardik bos oldunda NULL vericektir\n");
	return 0;
}
