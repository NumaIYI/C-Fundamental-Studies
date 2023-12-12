#include<stdio.h>
#define MAX 10


int check_value(int A[],int valueA){
	/*int i;
	int uzu;
	uzu = sizeof(A)/sizeof(int);
    for (i=0; i<=uzu; i++) A[i] = i+1;*/
    int ou = 999;
	int j;
	for(j = 0;j<MAX;j++){
		if(A[j] == valueA){
			ou = j;
			break;
		}
	}
	if(ou == 999){
		ou = -1;
	}
	return ou;
	
	
	
	
}

void delete_element(int A[], int pos){
	int i;
	int uzu;
	int lenn;
	lenn = sizeof(A)/sizeof(int);
	uzu = (lenn-1) - pos;
	int j;
	A[lenn] = A[lenn-1];
	for(j=pos;j<uzu;j++){
		A[j] = A[j+1];
	}
	
	
	
	
}

int main(){
	
	int dizi[MAX];
	int h;
	for(h=0;h<MAX;h++){
		scanf("%d",&dizi[h]);
	}
	
	int a;
	a = check_value(dizi,5);
	delete_element(dizi,4);
	printf("%d",a);
	printf("\n");
	int g;
	for(g=0;g<MAX;g++){
		printf("%d",dizi[g]);
	}
	 
	
	
	
	
	
	
}
