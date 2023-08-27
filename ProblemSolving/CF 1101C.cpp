#include <bits/stdc++.h>
using namespace std;
typedef int intt;
typedef long long int intl;
typedef unsigned long long intu;
#define int           long long
#define sfi(x)        scanf("%lld", &x)
#define sfi2(x, y)    scanf("%lld %lld", &x, &y)
#define sfi3(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define pfi(x)        printf("%lld", (intl)x)
#define pfi2(x, y)    printf("%lld %lld", (intl)x, (intl)y)
#define pfi3(x, y, z) printf("%lld %lld %lld", (intl)x, (intl)y, (intl)z)
#define sfd(x)        scanf("%lf", &x)
#define sfd2(x, y)    scanf("%lf %lf", &x, &y)
#define sfd3(x, y, z) scanf("%lf %lf %lf", &x, &y, &z)
#define sfs(x)        scanf("%s", x)
#define sfsn(x)       scanf("%[^\n]s", x)
#define pfs(x)        printf("%s", x)
#define space         printf(" ")
#define newl          printf("\n")
#define endl          '\n'
#define sp            ' '
#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(0); cin.tie(0);
#define watch(x)      cout<<"::debug::   "<< #x <<" : "<<x<<endl
#define watchi(x, i)  cout<<"::debug::   "<< #x <<"-> ["<<i<<"]"<<" : "<<x<<endl
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define repit(it, x)  for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define rep(i, begin, end) for (__typeof(end) i = (begin); i < (end); i += 1)
#define per(i, end, begin) for (__typeof(end) i = (end)-1; i >= (begin); i -= 1)
#define all(a)        a.begin(), a.end()
#define PB            push_back
#define MP            make_pair
#define mem(a, v)     memset((a), v, sizeof(a))
#define min3(a, b, c) min(a,min(b,c))
#define max3(a, b, c) max(a,max(b,c))
#define ff              first
#define ss              second.first
#define tt              second.second
#define CEIL(x, y)    ((x)%(y)==0 ? (x)/(y) : ((x)/(y))+1)
#define ABS(x)        ((x)<0?-(x):(x))
#define SQ(x)         ((x)*(x))
#define PI            acos(-1.0)
#define ERR           0.000000001
#define INF           1000000007
#define mod           1000000007
#define debug         if( 1 )
#define mxn           100010

typedef vector< pair< int, pair<int, int> > > piii;

bool inSeg(int a, int b, int l, int r)
{
    return ((a>=l and a<=r) or (b>=l and b<=r));
}

void solve(int tc)
{
    int n; sfi(n);
    piii vp(n);

    rep(i, 0, n){
        sfi2(vp[i].ff, vp[i].ss);
        vp[i].tt = i;
    }

    sort(all(vp));

    int ans[n];

    ans[vp[0].tt] = 1;
    int l1 = vp[0].ff, r1 = vp[0].ss, l2 = -1, r2 = -1, one = 1, two = 0;

    rep(i, 1, n){
        int l = vp[i].ff, r = vp[i].ss, idx = vp[i].tt;

        if(inSeg(l, r, l1, r1)){ //[l, r] is intersects in union 1
            if((l2==-1 and r2==-1) or ((l2!=-1 and r2!=-1) and !inSeg(l, r, l2, r2))){ //[l, r] does not intersect in union 2
                ans[idx] = 1;
                l1 = min(l1, l);
                r1 = max(r1, r);
                one++;
            }
            else{ // [l, r] intersects in union 2
                cout<<-1<<endl;
                return;
            }
        }
        else if(l2==-1 and r2==-1){ //[l, r] not in union 1 but can be initialized in union 2
            ans[idx] = 2;
            l2 = l;
            r2 = r;
            two++;
        }
        else if(inSeg(l, r, l2, r2)){ //[l, r] is in union 2
            if(!inSeg(l, r, l1, r1)){ //[l, r] is not in union 1
                ans[idx] = 2;
                l2 = min(l2, l);
                r2 = max(r2, r);
            }
            else{ //[l, r] is in union 1
                cout<<-1<<endl;
                return;
            }
        }
        else{
            ans[idx] = 1;
            l1 = min(l1, l);
            r1 = max(r1, r);
            one++;
        }
    }

    if(two == 0){
        cout<<-1<<endl;
        return;
    }
    rep(i, 0, n){
        if(!i) cout<<ans[i];
        else cout<<sp<<ans[i];
    }
    cout<<endl;
}

int32_t main()
{
    //INPUT
    //FastRead
    //solve(1);
    int tc; sfi(tc); rep(t, 1, tc+1) solve(t);

    return 0;
}

