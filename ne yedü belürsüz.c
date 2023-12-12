#include<stdio.h>
struct data{
    double aver;
    double eror;
};
struct data func(int n, double A[]){
    int i, j;
    double total = 0.0;
    for(j = 0; j < n; j++){
        total += A[j];
    }
    double avg = total / n;
    double sumt = 0.0;
    for(i = 0; i < n; i++){
        sumt += (A[i] - avg) * (A[i] - avg);
    }
    struct data value;
    value.aver = avg;
    value.eror = sqrt(sumt / n);
    return value;
}
void display(struct data who){
    printf("Ortalama: %.2f\n", who.aver);
    printf("Standart sapma: %.2f", who.eror);
}
int main(){
    int i, n;
    double s;
    printf("Ogrenci mevcudunuz kac: ");
    scanf("%d", &n);
    double A[n];
    for(i = 0; i < n; i++){
        printf("%d. Ogrenci notu: ", i + 1);
        scanf("%lf", &A[i]);
    }
    display(func(n,A));
    return 0;
}
