#include<stdio.h>
#include<stdlib.h>

int *dizi;
int boyut = 2;
int tepe = 0;

int pop(){
	if(tepe<=boyut/4){
		int *dizi2 = (int*)malloc(sizeof(int)*boyut/2);
		int i;
		for(i=0;i<boyut;i++){
			dizi2[i]=dizi[i];
		}
		free(dizi);
		dizi = dizi2;
		boyut /= 2;
	}
	return dizi[--tepe];
}

void push(int a){
	if(tepe >= boyut){
		int *dizi2 = (int*)malloc(sizeof(int)*boyut*2);
		int i;
		for(i=0;i<boyut;i++){
			dizi2[i]=dizi[i];
		}
		free(dizi);
		dizi = dizi2;
		boyut *= 2;
	}
	dizi[tepe++] = a;
}

void bastir(){
	printf(" Boyut : %d \n",boyut);
	int i;
	for(i=0;i<tepe;i++){
		printf("|%d| ",dizi[i]);
	}
	printf("\n");
}

int main(){
	dizi = (int *)malloc(sizeof(int)*2);
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
