#ifndef bkutup
#define bkutup
struct n {
    int x;
    struct n* next;
	struct n* prev;
};
typedef struct n node;
void yazdir(node* ro);
node * siraliekle(node * ro,int x);
node * sil(node *ro,int x);

#endif
