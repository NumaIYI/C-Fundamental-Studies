/*#include <stdio.h>

struct Point {
   int x, y, z;
};
 
int main( ) {
  struct Point p1 = {.y = 0, .z = 1, .x = 2};
  struct Point p2 = {.y = 6, .z = 7};

   printf( "%d %d %d\n", p1.x, p1.y, p1.z);
   printf( "%d %d\n", p2.y, p2.z);

   return 0;
}*/

#include <stdio.h>
#include <string.h>
 
struct Kitaplar {
   char  isim[50];
   char  yazar[50];
   char  konu[100];
   int   barkod;
};

/* Fonksiyon prototipi tanimlama */
void kitaplariYazdir( struct Kitaplar kitap );

int main(void){

   struct Kitaplar Kitap1; /* Kitap1 adli Kitabý Deklare etme */
   struct Kitaplar Kitap2; /* Kitap2 adli Kitabý Deklare etme */
 
   /* Kitap1 özellikleri */
   strcpy( Kitap1.isim, "C Programlama Dili");
   strcpy( Kitap1.yazar, "Dennis Ritchie"); 
   strcpy( Kitap1.konu, "C Programlama Egitimi");
   Kitap1.barkod = 65657098;

   /* Kitap2 özellikleri */
   strcpy( Kitap2.isim, "Python3");
   strcpy( Kitap2.yazar, "Firat Ozgul"); 
   strcpy( Kitap2.konu, "Python Programlama Egitimi");
   Kitap2.barkod = 6495407;
 
   /* Kitap1 bilgilerini yazdir */
   kitaplariYazdir( Kitap1 );

   /* Kitap2 bilgilerini yazdir */
   kitaplariYazdir( Kitap2 );

   return 0;
}

void kitaplariYazdir( struct Kitaplar kitap ) {

   printf( "Kitap isimi : %s\n", kitap.isim);
   printf( "Kitabin yazari : %s\n", kitap.yazar);
   printf( "Kitabin konusu : %s\n", kitap.konu);
   printf( "Kitabin barkod kodu : %d\n", kitap.barkod);
}
