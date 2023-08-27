#include<stdio.h>

int main()
{

    long long int n, k;
    scanf("%lld %lld", &n, &k);

    long long int inp[n];

    int i, j;

    for(i=1, j=0; i<=n; i=i+2, j++){
        inp[j] = i;
    }

    for(i=2; i<=n; i+=2, j++){
        inp[j] = i;
    }

    printf("%lld\n", inp[k-1]);

    return 0;
}

