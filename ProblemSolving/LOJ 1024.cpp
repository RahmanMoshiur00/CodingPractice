#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define MX 1001
ull arr[MX];
ull ans, lcm, tmp;

int main()
{
    int tc, n;
    scanf("%d", &tc);

    for(int t=1; t<=tc; t++){
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%llu", &arr[i]);
        lcm = arr[0];
        for(int i=1; i<n; i++){
            lcm = (lcm*arr[i]) / __gcd(lcm, arr[i]);
            ans = max(ans, lcm);
        }
        printf("Case %d: %llu\n", t, ans);
    }
    return 0;
}
