#include<bits/stdc++.h>

int main()
{
    int t;
    scanf("%d ", &t);
    for(int l=1; l<=t; l++){
        long long n, m;
        scanf("%lld %lld", &n, &m);
        long long sum = (n/2) * m;
        printf("Case %d: %lld\n", l, sum);
    }
    return 0;
}
