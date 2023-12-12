#include <stdio.h>

#define MAX_SIZE 100

int check_value(int A[], int valueA);
void delete_element(int A[], int pos);

int SIZE;

int main() {
    int A[MAX_SIZE];
    printf("Enter integer values for the array (up to %d elements):\n", MAX_SIZE);
    int i = 0;
    do {
        scanf("%d", &A[i]);
        i++;
    } while (A[i-1] != -1 && i < MAX_SIZE);
    SIZE = i-1; 

    int value;
    do {
        printf("\nEnter a value to delete (-1 to stop): ");
        scanf("%d", &value);
        if (value != -1) {
            int pos = check_value(A, value);
            if (pos != -1) {
                delete_element(A, pos);
            } else {
                printf("Value not found in array.\n");
            }
        }
    } while (value != -1);
    
    printf("\nRemaining elements in array:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}

int check_value(int A[], int valueA) {
    int i;
    for (i = 0; i < SIZE; i++) {
        if (A[i] == valueA) {
            return i;
        }
    }
    return -1;
}

void delete_element(int A[], int pos) {
    int i;
    for (i = pos; i < SIZE-1; i++) {
        A[i] = A[i+1]; 
    }
    SIZE--; 
}
