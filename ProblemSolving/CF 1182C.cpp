#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define int           long long // change here

#define sfi(x)        scanf("%lld", &x) // change here
#define sfi2(x, y)    sfi(x) , sfi(y)
#define sfi3(x, y, z) sfi(x) , sfi(y) , sfi(z)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfsn(x)       scanf(" %[^\n]s", x)

#define pfi(x)        printf("%lld", (intl)x)
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

#define FOR(i, begin, end)  for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define repit(it, x)        for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define perit(it, x)        for(__typeof((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
#define rep(i, begin, end)  for(int i = (begin), ed = (end); i < (ed); ++i)
#define per(i, end, begin)  for(int i = (end)-1, bg = (begin); i >= (bg); --i)

#define setval(a, v)  for(int i = 0, sz = (sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))

#define all(a)        a.begin(), a.end()
#define min3(x, y, z) min(x,min(y,z))
#define max3(x, y, z) max(x,max(y,z))
#define PI            2*acos(0)
#define INF           1000000007
#define debug         if( 0 )

const int mxn = 100010;

vector< string > v[5][mxn];

int vowel_index(int ch)
{
    if(ch == 'a') return 0;
    if(ch == 'e') return 1;
    if(ch == 'i') return 2;
    if(ch == 'o') return 3;
    if(ch == 'u') return 4;
}

pair<int,int> process(string& s)
{
    int vw, cnt = 0;
    rep(i, 0, s.size()){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
            vw = vowel_index(s[i]);
            cnt++;
        }
    }
    return make_pair(vw, cnt);
}

struct result{
    string s[4];
    result(){}
    result(string a, string b, string c, string d){
        s[0] = a, s[1] = b, s[2] = c, s[3] = d;
    }
};

void solve(int tc)
{
    int n; sfi(n);
    string s;

    int mxln = 0;
    pair<int, int> p;
    rep(i, 0, n){
        cin>>s;
        p = process(s);
        mxln = max(mxln, p.second);
        v[p.first][p.second].push_back(s);
    }

    vector< pair<string,string> > sec, fir;
    vector< string > vlen[mxln + 5];
    int ed;

    rep(i, 0, 5){
        rep(j, 0, mxln+1){
            int sz = v[i][j].size(), k = 0;
            for( ; k+1<sz; k+=2){
                sec.push_back({v[i][j][k], v[i][j][k+1]});
            }
            if(sz & 1) vlen[j].push_back(v[i][j][k]);
        }
    }

    rep(i, 0, mxln+1){
        int sz = vlen[i].size(), k = 0;
        for( ; k+1<sz; k+=2){
            fir.push_back({vlen[i][k], vlen[i][k+1]});
        }
    }

    int sec_sz = sec.size(), fir_sz = fir.size();
    int sz = min(sec_sz, fir_sz);

    vector< result > res;
    rep(i, 0, sz){
        res.push_back({fir[i].first, sec[i].first, fir[i].second, sec[i].second});
    }

    if(sec_sz > sz){
        for(int i = sz; i+1 < sec_sz; i+=2){
            res.push_back({sec[i].first, sec[i+1].first, sec[i].second, sec[i+1].second});
        }
    }

    cout<<res.size()<<endl;
    rep(i, 0, res.size()){
        cout<<res[i].s[0]<<sp<<res[i].s[1]<<endl;
        cout<<res[i].s[2]<<sp<<res[i].s[3]<<endl;
    }
}

int32_t main()
{
    //INPUT //OUTPUT
    //FastRead

    solve(1);
    //int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

