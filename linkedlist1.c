#include<stdio.h>
#include<stdlib.h>

struct n{
	int x;
	struct n * next;
};
typedef struct n node;

int main(){
	node * root;
	
	root = (node *)malloc(sizeof(node));
	root -> x = 10;
	root -> next = (node * ) malloc (sizeof(node));
	root -> next -> x=20;
	root -> next -> next= (node *) malloc(sizeof(node));
	root -> next -> next -> x=30;
	root -> next -> next -> next = NULL;
	
	node * iter;
	iter = root;
	
	printf("%d \n",iter->x);
	iter = iter -> next;
	printf("%d \n",iter->x);
	
	int i = 0;
	iter = root;
	
	while (iter->next != NULL){
		i++;
		printf("%d . eleman: %d\n",i,iter->x);
		iter = iter ->next;
	}
	int j;
	for (j=5;j<10;j++){
		iter->next = (node *)malloc(sizeof(node));
		iter = iter->next;
		iter->x = (j*10);
		iter->next=NULL;
	}
	iter = root;
	while (iter->next != NULL){
		i++;
		printf("%d . eleman: %d\n",i,iter->x);
		iter = iter ->next;
	}
	
	
	
}
/*for (j = 5; j < 10; j++) {
        root->next = (node*)malloc(sizeof(node));
        root = root->next;
        root->x = j * 10;
        root->next = NULL;
    }*/

