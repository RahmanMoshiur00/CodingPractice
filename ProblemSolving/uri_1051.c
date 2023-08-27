#include<stdio.h>
int main()
{
    double tk;
    scanf("%lf", &tk);
    if(tk>=0.00 && tk<=2000.00) printf("Isento\n");
    else if(tk>=2000.01 && tk<=3000.00) printf("R$ %.2lf\n", (tk-2000.00)*.08);
    else if(tk>=3000.01 && tk<=4500.00) printf("R$ %.2lf\n", (1000*.08)+((tk-3000.00)*.18));
    else if(tk>4500.00) printf("R$ %.2lf\n", (1000*.08)+(1500*.18)+((tk-4500.00)*.28));
}
