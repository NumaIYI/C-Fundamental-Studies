#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h> 
#include <string.h>

// dosyada istenen satiri degistir

int main()
{
   
   FILE *filePointer;
   FILE *filePointerGecici;
   char fileName[20] = "test.txt";
   char geciciDosya[] = "gecici.txt";
   int bufferMiktari = 500;
   char buffer[bufferMiktari];
   char yeniSatir[250];
   
  
   int silinecekSatir = 0; 

   printf("\n test.txt dosyasindaki istediginiz satir degistirilecek...:\n");
      
   printf("\n Lutfen yeni satir icerigini giriniz : \n");

   fgets(yeniSatir, sizeof yeniSatir, stdin);
   
   printf(" Lutfen degistirmek istediginiz satir nosunu giriniz : ");
   scanf("%d", &silinecekSatir);
   
   filePointer = fopen(fileName, "r");	
   if(filePointer ==NULL)
   {
      printf(" Dosya acilirken hata!");
      exit(1);
   }
   
   filePointerGecici = fopen(geciciDosya, "w");	
   if(filePointerGecici ==NULL)
   {
      printf("Gecici Dosya acilirken hata!");
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
           
            if (index != silinecekSatir) 
            {
                fprintf(filePointerGecici, "%s", buffer);
            } else {
			
				fprintf(filePointerGecici, "%s", yeniSatir);
			}
        }
    } while (!feof(filePointer));
    
   fclose(filePointer);
   fclose(filePointerGecici);
   remove(fileName);
   rename(geciciDosya, fileName); 	 
   
   printf("\n Dosyadaki %d. satir degistirildi!\n", silinecekSatir);
  
   return 0;
}
