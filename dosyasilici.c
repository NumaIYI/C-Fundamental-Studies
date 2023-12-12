#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h> 
#include <string.h>

// adi verilen dosyayi sil. Dikkatli kullaniniz. Veri kayiplarinda sorumnluluk kabul edilmemektedir.

int main()
{
   
   char silinecekDosyaAdi[50];
   
   printf("\n Lutfen silinecek dosya ismini giriniz : \n");

   fgets(silinecekDosyaAdi, sizeof silinecekDosyaAdi, stdin);
   int i = 0;
   for(i = 0; i < 50; i++) {
   	
   		if(silinecekDosyaAdi[i] == '\n') {
   			
   			silinecekDosyaAdi[i] = '\0';
		}
   	
   }
    
   int result = remove(silinecekDosyaAdi);
     
   if(result == 0) {
   	
   	 printf("\n Dosya silindi !\n");
   	 
   } else {
   	
   	 printf("\n Dosya Silinemedi!\n", result);
   }
  
  
   return 0;
}
