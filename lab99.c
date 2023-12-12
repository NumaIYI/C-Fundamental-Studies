#include<stdio.h>
/*Kullan�c�dan veri giri�i sonland�r�l�ncaya kadar (enter tu�una bas�l�ncaya kadar) okuma yapan ve 
a�a��daki kurallar� sa�layacak �ekilde al�nan veriyi kontrol eden bir program yazman�z beklenmektedir. 
Kullan�c� veri giri�i yapt���nda program�n�z bu veriyi okuyacak ve a�a��da tan�mlanan fonksiyonlar ile 
elde edilen sonucu �retecektir. Kullan�c� istedi�i uzunlukta veri giri�i yapabilir. Bunu s�n�rland�rmak ve 
program�n g�venli�ini sa�lamak i�in en fazla 20 elemanl�k bir dizin olu�turacak �ekilde program�n�z� 
tasarlay�n�z. 20�den fazla boyuta sahip olan bir input girilmeyece�ini varsayabilirsiniz.
void get_input (int size, char my_array[ ]): Fonksiyonu size uzunlukta eleman� my_array dizinine 
alacakt�r. 
void erase_non_digit ( int size, int my_new_size, char my_array[ ], int my_new_array[ ] ): 
Fonksiyonu kullan�c�dan al�nan my_array dizini i�erisinde sadece say� karakterlerin (rakamlar�n) 
olu�turdu�u my_new_array dizinini olu�turacakt�r. �rne�in kullan�c� �12 a._e 4]b� �eklinde bir input 
girmi�se bu fonksiyon my_array dizinini 3 elemanl� 124 durumuna indirgeyecektir. Bu yap� 
my_new_array �zerinde saklanacak ve uzunlu�u my_new_size ile tan�mlanacakt�r. ( yeni dizinin tipine 
dikkat!) Program�n�z�n olu�turaca�� beklenen output i�in a�a��da baz� kurallar tan�mlanm��t�r. Her bir 
kural� ger�ekle�tirecek 3 ayr� fonksiyon yazman�z gerekmektedir.
Kural 1: Beklenen yap�da tam 11 rakam olmal�d�r. 
int rule_1 (int size, int A[ ] ): Bu fonksiyon arg�man olarak al�nan A dizininin uzunlu�unun 11 olup 
olmad���n� kontrol eder. Kuraldan ge�erse 1, ge�emezse 0 �eklinde sonu� d�nd�r�r. 
Kural 2: 1,3,5,7 ve 9. basamaklar�n�n (array indeksi de�il birden ba�layan basamak) toplam�n�n 7 
kat�ndan 2,4,6 ve 8. basamaklar�n toplam� ��kar�ld���nda elde edilen sonucun 10�a b�l�m�nden kalan 
say� 10. basamaktaki say�ya e�it olmal�d�r. 
int rule_2( int size, int A[ ] ): Bu fonksiyon size elemanl� A dizininin yukar�daki kural� sa�lay�p 
sa�lamad���n� kontrol eder. Kuraldan ge�erse 1, ge�emezse 0 �eklinde sonu� d�nd�r�r.
Kural 3: �lk 10 hanenin toplam�ndan elde edilen sonucun 10�a b�l�m�nden kalan say� 11. basamaktaki 
say�ya e�it olmal�d�r.
int rule_3( int size, int A[ ] ): Bu fonksiyon size elemanl� A dizininin yukar�daki kural� sa�lay�p 
sa�lamad���n� kontrol eder. Kuraldan ge�erse 1, ge�emezse 0 �eklinde sonu� d�nd�r�r.
Program�n�z �al��t���nda ilk olarak;
void get_input ( int size, char my_array[ ] ) 
void erase_non_digit ( int size, int my_new_size, int, my_array[ ], int my_new_array[ ] ) 
fonksiyonlar�n� �a�r�lacakt�r. Ard�ndan 3 kural�n sa�lan�p sa�lanmad��� test edilecektir. rule_1 
fonksiyonu olumsuz sonu� d�nd�rd���nde kullan�c�dan yeni bir veri giri�i yapmas� istenecek ve 
yukar�daki ilk iki fonksiyon(get_input ve erase_non_digit) yeniden �a�r�lacakt�r. Kullan�c�n�n kural 
1�i ge�mek i�in toplamda 3 veri giri�i yapma hakk� olacakt�r. Bu a�amadan ge�ilirse di�er rule_2 ve 
rule_3 test edilecektir. E�er rule_2 a�amas�ndan ge�emez ise rule_3 kontrol edilmeyecektir. Kural 2 
vcya 3�den ge�ilemez ise, kullan�c�dan tekrar veri girdisi al�nmayacakt�r ve program sonlanacakt�r. 
Al�nan veri t�m testleri ge�mi� ise ekrana elde edilen input sonucu bast�r�lacakt�r. E�er kurallardan birini 
ge�emezse hangi kural ihlalinden dolay� testin ge�ilemedi�i ekrana bast�r�larak program sonlanacakt�r.
Sizlere verilen input-output dosyalar�n� inceleyiniz. ��kt�lar�n�z output dosyalar�ndaki ile birebir ayn� 
olmak zorundad�r.*/
/*
int main() {
	int i;
	char c = getchar(); 

    while (c != '\n'){
    	c = getchar();
    	
    	
	}
	
	
	
	
	
	
	
	
	
}*/

#include <stdio.h>
#include <ctype.h>

void get_input(int size, char my_array[])
{
    fgets(my_array, size, stdin); 
}

void erase_non_digit(int size, int my_new_array_size, char my_array[], int my_new_array[])
{
    int j = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        if (isdigit(my_array[i])) 
        {
            my_new_array[j] = my_array[i] - '0'; 
            j++;
            if (j == my_new_array_size) 
            {
                break;
            }
        }
    }
}

int rule_1(int size, int A[])
{
    return size == 11;
}

int rule_2(int size, int A[])
{
    int sum_odd = A[0] + A[2] + A[4] + A[6] + A[8];
    int sum_even = A[1] + A[3] + A[5] + A[7];
    int result = (sum_odd * 7) - sum_even;
    return result % 10 == A[9];
}

int rule_3(int size, int A[])
{
    int sum = 0;
    int i;
    for (i = 0; i < size - 1; i++) 
    {
        sum += A[i];
    }
    return sum % 10 == A[10];
}

int main()
{
    char my_array[20];
    int my_new_array[20];
    int my_new_array_size = 0;
    int input_count = 0;
    while (input_count < 3) 
    {
        get_input(20, my_array);
        erase_non_digit(20, 11, my_array, my_new_array);
        my_new_array_size = 0;
        while (my_new_array[my_new_array_size] != 0) 
        {
            my_new_array_size++;
        }
        if (!rule_1(my_new_array_size, my_new_array)) 
        {
            printf("Invalid input: must contain exactly 11 digits\n");
            input_count++;
            continue;
        }
        if (!rule_2(my_new_array_size, my_new_array)) 
        {
            printf("Invalid input: rule 2 \n");
            return 0;
        }
        if (!rule_3(my_new_array_size, my_new_array)) 
        {
            printf("Invalid input: rule 3 \n");
            return 0;
        }
        printf("Valid: ");
        int i;
        for (i = 0; i < my_new_array_size; i++)
        {
            printf("%d", my_new_array[i]);
        }
        printf("\n");
        break;
    }
    if (input_count == 3)
    {
        printf("Invalid input: exceeded maximum number of attempts\n");
    }
    return 0;
}
