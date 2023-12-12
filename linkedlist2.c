#include <stdio.h>
#include <stdlib.h>

struct n {
    int x;
    struct n* next;
};
typedef struct n node;

void yazdir(node* ro) {
    while (ro != NULL) {
        printf("%d\n", ro->x);
        ro = ro->next;
    }
}

void ekle(node *ro, int x) {
	while(ro->next != NULL){
		ro = ro->next;
	}
	ro->next=(node*)malloc(sizeof(node));
	ro->next->x = x;
	ro->next->next = NULL;
}


int main() {
    node * root;
    root = (node *)malloc(sizeof(node));
    root->x = 1001;
    root->next=NULL;
	
    
    int i =0;
    for (i = 0; i < 5; i++) {
        ekle(root, i*5);
    }
    
	yazdir(root);
	
	node * iter =root;
	for(i=1;i<4;i++){
		iter = iter->next;
		node * kamp = (node*)malloc(sizeof(node));
		kamp->next = iter->next;
		iter->next = kamp;
		kamp->x = i*100;
	}
	yazdir(root);
    
    while (root != NULL) {
        node* temp = root;
        root = root->next;
        free(temp);
    }

    return 0;
}

