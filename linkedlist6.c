#include <stdio.h>
#include <stdlib.h>

struct n {
	/*double linked list member*/
    int x;
    struct n* next;
	struct n* prev;
};
typedef struct n node;

void yazdir(node* ro) {
    while (ro != NULL) {
        printf("%d ", ro->x);
        ro = ro->next;
    }
    printf("\n");
}

node * siraliekle(node * ro,int x){
	if (ro==NULL){
		ro = (node *)malloc(sizeof(node));
		ro ->next=NULL;
		ro->prev = NULL;
		ro->x = x;
		return ro;
	} 
	if(ro->x > x){ // ilk elemandan kucuk durumu
		// yeni root olu�tu
		node * temp = (node *)malloc(sizeof(node));
		temp->x = x;
		temp->next =ro;
		ro->prev = temp;
		temp->prev=NULL;
		return temp;
	}
	
	node * iter = ro;
	while(iter->next != NULL && iter->next->x < x){
		iter = iter->next;
	}
	
	node * temp = (node*)malloc(sizeof(node));	
	temp -> next = iter -> next;
	iter->next = temp;
	temp->prev=iter;
	if(temp->next!=NULL){
		temp->next->prev=temp;
	}
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
		//say� bulunamad�
		return ro;
	}
	temp = iter->next;
	iter->next = iter->next->next; //burda da �nceki eleman� sonraki elemana e�itledik aradakini silcez
	free (temp);
	if (iter->next!=NULL){
		iter->next->prev=iter;	
	}

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
	root= sil(root,450);
	root = sil(root,9990);
	yazdir(root);
	
    
    while (root != NULL) {
        node* temp = root;
        root = root->next;
        free(temp);
    }
    return 0;
}
// Compilation Time: 0,17s 
