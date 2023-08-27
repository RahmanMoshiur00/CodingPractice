#include<math.h>
int main()
{
    double n[3];
    int i;
    scanf("%lf %lf %lf", &n[0], &n[1], &n[2]);
    for(i=0; i<3; i++){
        int j;
        for(j=i+1; j<3; j++){
            if(n[i]<n[j]){
                double x = n[i];
                n[i] = n[j];
                n[j] = x;
            }
        }
    }
    double a = n[0], b = n[1], c = n[2];
    if(a>=b+c){
        printf("NAO FORMA TRIANGULO\n");
        goto end;
    }
    if((a*a) == ((b*b) + (c*c))){
        printf("TRIANGULO RETANGULO\n");
    }
    if((a*a) > ((b*b) + (c*c))){
        printf("TRIANGULO OBTUSANGULO\n");
    }
    if((a*a) < ((b*b) + (c*c))){
        printf("TRIANGULO ACUTANGULO\n");
    }
    if(a==b && b==c) printf("TRIANGULO EQUILATERO\n");
    else if((a==b && a!=c) || (b==c && b!=a) || (c==a && c!=b)) printf("TRIANGULO ISOSCELES\n");
    end:
        return 0;
}
