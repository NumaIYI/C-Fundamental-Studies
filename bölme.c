#include<stdio.h>

int main(){
	
	int a;
	float b;
	float c;
	printf("ilk sayiyi giriniz: ");
	scanf("%d",&a);
	
	printf("\nikinci sayiyi giriniz: ");
	scanf("%f",&b);
	//ikinci sayýyý float olarak almassak sonuç int bölmesi oluyor tam kýsmý alýnýyor haber ola.*****#####
	printf("bolme islemi yapiliyor...\n");
	c = a / b;
	
	printf("Total : %.2f",c);
	return 0;
	
}
