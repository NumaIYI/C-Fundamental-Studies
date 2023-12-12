#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h> 
#include <string.h>

// dosyayi ac, oku konsola yaz
int main()
{
   char karakter;
   FILE *filePointer;
   char fileName[20] = "a.txt";
   

   printf("\n verilen dosya okunuyor...:\n");

   filePointer = fopen(fileName, "r");	
   if(filePointer ==NULL)
   {
      printf(" Dosya acilirken hata!");
      exit(1);
   }
 
 
    karakter = fgetc(filePointer);
    while (karakter != EOF)
	{
		printf ("%c", karakter);
		karakter = fgetc(filePointer);
	}
 
   fclose(filePointer);
   printf("\n Dosya basariyla okundu. \n", fileName);
   return 0;
}
