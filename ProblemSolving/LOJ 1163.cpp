#include<bits/stdc++.h>
using namespace std;
typedef long long ull;

int main()
{
    int tc; scanf("%lld", &tc);
    ull n, i;
    for(int t=1; t<=tc; t++){
        scanf("%lld", &n);
        printf("Case %d:", t);
        for(i=n*1.111111; ; i++){
            if((i - (i/10)) == n) { printf(" %llu", i); break;}
        }
        if(n%9==0) printf(" %llu", i+1);
        printf("\n");
    }
    return 0;
}
