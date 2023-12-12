#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h> 
#include <string.h>

// dosyadaki satir sayisini bul

int main()
{
   char karakter;
   char karakterOnceki = NULL;
   FILE *filePointer;
   char fileName[20] = "test.txt";
   

   printf("\n test.txt dosyasindaki satir sayisi sayiliyor...:\n");

   filePointer = fopen(fileName, "r");	
   if(filePointer ==NULL)
   {
      printf(" Dosya acilirken hata!");
      exit(1);
   }
 
   int satirSayisi = 0;  

   karakter = getc(filePointer);
	
    while(karakter != EOF) {
	
		if (karakter == '\n') {
			
			satirSayisi++;
		}
		
		karakterOnceki = karakter;
		
		karakter = getc(filePointer);
		
	}
	
	if (karakterOnceki != NULL) {
			
		satirSayisi++;
	}
 
   fclose(filePointer);
   printf("\n Dosyadaki satir sayisi: %d\n", satirSayisi);
   return 0;
}
