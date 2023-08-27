#include <bits/stdc++.h>
using namespace std;
typedef int    intt;
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
#define pfi(x)        printf("%d", (intt)x)
#define pfi2(x, y)    printf("%d %d", (intt)x, (intt)y)
#define pfi3(x, y, z) printf("%d %d %d", (intt)x, (intt)y, (intt)z)
#define pfl(x)        printf("%lld", (intl)x)
#define pfl2(x, y)    printf("%lld %lld", (intl)x, (intl)y)
#define pfl3(x, y, z) printf("%lld %lld %lld", (intl)x, (intl)y, (intl)z)
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
#define str            first
#define idx            second
#define all(a)        a.begin(),a.end()
#define endl          '\n'
#define sp            ' '
#define mem(a, v)     memset((a), v, sizeof(a))
#define min3(a, b, c) min(a,min(b,c))
#define max3(a, b, c) max(a,max(b,c))
#define CEIL(x, y)    ((x)%(y)==0 ? (x)/(y) : ((x)/(y))+1)
#define ABS(x)        ((x)<0?-(x):(x))
#define PI            acos(-1.0)
#define ERR           0.000000001
#define INF           1000000007
#define mod           1000000007
#define mxn           100010

typedef pair<string, int> si;

bool cmp(si x, si y)
{
    return (x.str.size() < y.str.size());
}

bool pre(string a, string b)
{
    rep(i, 0, b.size()){
        if(a[i] != b[i]) return false;
    }
    return true;
}

bool suf(string a, string b)
{
    int j = a.size();
    rep(i, b.size(), 0){
        if(a[--j] != b[i]) return false;
    }
    return true;
}

void solve(int tc)
{
    int n, m; cin>>m;

    n = (2*m) - 2;
    vector< si > p(n);

    rep(i, 0, n){
        cin>>p[i].str;
        p[i].idx = i;
    }

    sort(all(p), cmp);

    if(m==2){
        cout<<"PS"<<endl;
        return;
    }

    //cout<<"debug:"<<endl; rep(i, 0, n) cout<<p[i].str<<endl;

    string a, b, c, d;
    int ia, ib, ic, id;

    a = p[0].str; ia = p[0].idx;
    b = p[1].str; ib = p[1].idx;
    c = p[2].str; ic = p[2].idx;
    d = p[3].str; id = p[3].idx;

    //debug(a); debug(b); debug(c); debug(d);
    //debug(ia); debug(ib); debug(ic); debug(id);

    char ans[n+5];

    if(pre(c, a) and suf(d, b)){
        ans[ia] = 'P', ans[ib] = 'S', ans[ic] = 'P', ans[id] = 'S';
    }
    else if(pre(d, a) and suf(c, b)){
        ans[ia] = 'P', ans[ib] = 'S', ans[ic] = 'S', ans[id] = 'P';
    }
    else if(pre(c, b) and suf(d, a)){
        ans[ia] = 'S', ans[ib] = 'P', ans[ic] = 'P', ans[id] = 'S';
    }
    else if(pre(d, b) and suf(c, a)){
        ans[ia] = 'S', ans[ib] = 'P', ans[ic] = 'S', ans[id] = 'P';
    }

    //debugi(ans[ia], ia); debugi(ans[ib], ib); debugi(ans[ic], ic); debugi(ans[id], id);

    for(int i=4; i<n; i+=2){
        a = p[i-2].str; ia = p[i-2].idx;
        b = p[i-1].str; ib = p[i-1].idx;

        c = p[i].str;   ic = p[i].idx;
        d = p[i+1].str; id = p[i+1].idx;

        if(ans[ia] == 'P'){ //a is prefix
            if(pre(c, a) and suf(d, b)){
                ans[ic] = 'P', ans[id] = 'S';
            }
            else if(pre(d,a) and suf(c, b)) {
                ans[ic] = 'S', ans[id] = 'P';
            }
        }
        else{ //b is prefix
            if(pre(c, b) and suf(d, a)){
                ans[ic] = 'P', ans[id] = 'S';
            }
            else if(pre(d, b) and suf(c, a)){
                ans[ic] = 'S', ans[id] = 'P';
            }
        }
    }
    rep(i, 0, n) cout<<ans[i]; cout<<endl;
}

int32_t main()
{
    //INPUT
    solve(1);
    //int tc; sfl(tc); rep(t, 1, tc+1) solve(t);

    return 0;
}

