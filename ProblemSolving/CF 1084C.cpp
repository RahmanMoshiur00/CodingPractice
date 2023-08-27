#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define repeach(it, x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(0); cin.tie(0);
#define debug(x)      cout<<" <<debug>> "<< #x <<": "<<x<<endl
#define all(a)        a.begin(),a.end()
#define find(x, a)    x.find(a) != x.end()
#define endl          '\n'
#define sp            ' '
#define ff            first
#define ss            second
#define sf            second.first
#define sd            second.second
#define mem(a,v)      memset((a), v, sizeof(a))
#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define CEIL(x,y)     ((x)%(y)==0 ? (x)/(y) : ((x)/(y))+1)
#define ABS(x)        ((x)<0?-(x):(x))
#define PI            acos(-1.0)
#define ERR           0.000000001
#define INF           1000000007
#define mod           1000000007
#define mxn           100010



int main()
{
    string s, str;
    cin>>s;

    bool aFound = false;
    rep(i, 0, s.size()){
        if(s[i] == 'a') str += s[i], aFound = true;
        else if(s[i] == 'b' and aFound and *str.rbegin() != 'b') str += s[i];
    }

    debug(str);

    intl ans = 1LL, noa = 0, atotal = 0;
    rep(i, 0, str.size()){
        if(str[i] == 'a') noa++ , atotal++;
        else{
            ans = ((ans%mod) * (noa%mod)) % mod;
            noa = 0;
        }
    }
    if(noa and ans!=1) ans = ((ans%mod) * (noa%mod)) % mod;

    if(ans == 1) ans = atotal;
    else ans = ((ans%mod) + (atotal%mod)) % mod;

    cout<<ans<<endl;

    return 0;
}
