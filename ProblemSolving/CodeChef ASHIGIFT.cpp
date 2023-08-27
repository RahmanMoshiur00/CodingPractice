#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define sfi(x)        scanf("%d", &x)
#define sfi2(x, y)    scanf("%d %d", &x, &y)
#define sfi3(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sfl(x)        scanf("%lld", &x)
#define sfl2(x, y)    scanf("%lld %lld", &x, &y)
#define sfl3(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define sfd(x)        scanf("%lf", &x)
#define sfd2(x, y)    scanf("%lf %lf", &x, &y)
#define sfd3(x, y, z) scanf("%lf %lf %lf", &x, &y, &z)
#define sfs(x)        scanf("%s", x)
#define sfsn(x)       scanf("%[^\n]s", x)
#define pfi(x)        printf("%d", x)
#define pfi2(x, y)    printf("%d %d", x, y)
#define pfi3(x, y, z) printf("%d %d %d", x, y, z)
#define pfl(x)        printf("%lld", x)
#define pfl2(x, y)    printf("%lld %lld", x, y)
#define pfl3(x, y, z) printf("%lld %lld %lld", x, y, z)
#define pfs(x)        printf("%s", x)
#define space         printf(" ")
#define newl          printf("\n")
#define FastRead      ios::sync_with_stdio(0); cin.tie(0);
#define debug(x)      cout<<" <<debug>> "<< #x <<": "<<x<<endl
#define debugi(x, i)  cout<<" <<debug>> "<< #x <<"["<<i<<"]"<<": "<<x<<endl
#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define repeach(it, x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define found(x, a)    x.find(a) != x.end()
#define all(a)        a.begin(),a.end()
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
#define mxn           10010

intl n, dish, dish_pos[mxn], dish_power[mxn], clan, clan_pos[mxn], clan_beg[mxn], clan_size[mxn];


bool f(intl x)
{
    intl have = x, c = 0;

    rep(i, 0, dish){
        while(c<clan and clan_pos[c]<=dish_pos[i]){
            if(have >= clan_beg[c]) have += clan_size[c];
            c++;
        }
        if(have >= dish_power[i]) have -= dish_power[i];
        else return false;
    }

    return (have > 0);
}


void solve(int tc)
{
    sfl(n);
    sfl(dish);

    intl lo = 0, hi = 1, mid; //hi = 1; because at least one person have to reach Suraj(destination)
    rep(i, 0, dish) sfl2(dish_pos[i], dish_power[i]) , hi += dish_power[i];

    sfl(clan);
    rep(i, 0, clan) sfl3(clan_pos[i], clan_beg[i], clan_size[i]);

    while(hi - lo > 1){
        mid = (hi + lo) / 2;
        if(f(mid)) hi = mid;
        else lo = mid;
    }

    rep(i, lo, hi+1){
        if(f(i)){
            pfl(i), newl;
            return;
        }
    }
}

int main()
{
    int tc; sfi(tc); rep(t, 1, tc+1) solve(t);

    return 0;
}
