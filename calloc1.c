#include<stdio.h>
#include<stdlib.h>

int main(void){
	int *ip, id;
	ip = (int*) calloc(10,sizeof(int));
	for (id=0;id<10;id++){
		*(ip+id) = (id+1)*7;
		printf("%p adresindeki deger: %d\n",(ip+id),*(ip+id));
	}
	
	return 0;
}
