#include<bits/stdc++.h>
using namespace std;
#define FI freopen("in.txt","r",stdin)
#define FO freopen("out.txt","w",stdout)
#define MS(x,v) memset(&x,v,sizeof(x))
#define CL(x) memset(&x,0,sizeof(x))
#define mp make_pair
#define pb push_back
#define ss second
#define fi first
#define vanish scanf("\n")
#define nl puts("")
#define endl '\n'
#define i64 long long
#define all(x) x.begin(),x.end()
#define Iterate(s) for(typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define FOR(i,k,n) for(__typeof(n) i = (k); i <= (n); ++i)
#define For(i,k,n) for(__typeof(n) i = (k); i < (n); ++i)
#define ROF(i,k,n) for(__typeof(n) i = k; i >= n; i--)
#define REP(i,n) for(__typeof(n) i = 0; i < (n); ++i)
#define sq(x) ((x)*(x))
#define PI acos(-1.0)
#define EPS 0.0000001
#define MOD 1000000007
#define oo 100000000000000LL
#define MAX 200005
int main(){
//FI;
int t,T=0;
scanf("%d",&t);
while(t--){
i64 x;
scanf("%lld",&x);
printf("Case %d: ",++T);
if( x>=180 && x%180 == 0 ){
i64 n = (x/180LL) + 2LL;
double p = double(x)/double(n);
i64 m = (i64)round(p);
printf("%lld %lld\n",n,m);
}else
printf("Impossible\n");
}
return 0;
}
