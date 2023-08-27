#include<stdio.h>


int main()
{
    long int n;
    scanf("%lu", &n);

    for(long long int i=1;)
    printf("%lu\n", fib(n-1)%10000000000000000);
    return 0;
}
