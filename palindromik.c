#include<stdio.h>

int main(){
	int s,ou = 0;
	printf("sayi: ");
	scanf("%d",&s);
	int ilk = s;
	int tutucu;
	
	while(s!=0){
		tutucu = s % 10;
		ou = ou * 10 +tutucu;
		s = s / 10; 
	}
	
	if (ilk==ou){
		printf("\nBu sayi Palindromik.");
	}else{
		printf("\nBu sayi Palindromik deðil.");
	}
	
	return 0;
}
