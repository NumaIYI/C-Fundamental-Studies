#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h> 
#include <string.h>

// klavyeden gelen veriyi yeni dosyaya kaydet
int main()
{
   char inputString[1000];
   FILE *filePointer;
   char fileName[20] = "inpututxtyap.txt";

   printf("\nBir cumle yazýnýz :\n");

   filePointer = fopen(fileName, "w");	
   if(filePointer ==NULL)
   {
      printf(" Dosya acilirken hata!");
      exit(1);
   }
   
   fgets(inputString, sizeof inputString, stdin);
   fprintf(filePointer, "%s", inputString);
   fclose(filePointer);
   printf("\n Dosya basariyla olusturuldu. \n", fileName);
   return 0;
}
