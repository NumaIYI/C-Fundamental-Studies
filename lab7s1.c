#include<stdio.h>



void get_film_rating(){
	int star_wars_rating[12]={0,0,0,0,0,0,0,0,0,0,0,0};
	int i;
	for (i=0;i<12;i++){
		scanf("%d",&star_wars_rating[i]);
	}
	return star_wars_rating;
}

void sorted_star_wars(int sorted_rating){
	
	
	
	
}

void print_sorted_names(){
	
	
	
	
}

int star_wars_rating(){
	
	
	
	
}



int main(){
	
	int sorted_rating[12]={0,1,2,3,4,5,6,7,8,9,10,11};
	int star_wars_rating[12]={0,0,0,0,0,0,0,0,0,0,0,0};
	int l;
	for (l=0;l<12;l++){
		scanf("%d",&star_wars_rating[l]);
	}
	int gecici;
	int gec;
	int i;
	for(i= 0;i<11;i++){
	int j;
		for(j =i+1;j<12;j++){
			if(star_wars_rating[j]>star_wars_rating[i]){
				gecici = star_wars_rating[i];
				gec = sorted_rating[i];
				star_wars_rating[i] = star_wars_rating[j];
				sorted_rating[i] = sorted_rating[j];
				star_wars_rating[j]=gecici;
				sorted_rating[j]=gec;
			}
		}	
	}
	int k;
	for (k=0;k<12;k++){
		printf("%d ",sorted_rating[k]);
	}
	
	char star_wars_names[12][60]={"Episode IV: A New Hope (1977)", 
    "Episode V: The Empire Strikes Back (1980)",
    "Episode VI: Return of the Jedi (1983)",
    "Episode I: The Phantom Menace (1999)",
    "Episode II: Attack of the Clones (2002)",
    "Episode III: Revenge of the Sith (2005)",
    "Star Wars: The Clone Wars (2008)",
    "Episode VII: The Force Awakens (2015)",
    "Rogue One: A Star Wars Story (2016)",
    "Episode VIII: The Last Jedi (2017)",
    "Solo: A Star Wars Story (2018)",
    "Episode IX: The Rise of Skywalker (2019)"};
    printf("\n");
    
	int f;
	for(f=0;f<12;f++){
		printf("%s\n",star_wars_names[sorted_rating[f]]);
			}
	
	
	

	
	
	
	
	
	
	
	return 0;
}
