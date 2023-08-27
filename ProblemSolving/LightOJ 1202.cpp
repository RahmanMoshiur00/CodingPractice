#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for(int l=1; l<=t; l++){
        long long x1, y1, x2, y2;
        scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
        long long x = abs(x2-x1);
        long long y = abs(y2-y1);
        if(x==y) printf("Case %d: 1\n", l);
        else if(x%2 == y%2) printf("Case %d: 2\n", l);
        else printf("Case %d: impossible\n", l);
    }
    return 0;
}
