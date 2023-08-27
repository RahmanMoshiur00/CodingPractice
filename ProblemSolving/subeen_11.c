#include<stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        int n, i;
        scanf("%d", &n);
        long long count = 1;
        for(i=2; i<=n; i++) count *= i;
        printf("%lld\n", count);
    }
    return 0;
}
