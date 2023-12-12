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

void ekle(node** ro, int x) {
    while (*ro != NULL) {
        ro = &(*ro)->next;
    }
    *ro = (node*)malloc(sizeof(node));
    (*ro)->x = x;
    (*ro)->next = NULL;
}

int main() {
    node* root;
    root = (node*)malloc(sizeof(node));
    root->x = 500;

    int k;
    for (k = 5; k < 10; k++) {
        ekle(&root, k);
    }

    yazdir(root);

    while (root != NULL) {
        node* temp = root;
        root = root->next;
        free(temp);
    }

    return 0;
}

