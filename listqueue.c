#include<stdio.h>
#include<stdlib.h>
int *dizi=NULL;
int sira = 0,bas = 0,boyut=2;


int deque(){
	if(sira==bas)	{
		printf("\n!!! WARNING: sira bos !!!\n");
		return -1;
	}
	
	if(sira-bas<=boyut/4){
		int* dizi2 = (int*)malloc(sizeof(int)*boyut/2);
		int i;
		for(i=0;i<sira-bas;i++){
			dizi2[i]=dizi[bas+i];
		}
		sira-=bas;
		bas=0;
		free(dizi);
		boyut /=2;
		dizi = dizi2;
	}
	return dizi[bas++];
	
}

void toparla(){
	if(bas==0){
		return ;
	}
	int i;
	for(i=0;i<boyut;i++){
		dizi[i]=dizi[i+bas];
	}
	sira -= bas;
	bas = 0;
}

void enque(int a){
	if(dizi==NULL){
		dizi = (int*)malloc(sizeof(int)*2);
	}
	if(sira>=boyut){
		boyut *= 2;
		int *dizi2 = (int*)malloc(sizeof(int)*boyut);
		int i;
		for(i=0; i < boyut/2 ;i++){
			dizi2[i]=dizi[i];
		}
		free(dizi);
		dizi=dizi2;
	}
	dizi[sira++]=a;
}

int main(){
	int i;
	for(i=0;i<20;i++){
		enque(i*10);
	}
	printf("\nDURUM: boyut: %d sira: %d sirabasi: %d ##\n",boyut,sira,bas);
	for(i=0;i<13;i++){
		printf("%d ",deque());
	}
	
	printf("\nDURUM: boyut: %d sira: %d sirabasi: %d ##\n",boyut,sira,bas);
	
	for(i=0;i<20;i++){
		enque(i*10);
	}
	printf("\nDURUM: boyut: %d sira: %d sirabasi: %d ##\n",boyut,sira,bas);
	for(i=0;i<30;i++){
		printf("%d ",deque());
	}
	printf("\nDURUM: boyut: %d sira: %d sirabasi: %d ##\n",boyut,sira,bas);	
	
	return 0;
}
