#include<stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        long long a, b, c, i;
        scanf("%lld %lld %lld", &a, &b, &c);
        for(i=a*b; i<=c; i += a*b) printf("%lld\n", i);
        printf("\n");
    }
    return 0;
}
