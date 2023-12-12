#include<stdio.h>
#include<stdlib.h>
#include "stack_arr.h"
int *dizi=NULL;
int boyut = 2;
int tepe = 0;
int pop(){
	if(dizi==NULL){
		printf("dizi boþ");
		return -1;
	}
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
	if(dizi==NULL){
		dizi = (int *)malloc(sizeof(int)*2);
	}
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

