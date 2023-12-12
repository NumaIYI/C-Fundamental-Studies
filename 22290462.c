#include <stdio.h>
#include <math.h>

int main(){

int taksit = 10; 
int m2_34 = 5000; 
int m2_06 = 4500; 
int m2_35 = 4000; 
int m2_01 = 3500; 
int m2_55 = 3000; 
int sehirKodu, evinMetreKaresi, aylikOdenebilecekTaksit,
pesinat;
float yillikFaiz;
printf("Sehir Kodu: ");
scanf("%d",&sehirKodu);
printf("\nEvin metrekaresi: ");
scanf("%d",&evinMetreKaresi);
printf("\nAylik odenebilecek taksit: ");
scanf("%d",&aylikOdenebilecekTaksit);
printf("\nPesinat: ");
scanf("%d",&pesinat);
printf("\nYillik faiz: ");
scanf("%f",&yillikFaiz);

int m2Bedeli;
if (sehirKodu == 34){
	m2Bedeli = m2_34;
}
if (sehirKodu == 6){
	m2Bedeli = m2_06;
}
if (sehirKodu == 35){
	m2Bedeli = m2_35;
}
if (sehirKodu == 1){
	m2Bedeli = m2_01;
}
if (sehirKodu == 55){
	m2Bedeli = m2_55;
}


int evinFiyati;
evinFiyati = m2Bedeli*evinMetreKaresi; 
printf("Evin fiyati: %d\n", evinFiyati);
float aylikFaiz;
aylikFaiz = yillikFaiz/(12*100); 
printf("Aylik Faiz: %.4f\n", aylikFaiz);
int krediTutari; 
krediTutari = evinFiyati - pesinat;
 
float aylikTaksit;  
aylikTaksit = (krediTutari*aylikFaiz*pow(1+aylikFaiz,taksit))/(pow(1+aylikFaiz,taksit)-1);
printf("Aylik taksit: %.2f\n", aylikTaksit);
if (aylikTaksit <= aylikOdenebilecekTaksit){
	printf("true\n");

}
else{
	printf("false\n");
}
//taksit1
printf("---TAKSIT-1\n");
float kalanBorc = evinFiyati - pesinat;  
float odenecekFaizMikari = kalanBorc*aylikFaiz; 
float odenecekAnaparaMiktari = aylikTaksit - odenecekFaizMikari; 
printf("Kalan borc: %.2f\n", kalanBorc);
printf("Odenecek Faiz: %.2f\n", odenecekFaizMikari);
printf("Odenecek ana para: %.2f\n", odenecekAnaparaMiktari);
//taksit2
printf("---TAKSIT-2\n");
//hocam bu bölümde kalanborcu güncellerken outputla ayný sonucu vermesi için ödenecek anapara miktarýný çýkarmamýz gerekiyor ayliktaksiti çýkardýðýmýzda sonuç outputla ayný olmuyor bu yüzden verilen formülden saptým saygýlarýmla :)
kalanBorc = kalanBorc - odenecekAnaparaMiktari;  
odenecekFaizMikari = kalanBorc*aylikFaiz; 
odenecekAnaparaMiktari = aylikTaksit - odenecekFaizMikari;
printf("Kalan borc: %.2f\n", kalanBorc);
printf("Odenecek faiz: %.2f\n", odenecekFaizMikari);
printf("Odenecek ana para: %.2f\n", odenecekAnaparaMiktari);
//taksit3
printf("---TAKSIT-3\n");
kalanBorc = kalanBorc - odenecekAnaparaMiktari;  
odenecekFaizMikari = kalanBorc*aylikFaiz; 
odenecekAnaparaMiktari = aylikTaksit - odenecekFaizMikari; 
printf("Kalan borc: %.2f\n", kalanBorc);
printf("Odenecek faiz: %.2f\n", odenecekFaizMikari);
printf("Odenecek ana para:%.2f\n", odenecekAnaparaMiktari);

return 0;
}
