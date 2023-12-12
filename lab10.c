#include<stdio.h>

//Boþ karakter "\0" þeklinde ifade edilir. C programlama dilinde, kelimelerin bittiðini boþ karakterlerle anlarýz. Herhangi bir katarý boþ karakterle sonlandýrmaya, 'null-terminated' denmektedir.
int compare(char *str1, char *str2) {
	int i = 0;
	while(str1[i] != '\0' && str2[i] != '\0') {
		if(str1[i] > str2[i]) {
			return 1;
		}
		else if(str1[i] < str2[i]) {
			return -1;
		}
		i++;
	}
	if(str1[i] == '\0' && str2[i] == '\0') {
		return 0;
		}
	else if(str1[i] == '\0') {
		return -1;
		}
	else {
		return 1;
	}
}

void sort(char dizi[][20], int size) {
	int i,j;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - i - 1; j++) {
			if (compare(dizi[j], dizi[j+1]) > 0) {
				char temp[20];
	int k;
	for (k = 0; k < 20; k++)
	*(temp + k) = *(dizi[j] + k);
	for (k = 0; k < 20; k++)
	*(dizi[j] + k) = *(dizi[j+1] + k);
	for (k = 0; k < 20; k++)
	*(dizi[j+1] + k) = *(temp + k);
}
}
}
}


int main() {
	printf("kac kelime girilecek: ");
	int size;
	scanf("%d", &size);
	char dizi[size][20];
	int i;
	for(i = 0; i < size; i++) {
		scanf("%s", dizi[i]);
	}
	sort(dizi, size);
	for(i = 0; i < size; i++) {
		printf("%s\n", dizi[i]);
	}
	return 0;
}
