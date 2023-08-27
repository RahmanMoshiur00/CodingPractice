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
#define debug         if( 1 )

const int mxn = 100010;

int cnt[10];

int find_best(int n)
{
    for(int i = n; i>=0; i--){
        if(cnt[i]){
            return i;
        }
    }
    return -1;
}

string best_string()
{
    string tmp;
    for(int i=9; i>=0; i--){
        while(cnt[i]){
            tmp += (i + '0');
            cnt[i]--;
        }
    }
    return tmp;
}

void solve(int tc)
{
    string f, s;
    cin>>f>>s;

    rep(i, 0, f.size()) cnt[f[i] - '0']++;

    if(f.size() < s.size()){
        sort(all(f), greater<char>());
        cout<<f<<endl;
    }
    else{
        int a;
        char ch;
        bool low = false;
        string res;

        rep(i, 0, f.size()){
            a = find_best(s[i] - '0');

            if(a == -1){
                while( find_best( *res.rbegin() - '0' - 1) == -1){
                    cnt[ *res.rbegin() - '0' ]++;
                    res.pop_back();
                }

                ch = *res.rbegin();
                cnt[ ch - '0' ]++;
                res.pop_back();

                ch = find_best(ch - '0' - 1) + '0';
                res += ch;
                cnt[ch - '0']--;
                res += best_string();

                cout<<res<<endl;
                return;
            }

            ch = a + '0';

            if(ch == s[i]){
                res += ch;
                cnt[ch - '0']--;
            }
            else if(ch < s[i]){
                res += ch;
                cnt[ch - '0']--;
                res += best_string();
                cout<<res<<endl;
                return;
            }
        }
        cout<<res<<endl;
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

