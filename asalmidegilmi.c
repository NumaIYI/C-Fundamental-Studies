#include<stdio.h>

int main(){
	int s,i,flag = 0;
	printf("Pozitif syinizi giriniz: ");
	scanf("%d",&s);
	
	for (i = 2; i < s ; i++){
		if(s%i == 0){
			flag = 1;
			break;
		}
	}
	
	if (s==1){
		printf("\n1 ne asal sayidir ne de bileþiktir.");
	}else{
		if(flag==0){
			printf("%d asal sayidir.",s);
		}else{
			printf("%d asal sayi degildir.",s);
		}
	}
	return 0;
}
