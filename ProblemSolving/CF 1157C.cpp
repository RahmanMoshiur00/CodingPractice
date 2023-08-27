#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define int           long long

#define sfi(x)        scanf("%lld", &x)
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
#define debug         if( 1 )

#define mxn           200010

int n;
int arr[mxn];

pair<int, int> finder(int l, int r)
{
    int x = arr[l], y = arr[r];
    int cntx = 1, cnty = 1;
    rep(i, l+1, r+1){
        if(arr[i] > arr[i-1]) cntx++;
        else break;
    }

    for(int i=r-1; i>=l; i--){
        if(arr[i] > arr[i+1]) cnty++;
        else break;
    }

    if(cntx > cnty) return make_pair(-1, l+cntx-1);
    else return make_pair(1, r-cnty+1);

}

void solve(int tc)
{
    sfi(n);
    int l = 0, r = n-1;

    rep(i, 0, n) sfi(arr[i]);

    vector<int> ans;
    vector<char> res;

    while(l <= r){
        int mn = min(arr[l], arr[r]);
        int mx = max(arr[l], arr[r]);

        if(!ans.empty() && (mx <= *ans.rbegin())) break;
        if(l==r){
            if(ans.empty() or (*ans.rbegin() < arr[l])){
                res.push_back('L');
            }
            break;
        }

        if(arr[l] == arr[r]){
            pair<int,int> p = finder(l, r);
            int mv = p.first, idx = p.second;

            if(mv == -1){
                rep(i, l, idx+1){
                    ans.push_back(arr[i]);
                    res.push_back('L');
                }
                l = idx+1;
            }
            else{
                per(i, r+1, idx){
                    ans.push_back(arr[i]);
                    res.push_back('R');
                }
                r = idx-1;
            }

            continue;
        }

        if(ans.empty()){
            if(arr[l] < arr[r]){
                ans.push_back(arr[l]);
                res.push_back('L');
                l++;
            }
            else{
                ans.push_back(arr[r]);
                res.push_back('R');
                r--;
            }
        }
        else{
            if(mn > *ans.rbegin()){
                if(arr[l] < arr[r]){
                    ans.push_back(arr[l]);
                    res.push_back('L');
                    l++;
                }
                else{
                    ans.push_back(arr[r]);
                    res.push_back('R');
                    r--;
                }
            }
            else if(mx > *ans.rbegin()){
                if(arr[l] > arr[r]){
                    ans.push_back(arr[l]);
                    res.push_back('L');
                    l++;
                }
                else{
                    ans.push_back(arr[r]);
                    res.push_back('R');
                    r--;
                }
            }
            else break;
        }
    }

    pfin(res.size());

    rep(i, 0, res.size()) cout<<res[i];

}

int32_t main()
{
    solve(1);

    return 0;
}

