#include<stdio.h>
int main()
{
    int sum=0, n, i, coelho=0, rat=0, frog=0;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        int qnt;
        char name;
        scanf("%d %c", &qnt, &name);

        if(name=='C') coelho += qnt;
        else if(name=='R') rat += qnt;
        else if(name=='S') frog += qnt;
        sum += qnt;
    }
    printf("Total: %d cobaias\n", sum);
    printf("Total de coelhos: %d\n", coelho);
    printf("Total de ratos: %d\n", rat);
    printf("Total de sapos: %d\n", frog);
    printf("Percentual de coelhos: %.2lf %%\n", ((double)coelho/(double)sum)*100.00);
    printf("Percentual de ratos: %.2lf %%\n", ((double)rat/(double)sum)*100.00);
    printf("Percentual de sapos: %.2lf %%\n", ((double)frog/(double)sum)*100.00);
}
