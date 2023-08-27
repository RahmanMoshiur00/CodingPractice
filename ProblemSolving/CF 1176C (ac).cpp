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
#define debug         if( 0 )

const int mxn = 100010;



void solve(int tc)
{
    int n, m; cin >> n;

    deque<int> v[6];
    for(int i=0; i<n; i++){
        cin >> m;
        if(m == 4) v[0].push_back(i);
        else if(m == 8) v[1].push_back(i);
        else if(m == 15) v[2].push_back(i);
        else if(m == 16) v[3].push_back(i);
        else if(m == 23) v[4].push_back(i);
        else v[5].push_back(i);
    }

    int cnt = 0;
    while(true){
        bool brk = false;
        for(int i=0; i<6; i++){
            if(v[i].empty()){
                brk = true;
                break;
            }
        }
        if(brk) break;

        bool ok = true;
        int prv = v[0][0];
        v[0].pop_front();
        for(int i=1; i<6; i++){
            if(prv < v[i][0]){
                prv = v[i][0];
                v[i].pop_front();
            }
            else{
                while(!v[i].empty() && v[i][0]<prv) v[i].pop_front();
                if(v[i].empty()){
                    ok = false;
                    break;
                }
                prv = v[i][0];
                v[i].pop_front();
            }
        }
        if(ok) cnt++;
    }

    cout << n - (cnt * 6) << endl;
}

int32_t main()
{
    //INPUT //OUTPUT
    FastRead

    solve(1);
    //int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

