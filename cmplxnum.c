#include<stdio.h>

struct cmplx{
	double real;
	double img;
};

struct cmplx cmplx_add(struct cmplx x,struct cmplx y){
	struct cmplx c;
	c.real = x.real + y.real;
	c.img = x.img + y.img;
	return c;
}

void display(struct cmplx c){
	printf("%.2f",c.real);
	printf(" + %.2fi",c.img);
}

int main(){
	struct cmplx a = {5.2,4.5};
	struct cmplx b = {2.1,7.8};
	struct cmplx c;
	c = cmplx_add(a,b);
	display(c);
	return 0;
}
