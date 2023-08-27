#include<stdio.h>
int main()
{
    double sal;
    scanf("%lf", &sal);
    if(sal>=0.00 && sal<=400.00){
        printf("Novo salario: %.2lf\n", (sal*.15) + sal );
        printf("Reajuste ganho: %.2lf\n", sal*.15);
        printf("Em percentual: 15 %\n");
    }
    else if(sal>=400.01 && sal<=800.00){
        printf("Novo salario: %.2lf\n", (sal*.12) + sal );
        printf("Reajuste ganho: %.2lf\n", sal*.12);
        printf("Em percentual: 12 %\n");
    }
    else if(sal>=800.01 && sal<=1200.00){
        printf("Novo salario: %.2lf\n", (sal*.10) + sal );
        printf("Reajuste ganho: %.2lf\n", sal*.10);
        printf("Em percentual: 10 %\n");
    }
    else if(sal>=1200.01 && sal<=2000.00){
        printf("Novo salario: %.2lf\n", (sal*.07) + sal );
        printf("Reajuste ganho: %.2lf\n", sal*.07);
        printf("Em percentual: 7 %\n");
    }
    else if(sal>=2000.00){
        printf("Novo salario: %.2lf\n", (sal*.04) + sal );
        printf("Reajuste ganho: %.2lf\n", sal*.04);
        printf("Em percentual: 4 %\n");
    }
}
