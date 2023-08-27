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

double a, b;

bool f(double x)
{
    double y = (b*x) / a;
    double r = sqrt((x*x) + (y*y)) / 2.0;
    double theta = 2 * asin((y/2)/r);  // hint: find the perimeter of the curve of the circle using perimeter theorem i.e. perimeter of curve of angle "theta" = theta*r; e.g. full perimeter = 2*pi*r where theta = 2*pi
    double perimeter = (2*x) + (2*theta*r);

    return (perimeter >= 400);
}


void solve(int tc)
{
    cin>>a;
    getchar(); getchar(); getchar();
    cin>>b;

    double lo = 0.0, hi = 400.00, mid;

    rep(i, 0, 100){
        mid = (lo+hi)/2;
        if(f(mid)) hi = mid;
        else lo = mid;
    }

    double x = hi;
    double y = (x*b) / a;

    cout<<"Case "<<tc<<": "<<x<<sp<<y<<endl;
}

int main()
{

    int tc; cin>>tc;

    cout<<fixed<<setprecision(12);
    rep(t, 1, tc+1) solve(t);

    return 0;
}


