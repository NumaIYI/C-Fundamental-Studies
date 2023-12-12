#include<stdio.h>
#include<stdlib.h>
#include "bkutup.h"
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

