#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h> 
#include <string.h>

// dosyadaki kelime ve karakter sayisini bul

int main()
{
   char karakter;
   char karakterOnceki = NULL;
   FILE *filePointer;
   char fileName[20] = "33.txt";
   

   printf("\n test.txt dosyasindaki kelime ve karakter sayisi sayiliyor...:\n");

   filePointer = fopen(fileName, "r");	
   if(filePointer ==NULL)
   {
      printf(" Dosya acilirken hata!");
      exit(1);
   }
 
   
   int kelimeSayisi = 0;
   
   int karakterSayisi = 0;
   
   karakter = getc(filePointer);
	
    while(karakter != EOF) {
	
		karakterSayisi++;
	
		if (karakter == ' ' || karakter == '\n') {
			
			kelimeSayisi++;
		}
		
		karakterOnceki = karakter;
		
		karakter = getc(filePointer);
		
	}
	
	if (karakterOnceki != NULL) {
			
		kelimeSayisi++;
	}
 
   fclose(filePointer);
   
   printf("\n Dosyadaki karakter sayisi: %d\n", karakterSayisi);
   
   printf("\n Dosyadaki kelime sayisi: %d\n", kelimeSayisi);
   
   return 0;
}
