#include<bits/stdc++.h>
using namespace std;
#define M 10000007
typedef long long intt;

int main(){
    intt n, tc, a, b, c, d, e, f, ans;
    cin>>tc;
    for(intt t=1; t<=tc; t++){
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        vector<intt> arr(n+1);
        if( n == 0 ) ans = a;
        if( n == 1 ) ans = b;
        if( n == 2 ) ans = c;
        if( n == 3 ) ans = d;
        if( n == 4 ) ans = e;
        if( n == 5 ) ans = f;
        if(n>=0 && n<=5){
            printf("Case %lld: %lld\n", t, ans%M);
            continue;
        }
        arr[0] = a;
        arr[1] = b;
        arr[2] = c;
        arr[3] = d;
        arr[4] = e;
        arr[5] = f;
        for(intt i=6; i<=n; i++){
            arr[i] = (arr[i-1] + arr[i-2] + arr[i-3] + arr[i-4] + arr[i-5] + arr[i-6])%M;
        }
        printf("Case %lld: %lld\n", t, arr[n]%M);
        arr.clear();
    }
    return 0;
}
