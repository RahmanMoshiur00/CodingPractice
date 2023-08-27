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
#define perit(it, x)  for(__typeof__((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
#define rep(i, begin, end) for(int i = (begin), ed = (end); i < (ed); ++i)
#define per(i, end, begin) for(int i = (end)-1, bg = (begin); i >= (bg); --i)

#define mem(a, v)     for(int i = 0, sz = (sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }
#define setmem(a, v)  memset((a), v, sizeof(a))

#define all(a)        a.begin(), a.end()
#define PB            push_back
#define MP            make_pair
#define min3(x, y, z) min(x,min(y,z))
#define max3(x, y, z) max(x,max(y,z))
#define ff            first
#define ss            second

#define PI            acos(-1.0)
#define ERR           0.000000001
#define INF           1000000007
#define mod           1000000007
#define debug         if( 1 )
#define mxn           1005

int cnt[mxn];
int res[mxn][mxn], n;

void put_ans_odd(int v){

    int idx = (n+1) / 2;

    rep(i, 1, n+1){
        rep(j, 1, n+1){
           // if(i==idx and j==idx) continue;

            if(j==idx and res[i][j]==-1){
                res[i][idx] = v;
                res[n-i+1][idx] = v;
                res[idx][i] = v;
                res[idx][n-i+1] = v;

                return;
            }
            if(res[i][j] == -1){
                res[i][j] = v;
                res[i][n-j+1] = v;

                res[n-i+1][j] = v;
                res[n-i+1][n-j+1] = v;

                return;
            }
        }
    }
}

void put_ans_even(int v){
    rep(i, 1, n+1){
        rep(j, 1, n+1){
            if(res[i][j] == -1){
                res[i][j] = v;
                res[i][n-j+1] = v;

                res[n-i+1][j] = v;
                res[n-i+1][n-j+1] = v;

                return;
            }
        }
    }
}


void solve(int tc)
{
    cin>>n;

    rep(i, 0, mxn) cnt[i] = 0;
    rep(i, 0, mxn) rep(j, 0, mxn) res[i][j] = -1;

    int val;
    rep(i, 0, n)
        rep(j, 0, n){
            cin>>val;
            cnt[val]++;
        }

    debug{
        cout<<"----------------"<<endl;
        rep(i, 0, mxn){
            if(cnt[i]) cout<<i<<sp<<cnt[i]<<endl;
        }
        cout<<"================"<<endl;
    }

    int freq;
    if(n%2){
        bool one = false;
        rep(i, 1, 1001){
            if(cnt[i]%4==0){
                freq = cnt[i]/4;
                while(freq--) put_ans_odd(i);
            }
            else if(cnt[i] > 0){
                if(cnt[i]%4==1 and !one){
                    one = true;
                    int v = (n+1)/2;
                    res[v][v] = i;
                    freq = cnt[i]/4;
                    while(freq--) put_ans_odd(i);
                }
                else{
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
    }
    else{
        rep(i, 1, 1001){
            if(cnt[i]%4==0){
                freq = cnt[i]/4;
                while(freq--) put_ans_even(i);
            }
            else{
                cout<<"NO"<<endl;
                return;
            }
        }
    }

    rep(i, 1, n+1){
        rep(j, 1, n+1){
            if(res[i][j]==-1){
                cout<<"NO"<<endl;
                return;
            }
        }
    }

    cout<<"YES"<<endl;
    rep(i, 1, n+1)
        rep(j, 1, n+1){
            if(j==n) cout<<res[i][j]<<endl;
            else cout<<res[i][j]<<sp;
        }
}

int32_t main()
{
    INPUT  //OUTPUT
    //FastRead

    solve(1);
    //int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

