#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define int           long long

#define sfi(x)        scanf("%lld", &x) // changes
#define sfi2(x, y)    sfi(x) , sfi(y)
#define sfi3(x, y, z) sfi(x) , sfi(y) , sfi(z)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfsn(x)       scanf(" %[^\n]s", x)

#define pfi(x)        printf("%lld", (intl)x) // no changes
#define pfin(x)       printf("%lld", (intl)x), printf("\n")
#define pfis(x)       printf("%lld", (intl)x), printf(" ")
#define pfc(x)        printf("%c", x)
#define pfs(x)        printf("%s", x)
#define pfsn(x)       printf("%s", x), printf("\n")
#define spc           printf(" ")
#define nwl           printf("\n")
#define endl          '\n'
#define sp            ' '

#define watch(x)      cout<<"::debug::   "<< #x <<" : "<<x<<endl
#define watchi(x, i)  cout<<"::debug::   "<< #x <<"-> ["<<i<<"]"<<" : "<<x<<endl

#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(false), cin.tie(0);

#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define repit(it, x)  for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define perit(it, x)  for(__typeof((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
#define rep(i, begin, end) for(int i = (begin), ed = (end); i < (ed); ++i)
#define per(i, end, begin) for(int i = (end)-1, bg = (begin); i >= (bg); --i)

#define setval(a, v)  for(int i = 0, sz = (sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))

#define all(a)        a.begin(), a.end()
#define min3(x, y, z) min(x,min(y,z))
#define max3(x, y, z) max(x,max(y,z))
#define INF           1000000007
#define debug         if( 0 )

#define mxn           100010


void solve(int tc)
{
    int n;
    string l, r;

    cin>>n;
    cin>>l>>r;

    vector<int> lind[26], rind[26];
    vector<int> lc, rc;

    rep(i, 0, n){
        if(l[i] != '?') lind[l[i]-'a'].push_back(i+1);
        else lc.push_back(i+1);
    }
    rep(i, 0, n){
        if(r[i] != '?') rind[r[i]-'a'].push_back(i+1);
        else rc.push_back(i+1);
    }

    vector< pair<int,int> > vec;

    rep(i, 0, 26){
        int v = min(lind[i].size(), rind[i].size());
        rep(j, 0, v){
            vec.push_back({lind[i][j], rind[i][j]});
        }
        if(lind[i].size() > rind[i].size()){
            rep(j, rind[i].size(), lind[i].size()){
                if(!rc.empty()){
                    vec.push_back({lind[i][j], *rc.rbegin()});
                    rc.pop_back();
                }
            }
        }
        else if(lind[i].size() < rind[i].size()){
            rep(j, lind[i].size(), rind[i].size()){
                if(!lc.empty()){
                    vec.push_back({*lc.rbegin(), rind[i][j]});
                    lc.pop_back();
                }
            }
        }
    }

    while(!rc.empty() and !lc.empty()){
        vec.push_back({*lc.rbegin(), *rc.rbegin()});
        lc.pop_back();
        rc.pop_back();
    }

    cout<<vec.size()<<endl;
    repit(it, vec){
        cout<<it->first<<sp<<it->second<<endl;
    }
}

int32_t main()
{
    //INPUT //OUTPUT

    solve(1);
    //int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

// int dx[]={1,0,-1,0}; int dy[]={0,1,0,-1}; //4 Direction
// int dx[]={1,1,0,-1,-1,-1,0,1}; int dy[]={0,1,1,1,0,-1,-1,-1}; //8 direction
// int dx[]={2,1,-1,-2,-2,-1,1,2}; int dy[]={1,2,2,1,-1,-2,-2,-1}; //Knight Direction
// int dx[]={2,1,-1,-2,-1,1}; int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction
