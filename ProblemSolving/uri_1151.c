#include<stdio.h>
int main()
{
    int n, i;
    int fib[47];
    fib[0] = 0;
    fib[1] = 1;
    scanf("%d", &n);
    for(i=2; i<n; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    for(i=0; i<n; i++){
        printf("%d", fib[i]);
        if(i==n-1) printf("\n");
        else printf(" ");
    }
}
