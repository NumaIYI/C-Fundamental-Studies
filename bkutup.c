#include <stdio.h>
#include <stdlib.h>
#include "bkutup.h"

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
		// yeni root oluþtu
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
	node *temp; //silcemiz elemaný kaybetmemek için bununla onu iþaretlicez
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
	iter->next = iter->next->next; //burda da önceki elemaný sonraki elemana eþitledik aradakini silcez
	free (temp);
	if (iter->next!=NULL){
		iter->next->prev=iter;	
	}

	return ro;
}

