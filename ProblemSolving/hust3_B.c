#include<stdio.h>

int main()
{
    long long n, k;
    scanf("%lld %lld", &n, &k);
    if (k <= (n + 1) / 2)
    {
        printf("%lld\n", k * 2 - 1);
    }
    else
    {
        printf("%lld\n", (k - (n + 1) / 2) * 2);
    }
    return 0;
}
