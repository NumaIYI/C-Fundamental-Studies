#include <stdio.h>
#include <math.h>

void kok_Bulma_2(int a, int b, int c) {
	int d = b*b - 4*a*c;
	if (d < 0) {
		printf("kok yok");
	}
	else if (d > 0){
		float k1 = ((-1 * b) + sqrt(d))/2*a;
		float k2 = ((-1 * b) - sqrt(d))/2*a;
		printf("kok1 = %.4f, kok2 = %.4f", k1, k2);
	}else {
		float k = (-1 * b) / (2 * a);
	printf("kok = %.4f", k);
	}
}

int main(){
	int a, b, c;
	printf("Lutfen denklemin x^2 x^1 ve x^0 katsayilarini sirayla giriniz: ");
	scanf("%d %d %d", &a, &b, &c);
	kok_Bulma_2(a, b, c);
	return 0;
}
