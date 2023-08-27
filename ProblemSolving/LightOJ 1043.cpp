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

double ab, ac, bc, r;

double area(double a, double b, double c)
{
    double s = (a+b+c) / 2;
    double ret = sqrt(s*(s-a)*(s-b)*(s-c));
    return ret;
}

bool f(double ad)
{
    double ae = (ad * ac) / ab;
    double de = (ad * bc) / ab;

    double ade = area(ad, de, ae);
    double bdec = ade / r;
    double abc = area(ab, bc, ac);

    return (ade + bdec >= abc);
}

void solve(int tc)
{
    cin>>ab>>ac>>bc>>r;

    double lo = 0, hi = ab, mid, ans;
    while(hi-lo > ERR){
        mid = lo + (hi-lo)/2;
        if(f(mid)) hi = mid;
        else lo = mid;
    }

    cout<<fixed<<setprecision(12)<<"Case "<<tc<<": "<<hi<<endl;
}

int main()
{
    int tc; cin>>tc;

    rep(t, 1, tc+1) solve(t);

    return 0;
}


