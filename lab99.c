#include<stdio.h>
/*Kullanýcýdan veri giriþi sonlandýrýlýncaya kadar (enter tuþuna basýlýncaya kadar) okuma yapan ve 
aþaðýdaki kurallarý saðlayacak þekilde alýnan veriyi kontrol eden bir program yazmanýz beklenmektedir. 
Kullanýcý veri giriþi yaptýðýnda programýnýz bu veriyi okuyacak ve aþaðýda tanýmlanan fonksiyonlar ile 
elde edilen sonucu üretecektir. Kullanýcý istediði uzunlukta veri giriþi yapabilir. Bunu sýnýrlandýrmak ve 
programýn güvenliðini saðlamak için en fazla 20 elemanlýk bir dizin oluþturacak þekilde programýnýzý 
tasarlayýnýz. 20’den fazla boyuta sahip olan bir input girilmeyeceðini varsayabilirsiniz.
void get_input (int size, char my_array[ ]): Fonksiyonu size uzunlukta elemaný my_array dizinine 
alacaktýr. 
void erase_non_digit ( int size, int my_new_size, char my_array[ ], int my_new_array[ ] ): 
Fonksiyonu kullanýcýdan alýnan my_array dizini içerisinde sadece sayý karakterlerin (rakamlarýn) 
oluþturduðu my_new_array dizinini oluþturacaktýr. Örneðin kullanýcý “12 a._e 4]b” þeklinde bir input 
girmiþse bu fonksiyon my_array dizinini 3 elemanlý 124 durumuna indirgeyecektir. Bu yapý 
my_new_array üzerinde saklanacak ve uzunluðu my_new_size ile tanýmlanacaktýr. ( yeni dizinin tipine 
dikkat!) Programýnýzýn oluþturacaðý beklenen output için aþaðýda bazý kurallar tanýmlanmýþtýr. Her bir 
kuralý gerçekleþtirecek 3 ayrý fonksiyon yazmanýz gerekmektedir.
Kural 1: Beklenen yapýda tam 11 rakam olmalýdýr. 
int rule_1 (int size, int A[ ] ): Bu fonksiyon argüman olarak alýnan A dizininin uzunluðunun 11 olup 
olmadýðýný kontrol eder. Kuraldan geçerse 1, geçemezse 0 þeklinde sonuç döndürür. 
Kural 2: 1,3,5,7 ve 9. basamaklarýnýn (array indeksi deðil birden baþlayan basamak) toplamýnýn 7 
katýndan 2,4,6 ve 8. basamaklarýn toplamý çýkarýldýðýnda elde edilen sonucun 10’a bölümünden kalan 
sayý 10. basamaktaki sayýya eþit olmalýdýr. 
int rule_2( int size, int A[ ] ): Bu fonksiyon size elemanlý A dizininin yukarýdaki kuralý saðlayýp 
saðlamadýðýný kontrol eder. Kuraldan geçerse 1, geçemezse 0 þeklinde sonuç döndürür.
Kural 3: Ýlk 10 hanenin toplamýndan elde edilen sonucun 10’a bölümünden kalan sayý 11. basamaktaki 
sayýya eþit olmalýdýr.
int rule_3( int size, int A[ ] ): Bu fonksiyon size elemanlý A dizininin yukarýdaki kuralý saðlayýp 
saðlamadýðýný kontrol eder. Kuraldan geçerse 1, geçemezse 0 þeklinde sonuç döndürür.
Programýnýz çalýþtýðýnda ilk olarak;
void get_input ( int size, char my_array[ ] ) 
void erase_non_digit ( int size, int my_new_size, int, my_array[ ], int my_new_array[ ] ) 
fonksiyonlarýný çaðrýlacaktýr. Ardýndan 3 kuralýn saðlanýp saðlanmadýðý test edilecektir. rule_1 
fonksiyonu olumsuz sonuç döndürdüðünde kullanýcýdan yeni bir veri giriþi yapmasý istenecek ve 
yukarýdaki ilk iki fonksiyon(get_input ve erase_non_digit) yeniden çaðrýlacaktýr. Kullanýcýnýn kural 
1’i geçmek için toplamda 3 veri giriþi yapma hakký olacaktýr. Bu aþamadan geçilirse diðer rule_2 ve 
rule_3 test edilecektir. Eðer rule_2 aþamasýndan geçemez ise rule_3 kontrol edilmeyecektir. Kural 2 
vcya 3’den geçilemez ise, kullanýcýdan tekrar veri girdisi alýnmayacaktýr ve program sonlanacaktýr. 
Alýnan veri tüm testleri geçmiþ ise ekrana elde edilen input sonucu bastýrýlacaktýr. Eðer kurallardan birini 
geçemezse hangi kural ihlalinden dolayý testin geçilemediði ekrana bastýrýlarak program sonlanacaktýr.
Sizlere verilen input-output dosyalarýný inceleyiniz. Çýktýlarýnýz output dosyalarýndaki ile birebir ayný 
olmak zorundadýr.*/
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
