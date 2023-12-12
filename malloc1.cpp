#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char *cp;
	cp = (char*) malloc(20);
	strcpy(cp,"Bilgisaymaz");
	printf("Karakter dizisi: %s",cp);
	free(cp);
	return 0;
}
