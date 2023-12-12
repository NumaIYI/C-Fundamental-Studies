#include<stdio.h>

int main(){
	int grade;
	printf("Write your grade: ");
	scanf("%d",&grade);
	if (grade >= 0){
	
	if (grade <= 100){
		
	if (grade > 90){
		printf("you have A");
	}
	else{
		if(grade > 80){
			printf("you have B");
		}
		else{
			if(grade > 70){
				printf("you have C");	
			}
			else{
				if(grade > 60){
				printf("you have D");	
				}
				else{
					printf("You are done. Try again...");
						}
					}
				}
			}
		}
		else{
		printf("please write a grade which between hundred and zero");
		}
	}
	else{
		printf("please write a grade which between hundred and zero");
		}
	return 0;
}
