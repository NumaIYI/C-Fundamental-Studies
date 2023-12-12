#include <stdio.h>
void my_sort(int a[], int low, int high);
int divide(int a[], int low, int high);



int main(){
    int size;
    printf("how many integers: \n");
    scanf("%d", &size);
    int a[size];
    int i;
    printf("write integers with space or enter: \n");
	for(i=0; i<size; i++){
	    scanf("%d", &a[i]);
    }
    
    my_sort(a, 0, size-1);
    
    
    int j;
    for(j=0; j<size; j++){
	
        printf("%d ", a[j]);
	}
    return 0;
}



void my_sort(int a[], int low, int high){
    if(low<high){
        int middle = divide(a, low, high);
        my_sort(a, low, middle-1);
        my_sort(a, middle+1, high);
    }
}



int divide(int a[], int low, int high){
    int middle = a[low], temp_low = low+1, temp_high = high;
    
    while(temp_low <= temp_high){
    	while(a[temp_high] > middle && temp_high>=low)
            temp_high--;
        while(a[temp_low] < middle && temp_low<=high)
            temp_low++;
        
        if(temp_low<=temp_high){
            int temp = a[temp_low];
            a[temp_low] = a[temp_high];
            a[temp_high] = temp;
            temp_low++;
            temp_high--;
        }
    }
    
    a[low] = a[temp_high];
    a[temp_high] = middle;
    return temp_high;
}
