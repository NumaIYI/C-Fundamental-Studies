#include<stdio.h>
#include <string.h>
#define mmax 20

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

void sort(char dizi[][mmax], int size) {
int i, j;
char temp[mmax];
for(i = 0; i < size - 1; i++) {
for(j = 0; j < size - i - 1; j++) {
if(compare(dizi[j], dizi[j+1]) > 0) {
strcpy(temp, dizi[j]);
strcpy(dizi[j], dizi[j+1]);
strcpy(dizi[j+1], temp);
}
}
}
}

int main() {
int size, i;
scanf("%d", &size);
char dizi[size][mmax];
for(i = 0; i < size; i++) {
scanf("%s", dizi[i]);
}
sort(dizi, size);
for(i = 0; i < size; i++) {
printf("%s\n", dizi[i]);
}
return 0;
}
