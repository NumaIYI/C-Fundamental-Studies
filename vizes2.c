#include <stdio.h>
#define SIZE 10
//hocam getcharla yapt�m als�n diye kafam basmad� son input u bo�luk girince program� kapat�yor.

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
                printf("Parantezler uyumlu de�il\n");
                return 0;
            }
            dizi[++fed] = c; 
        }
        else if (c == ')' || c == '}' || c == ']') { 
            if (fed < 0 || 
               (c == ')' && dizi[fed] != '(') ||  
               (c == '}' && dizi[fed] != '{') ||
               (c == ']' && dizi[fed] != '[')) {
                printf("Parantezler uyumlu de�il\n");
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
        printf("Parantezler uyumlu de�il\n");
    }

    return 0;
}
