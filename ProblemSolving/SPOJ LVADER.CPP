#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long int intl;
typedef unsigned long long intu;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //e.g. ordered_set<int> s; s.insert(3); cout<<s.ook(3)<<*s.fbo(3);
#define ook           order_of_key
#define fbo           find_by_order //returns pointer
#define all(a)        a.begin(),a.end()
#define Unique(a)     sort(all(a)),a.erase(unique(all(a)),a.end())
#define INOUT         freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define FasterIO      ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl          "\n"
#define sp            " "
#define sfi(x)        scanf("%d", &x)
#define sfl(x)        scanf("%lld", &x)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfu(x)        scanf("%llu", &x)
#define pfi(x)        printf("%d\n", x)
#define pfl(x)        printf("%lld\n", x)
#define pfu(x)        printf("%llu\n", x)
#define debug(x)      cout<<">debug> "<< #x <<" : "<<x<<endl
#define fr(i,a,b)     for(intl i=(a); i<=(b); i++)
#define pb            push_back
#define mp            make_pair
#define ff            first
#define ss            second
#define sf            second.first
#define ssd           second.second
#define mem(a,v)      memset((a), v, sizeof(a))
#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define SQ(a)         ((a)*(a))
#define ABS(x)        ((x)<0?-(x):(x))
#define PI            acos(-1.0)
#define INF           1000000000
#define mod           1000000007LL
#define mxn           200010


intl f[mxn];

void factorial(){
    f[0] = f[1] = 1LL;
    for(int i=2; i<mxn; i++) f[i] = (i * f[i-1])%mod;
}

intl bigmod(intl b, intl p){ //finds (b^p)%mod
    intl res = 1LL;
    b = b % mod;  //Update b if it is more than or equal to p
    while(p > 0LL)
    {
        if(p & 1) res = (res*b) % mod; // If p is odd, multiply b with result
        p = p>>1; // p must be even now; then, p = p/2
        b = (b*b) % mod;
    }
    return res;
}

intl modinv(intl n){ //finds (1/n)%mod
    return bigmod(n, mod-2);
}

intl nCr(int n, int r){
    return ((f[n] * modinv(f[r]))%mod * modinv(f[n-r])) % mod;
}


int main()
{
    int sr, sc, er, ec, t, N, C, R, D;
    sfi(t);

    factorial();

    for(int tc=1; tc<=t; tc++){
        scanf("%d %d %d %d", &sr, &sc, &er, &ec);
        R = ABS(er-sr) , C = ABS(ec-sc) , N = R+C;
        D = min(R,C);
        intl res = 0LL, k;
        for(int i=0; i<=D; i++){
            k = (((f[N-i] * modinv(f[R-i]))%mod * modinv(f[C-i]))%mod * modinv(f[i])) % mod; //k = (N-1)! / ((R-1)!*(C-1)!*i!)
            //k = (nCr(N-i, R) * nCr(R, i)) % mod;  //this is equal to the upper statement; but upper statement is easier to understand
            res = (res+k)%mod;
        }

        printf("Case %d: %lld\n", tc, res);
    }

    return 0;
}
