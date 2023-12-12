#include<stdio.h>
#include<math.h>
int main(){
	int basamak = 0;
	long int o = 0;
	long int s = 0;
	long int ss;
	//scanf("%d",&s);
	s = 1011101010;
	ss=s;
	while(s>0){
		s = s/10;
		basamak += 1;
	}
	int a;
	int t;

	for(a=0;a<basamak;a++){
		t = ss % 10;
		ss = ss / 10;
		o = o+(t*pow(2,a));
		
		
	}
	printf("%d",o);

	
	
	
	
	
	
	
	return 0;
}
