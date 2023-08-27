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


void solve()
{
    double A, B, C, D, E, F, G, a, b, c, theta, beta, gama, s;
    cin>>A>>B>>C;

    a = sqrt(A) , b = sqrt(B), c = sqrt(C);

    s = (a+b+c) / 2;

    G = sqrt(s*(s-a)*(s-b)*(s-c));

    theta = asin((2*G) / (b*c));
    theta = PI - theta;

    beta = asin((2*G) / (a*c));
    beta = PI - beta;

    gama = asin((2*G) / (a*b));
    gama = PI - gama;

    E = 0.5 * a * b * sin(gama);
    D = 0.5 * a * c * sin(beta);
    F = 0.5 * b * c * sin(theta);

    double ans = A + B + C + D + E + F + G;

    cout<<ans<<endl;
}


int main()
{
    int tc; cin>>tc;

    cout<<fixed<<setprecision(10);
    while(tc--) solve();

    return 0;
}


