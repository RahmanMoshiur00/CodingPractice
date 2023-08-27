#include<stdio.h>
int main()
{
    double a, b, c, d;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    double avg = ((a*2.0) + (b*3.0) + (c*4.0) +(d*1.0)) / 10.0;
    if(avg>=7.0){
        printf("Media: %.1lf\n", avg);
        printf("Aluno aprovado.\n");
    }
    else if(avg<5.0){
        printf("Media: %.1lf\n", avg);
        printf("Aluno reprovado.\n");
    }
    else if(avg>=5.0 && avg<=6.9){
        printf("Media: %.1lf\n", avg);
        printf("Aluno em exame.\n");
        double x;
        scanf("%lf", &x);
        printf("Nota do exame: %.1lf\n", x);
        if((avg+x)/2.0 >=5.0) printf("Aluno aprovado.\n");
        else printf("Aluno reprovado.\n");
        printf("Media final: %.1lf\n", (avg+x)/2.0);
    }
    return 0;
}
