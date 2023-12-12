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

node * pop(node *root){
	if(root == NULL){
		printf("\nWARNING: stack bos\n");
		return root;
	}
	else if (root->next == NULL){
		int rvalue = root->data;
		printf("|%d|--> Out\n",rvalue);
		root = NULL;
		return root;
	}else{
		node * iter = root;
		root = root->next;
		int rvalue = iter->data;
		printf("|%d|--> Out\n",rvalue);
		free(iter);
		return root;
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
	node * temp = (node *) malloc(sizeof(node));
	temp -> data = a;
	temp -> next = iter;
	
	return temp;
}


int main(){
	int i;
	node * s = NULL;
	s = pop(s);
	for(i=0;i<1000;i++){
		s=push(s,i*100);
	}
	

	for(i=0;i<1001;i++){
		/*if(i==10){
			yazStack(s);
		}*/
		s=pop(s);
	}
	yazStack(s);
	
	for(i=0;i<31;i++){
		s=push(s,i);
	}
	yazStack(s);
	for(i=0;i<32;i++){
		s=pop(s);
	}
	yazStack(s);
	s = pop(s);

	printf("Compilation Time: 0,000001s");
	
	return 0;
}
