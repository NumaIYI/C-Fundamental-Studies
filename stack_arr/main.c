#include<stdio.h>
#include<stdlib.h>
#include "stack_arr.h"

int main(){
	push(10);
	push(10);
	push(20);
	push(10);
	push(20);
	bastir();
	push(10);
	push(310);
	push(20);
	push(10);
	push(20);
	push(10);
	push(310);
	bastir();
	printf("popped |%d| \n",pop());
	printf("popped |%d| \n",pop());
	printf("popped |%d| \n",pop());
	printf("popped |%d| \n",pop());
	printf("popped |%d| \n",pop());
	printf("popped |%d| \n",pop());
	bastir();
	printf("popped |%d| \n",pop());
	bastir();
	printf("popped |%d| \n",pop());
	printf("popped |%d| \n",pop());
	bastir();
	printf("popped |%d| \n",pop());
	printf("popped |%d| \n",pop());
	printf("popped |%d| \n",pop());
	bastir();
	return 0;
}
