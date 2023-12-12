#include<stdio.h>
#include<math.h>

int main(void){
    int a,b,c, cevre;
    float alan, u;
    printf("a kenarini girin:");
    scanf("%d",&a);

    printf("b kenarini girin:");
    scanf("%d",&b);

    printf("c kenarini girin:");
    scanf("%d",&c);
    if (((a+b>c) && (a-b<c)) || ( (a+c>b) && (a-c<b)) || ((b+c>a) && (b-c<a))){
        printf("Bir ucgen cizilebilir. \n");
        cevre = a+b+c;
        u = cevre/2;
        alan = pow((u*(u-a)*(u-b)*(u-c)), 0.5);
        if (((a==b) && (b==c) && (a==c))){
            printf("Es kenar Ucgen\n");
            printf("Alan: %f\n", alan);
            printf("Cevre: %d\n", cevre);
        
        }
        else if ((!(a==b) && !(a==c) && !(b==c))){
            printf("Cesitkenar Ucgen\n");
            printf("Alan: %f\n", alan);
            printf("Cevre: %d\n", cevre);
        }
        else{
            printf("Ýkiz Kenar Ucgen\n");
            printf("Alan: %f\n", alan);
            printf("Cevre:v%d\n", cevre);
        }
    }
    else{
        printf("Ucgen Cizilemez!");
    }
    
    return 0;
}
