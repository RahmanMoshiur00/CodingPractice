#include<stdio.h>
#include<math.h>
int main()
{
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    double nirnayok = (b*b) - (4.0*a*c);
    if(nirnayok<0.0 || a==0.0) printf("Impossivel calcular\n");
    else{
        printf("R1 = %.5lf\n", (-b+sqrt(nirnayok)) / (2.0*a));
        printf("R2 = %.5lf\n", (-b-sqrt(nirnayok)) / (2.0*a));
    }
}
