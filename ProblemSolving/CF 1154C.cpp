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
#define debug         if( 0 )

#define mxn           100010

string str = "RFFRCFC";

void solve(int tc)
{
    int F, R, C, f, r, c;
    sfi3(F, R, C);

    int cnt = min3(R/2, F/3, C/2);

    R -= cnt * 2;
    F -= cnt * 3;
    C -= cnt * 2;

    int days, mxday = 0;

    rep(i, 0, 7){
        days = 0;
        f = F, r = R, c = C;
        bool next = true;
        rep(j, i, 7){
            if(str[j]=='F'){
                f--;
                if(f>=0) days++;
                else{
                    next = false;
                    break;
                }
            }
            else if(str[j]=='R'){
                r--;
                if(r>=0) days++;
                else{
                    next = false;
                    break;
                }
            }
            else if(str[j]=='C'){
                c--;
                if(c>=0) days++;
                else{
                    next = false;
                    break;
                }
            }
        }
        if(next){
            rep(j, 0, i){
                if(str[j]=='F'){
                    f--;
                    if(f>=0) days++;
                    else{
                        next = false;
                        break;
                    }
                }
                else if(str[j]=='R'){
                    r--;
                    if(r>=0) days++;
                    else{
                        next = false;
                        break;
                    }
                }
                else if(str[j]=='C'){
                    c--;
                    if(c>=0) days++;
                    else{
                        next = false;
                        break;
                    }
                }
            }
        }

        mxday = max(mxday, days);
    }

    int ans = (cnt * 7) + mxday;
    pfin(ans);
}

int32_t main()
{
    //INPUT //OUTPUT

    solve(1);
    //int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

