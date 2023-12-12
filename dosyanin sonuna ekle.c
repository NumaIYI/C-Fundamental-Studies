#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h> 
#include <string.h>

// dosyanin sonuna ekle

int main()
{
   
   FILE *filePointer;
   char fileName[20] = "test.txt";
   int bufferMiktari = 500;
   char buffer[bufferMiktari];
   
   printf(" Dosyaya eklemek istediklerinizi giriniz. Cikmak icin EXIT yaziniz: \n");

   filePointer = fopen(fileName, "a");	
   if(filePointer == NULL)
   {
      printf(" Dosya acilirken hata!");
      exit(1);
   }
   
   char * exitCase = "EXIT\n";
   
   int eklenenSatirSayisi = 0;

    do
    {
        fgets(buffer, bufferMiktari, stdin);
        
        if(strcmp(exitCase, buffer) == 0){
        	break;
		}
        
        fprintf(filePointer, "%s", buffer);
        
        eklenenSatirSayisi++;
         
    } while (strcmp(exitCase, buffer) != 0);
    
   fclose(filePointer);
   
   printf("\n Dosyaya %d adet satir eklendi!\n", eklenenSatirSayisi);
  
   return 0;
