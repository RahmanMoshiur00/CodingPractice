#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define repeach(it, x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(0); cin.tie(0);
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


double x, y, z;

bool f(double w)
{
    double p = sqrt((x*x) - (w*w));
    double q = sqrt((y*y) - (w*w));
    double c = (p*q) / (p+q);

    return (c >= z);
}

void solve(int tc)
{
    double lo, hi, mid;
    cin>>x>>y>>z;

    lo = 0.0, hi = min(x,y);

    rep(i, 0, 100){
        mid = (lo+hi)/2.0;
        if(f(mid)) lo = mid; // c and mid is reversely proportional; so if c is bigger we need to increase mid to make c smaller(nearer to the solution)
        else hi = mid;
    }


    cout<<"Case "<<tc<<": "<<lo<<endl;
}

int main()
{
    int tc; cin>>tc;

    cout<<fixed<<setprecision(12);
    rep(t, 1, tc+1) solve(t);

    return 0;
}


