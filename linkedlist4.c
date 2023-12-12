#include <stdio.h>
#include <stdlib.h>

struct n {
    int x;
    struct n* next;
};
typedef struct n node;

void yazdir(node* ro) {
    while (ro != NULL) {
        printf("%d ", ro->x);
        ro = ro->next;
    }
    printf("\n");
}

void ekle(node *ro, int x) {
	while(ro->next != NULL){
		ro = ro->next;
	}
	ro->next=(node*)malloc(sizeof(node));
	ro->next->x = x;
	ro->next->next = NULL;
}

node * siraliekle(node * ro,int x){
	if (ro==NULL){
		ro = (node *)malloc(sizeof(node));
		ro ->next=NULL;
		ro->x = x;
		return ro;
	} 
	if(ro->x > x){ // ilk elemandan kucuk durumu
		// yeni root olu�tu
		node * temp = (node *)malloc(sizeof(node));
		temp->x = x;
		temp->next =ro;
		return temp;
	}
	
	node * iter = ro;
	while(iter->next != NULL && iter->next->x < x){
		iter = iter->next;
	}
	
	node * temp = (node*)malloc(sizeof(node));	
	temp -> next = iter -> next;
	iter->next = temp;
	temp->x = x;
	return ro;
}

node * sil(node *ro,int x){
	node *temp; //silcemiz eleman� kaybetmemek i�in bununla onu i�aretlicez
	node *iter = ro;
	if (ro->x == x){
		temp = ro;
		ro = ro->next;
		free (temp);
		return ro;
	}
	while(iter -> next != NULL && iter->next->x != x){
		iter = iter -> next;
	}
	if (iter->next==NULL){
		return ro;
	}
	temp = iter->next;
	iter->next = iter->next->next; //burda da �nceki eleman� sonraki elemana e�itledik aradakini silcez
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
	printf("sildikten soras�\n");
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

