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
#define pfis(x)       printf("%lld", (intl)x), printf(" ")
#define pfin(x)       printf("%lld", (intl)x), printf("\n")
#define pfs(x)        printf("%s", x)
#define pfnl          printf("\n")
#define pfsp          printf(" ")
#define endl          '\n'
#define sp            ' '

#define watch(x)      cout<<"::debug::   "<< #x <<" : "<<x<<endl
#define watchi(i, x)  cout<<"::debug::   "<< #x <<"-> ["<<i<<"]"<<" : "<<x<<endl

#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(false), cin.tie(0);

#define FOR(i, begin, end)  for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define repit(it, x)        for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define perit(it, x)        for(__typeof((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
#define rep(i, begin, end)  for(int i = (begin), ed = (end); i < (ed); ++i)
#define per(i, end, begin)  for(int i = (end)-1, bg = (begin); i >= (bg); --i)

#define setvalue(a, v)  for(int i = 0, sz = (sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))

#define all(a)        a.begin(), a.end()
#define min3(x, y, z) min(x,min(y,z))
#define max3(x, y, z) max(x,max(y,z))
#define PI            2*acos(0)
#define INF           1000000007
#define debug         if( 1 )

const int mxn = 100010;

bool cmp(pair<int,string>& a, pair<int,string>& b){
    if(a.second.size() == b.second.size()){
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }
    return (a.second.size() < b.second.size());
}

bool ok(string s){
    bool bl[3] = {false, false, false};
    for(auto ch : s) bl[ch-'A'] = true;
    return (bl[0] && bl[1] && bl[2]);
}

void solve(int tc)
{
    int n; cin >> n;
    vector< pair<int,string> > v(n); // a, b, c, ab, bc, ac, abc

    for(int i=0; i<n; i++){
        cin >> v[i].first >> v[i].second;
        sort(all(v[i].second));
    }

    sort(all(v), cmp);

    vector< pair<int, string> > mp;
    mp.push_back({v[0].first, v[0].second});
    for(int i=1; i<n; i++){
        if(v[i].second != v[i-1].second) mp.push_back({v[i].first, v[i].second});
    }

    int ans = LLONG_MAX;
    if(mp.size() >= 3 && mp[0].second=="A" && mp[1].second=="B" && mp[2].second=="C"){
        ans = mp[0].first + mp[1].first + mp[2].first;
    }
    string tmp;
    for(int i=0; i<mp.size(); i++){
        if(ok(mp[i].second)) ans = min(ans, mp[i].first);
        for(int j=i+1; j<mp.size(); j++){
            tmp = mp[i].second + mp[j].second;
            if(ok(tmp)) ans = min(ans, mp[i].first + mp[j].first);
        }
    }

    if(ans == LLONG_MAX) ans = -1;
    cout << ans << endl;
}

int32_t main()
{
    //INPUT //OUTPUT
    //FastRead

    solve(1);
    //int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

