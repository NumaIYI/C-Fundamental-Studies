#include <stdio.h>
#include <stdlib.h>

struct n {
    int x;
    struct n* next;
};
typedef struct n node;

void yazdir(node* ro) {
	node *iter = ro;
	printf("%d ",iter->x);
	iter = iter->next;
    while (iter != ro) {
        printf("%d ", iter->x);
        iter = iter->next;
    }
    printf("\n");
}

void ekle(node *ro, int x) {
	node * iter = ro; 
	while(iter->next != ro){
		iter = iter->next;
	}
	iter->next=(node*)malloc(sizeof(node));
	iter->next->x = x;
	iter->next->next = ro;
}

node * siraliekle(node * ro,int x){
	if (ro==NULL){
		ro = (node *)malloc(sizeof(node));
		ro ->next=ro;
		ro->x = x;
		return ro;
	} 
	if(ro->x > x){ // ilk elemandan kucuk durumu
		// yeni root oluþtu
		node * temp = (node *)malloc(sizeof(node));
		temp->x = x;
		temp->next =ro;
		node * iter = ro;
		while (iter->next != ro){
			iter = iter->next;
		}
		iter->next = temp;
		return temp;
	}
	
	node * iter = ro;
	while(iter->next != ro && iter->next->x < x){
		iter = iter->next;
	}
	
	node * temp = (node*)malloc(sizeof(node));	
	temp -> next = iter -> next;
	iter->next = temp;
	temp->x = x;
	return ro;
}

node * sil(node *ro,int x){
	node *temp; //silcemiz elemaný kaybetmemek için bununla onu iþaretlicez
	node *iter = ro;
	if (ro->x == x){
		while(iter->next != ro){
			iter = iter->next;
		}
		iter->next = ro->next;
		free(ro);
		
		return iter->next;
	}
	while(iter->next != ro && iter->next->x != x){
		iter = iter -> next;
	}
	if (iter->next==ro){ 
		printf("silinmesi istenen eleman listede yok\n");
		return ro;
	}
	temp = iter->next;
	iter->next = iter->next->next; //burda da önceki elemaný sonraki elemana eþitledik aradakini silcez
	free (temp);
	return ro;
}

int main() {
    node * root;
    root = NULL;
	root = siraliekle(root,400);
    root = siraliekle(root,50);
    root = siraliekle(root,450);
    root = siraliekle(root,40);
    root = siraliekle(root,4);
	yazdir(root);
	printf("sildikten sorasý\n");
	root = sil(root,40);
	root = sil(root,4);
	root = sil(root,9990);
	yazdir(root);
	
    
    while (root != NULL) {
        node* temp = root;
        root = root->next;
        free(temp);
    }

    return 0;
}

