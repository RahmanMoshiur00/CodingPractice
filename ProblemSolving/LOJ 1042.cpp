#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define count_one __builtin_popcountl

int main()
{
    int tc;
    scanf("%d", &tc);
    ll r, n;
    bool check;
    for(int t=1; t<=tc; t++){
        scanf("%lld", &n);
        check = false;
        for(ll i=0; i<=32; i++){
            if(pow(2LL, i)==n){
                check = true;
                break;
            }
        }
        if(check){ printf("Case %d: %lld\n", t, n*2); continue; }
        r = count_one(n);
        for(ll i=n+1; ; i++){
            if(count_one(i)==r){ printf("Case %d: %lld\n", t, i); break; }
        }
    }
    return 0;
}
