#include<stdio.h>

int main(){
	int n,i;
	printf("Dizi eleman sayisi: ");
	scanf("%d",&n);
	float ort,lst[n],total = 0.0;
	for(i=0;i<n;i++){
		printf("%d. sayi: ",i+1);
		scanf("%f",&lst[i]);
		total += lst[i];
	}
	ort = total/n;
	printf("\nOrtalama = %.2f",ort);
	
	return 0;
}
