#include<bits/stdc++.h>
using namespace std;
typedef long long intt;
typedef unsigned long long ull;
#define pb     push_back
#define MX     5000000

int phi[MX+1];
ull sum[MX+1];

void phi_sieve(int N)
{
    ull t;
    phi[1] = 1;
    sum[1] = 1;

    for(int i=2; i<=N; i++) phi[i] = i;
    for (int i=2; i<=N; i++)
    {
        if (phi[i] == i)
        {
            phi[i] = i - 1;
            for(int j=2*i; j<=N; j+=i) phi[j] = (phi[j]/i) * (i-1);
        }
        t = phi[i]; t *= phi[i]; //for square
        sum[i] = sum[i-1] + t; //cumulative sum
    }
}


int main()
{
    phi_sieve(MX);

    int tc, a, b, r;
    scanf("%d", &tc);

    for(int t=1; t<=tc; t++){
        scanf("%d %d", &a, &b);
        printf("Case %d: %llu\n", t, sum[b]-sum[a-1]);
    }
    return 0;
}
