#include<stdio.h>

unsigned long fact(int n, int base){
    if(n==0) return base;
    else return fact(n-1, base)*n;
}
int main()
{
    int t, j;
    scanf("%d", &t);
    for(j=1; j<=t; j++){
        int n, base;
        scanf("%d %d", &n, &base);
        printf("Case %d: %lu\n", j, fact(n, base));
    }
}
