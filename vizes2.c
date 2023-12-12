#include <stdio.h>
#define SIZE 10
//hocam getcharla yaptým alsýn diye kafam basmadý son input u boþluk girince programý kapatýyor.

int main() {
	int sayi;
	scanf("%d\n",&sayi);
	
    char dizi[SIZE]; 
    int tutar = 0;
    int fed = -1; 
    char c = getchar(); 

    while (c =! '\n') { 
        if (c == '(' || c == '{' || c == '[') { 
            if (fed >= SIZE - 1) { 
                printf("Parantezler uyumlu deðil\n");
                return 0;
            }
            dizi[++fed] = c; 
        }
        else if (c == ')' || c == '}' || c == ']') { 
            if (fed < 0 || 
               (c == ')' && dizi[fed] != '(') ||  
               (c == '}' && dizi[fed] != '{') ||
               (c == ']' && dizi[fed] != '[')) {
                printf("Parantezler uyumlu deðil\n");
                return 0;
            }
            fed--; 
        }
        c = getchar(); 
        tutar = tutar + 1;
    }

    if (fed < 0) { 
        printf("Parantezler uyumlu\n"); 
    }
    else { 
        printf("Parantezler uyumlu deðil\n");
    }

    return 0;
}
