#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h> 
#include <string.h>

// dosyayi baska isimli dosyaya kopyala

int main()
{
   
   FILE *filePointer;
   FILE *filePointerYeni;
   char fileName[20] = "test.txt";
   char yeniDosyaAdi[50];
   int bufferMiktari = 500;
   char buffer[bufferMiktari];
   char yeniSatir[250];
   
   printf("\n Lutfen yeni dosya ismini giriniz : \n");

   fgets(yeniDosyaAdi, sizeof yeniDosyaAdi, stdin);
   int i = 0;
   for(i = 0; i < 50; i++) {
   	
   		if(yeniDosyaAdi[i] == '\n') {
   			
   			yeniDosyaAdi[i] = '\0';
		}
   	
   }
   
   filePointer = fopen(fileName, "r");	
   if(filePointer ==NULL)
   {
      printf(" Dosya acilirken hata!");
      exit(1);
   }
   
   filePointerYeni = fopen(yeniDosyaAdi, "w");	
   if(filePointerYeni == NULL)
   {
      printf("Yeni Dosya acilirken hata!");
      exit(1);
   }
   
 
	int index = 0;

    do
    {
        strcpy(buffer, "\0");
        fgets(buffer, bufferMiktari, filePointer);
        if (!feof(filePointer)) 
        {
            index++;
           
             fprintf(filePointerYeni, "%s", buffer);
            
        }
    } while (!feof(filePointer));
    
   fclose(filePointer);
   fclose(filePointerYeni);
     
   printf("\n Dosya kopyalandi!\n");
  
   return 0;
}
