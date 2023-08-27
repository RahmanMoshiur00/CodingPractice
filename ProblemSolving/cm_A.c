#include<stdio.h>
int main()
{
    int t, l;
    scanf("%d", &t);
    for(l=1; l<=t; l++){
        long long n;
        scanf("%lld", &n);
        printf("Case %d: %lld\n", l, n/2);
    }
    return 0;
}
