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
#define debugi(x, i)  cout<<" <<debug>> "<< #x <<"["<<i<<"]"<<": "<<x<<endl
#define all(a)        a.begin(),a.end()
#define endl          '\n'
#define sp            ' '
#define ff            first
#define ss            second
#define sf            second.first
#define mem(a,v)      memset((a), v, sizeof(a))
#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define CEIL(x,y)     ((x)%(y)==0 ? (x)/(y) : ((x)/(y))+1)
#define ABS(x)        ((x)<0?-(x):(x))
#define PI            acos(-1.0)
#define ERR           0.000000001
#define INF           1000000007
#define mod           1000000007
#define mxn           110

intl ar[mxn], n;

intl solve(int idx)
{
    intl cost = 0LL;
    rep(i, 0, n){
        cost += ar[i] * 2 * (abs(i-idx) + i + idx);
    }
    return cost;
}

int main()
{
    cin>>n;

    rep(i, 0, n) cin>>ar[i];

    intl ans = INT_MAX;
    rep(i, 0, n){
        ans = min(ans, solve(i));
    }

    cout<<ans<<endl;

    return 0;
}


