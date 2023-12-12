#include<stdio.h>


int main(){
	int a,b;
	printf("1. sayi: ");
	scanf("%d",&a);
	printf("\n2. sayi: ");
	scanf("%d",&b);
	int i;
	int ebob;
	for(i=1;i<=a && i<=b; i++){
		if(a%i==0 && b%i==0){
			ebob = i;
		}
	}
	printf("iki sayinin ebobu: %d",ebob);
	int ekok = (a*b)/ebob;
	printf("\niki sayinin ekoku: %d",ekok);
	
	
	
	
	
	
	return  0;
}
