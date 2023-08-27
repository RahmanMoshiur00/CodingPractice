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
#define debug         if( 0 )
#define mxn           100010

int dist(int x1, int y1, int x2, int y2)
{
    int x = (x1 - x2) * (x1 - x2);
    int y = (y1 - y2) * (y1 - y2);
    return (x+y);
}

int X(char ch)
{
    if(ch=='U' or ch=='D') return 0;
    if(ch == 'L') return -1;
    if(ch == 'R') return 1;
}

int Y(char ch)
{
    if(ch=='L' or ch=='R') return 0;
    if(ch=='U') return 1;
    if(ch=='D') return -1;
}

pair<int, int> val(char f, char s)
{
    if((f=='U' and s=='L') or (f=='L' and s=='U')){
        return {-1, +1};
    }
    if((f=='U' and s=='R') or (f=='R' and s=='U')){
        return {+1, +1};
    }
    if((f=='D' and s=='L') or (f=='L' and s=='D')){
        return {-1, -1};
    }
    if((f=='R' and s=='D') or (f=='D' and s=='R')){
        return {+1, -1};
    }
    if((f=='U' and s=='U') or (f=='U' and s=='U')){
        return {0, +2};
    }
    if((f=='D' and s=='D') or (f=='D' and s=='D')){
        return {0, -2};
    }
    if((f=='R' and s=='R') or (f=='R' and s=='R')){
        return {+2, 0};
    }
    if((f=='L' and s=='L') or (f=='L' and s=='L')){
        return {-2, 0};
    }
    if((f=='U' and s=='D') or (f=='D' and s=='U')){
        return {0, 0};
    }
    if((f=='L' and s=='R') or (f=='R' and s=='L')){
        return {0, 0};
    }
}

void solve(int tc)
{
    int x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;

    int sz; cin>>sz;
    string s; cin>>s;

    int ans = 0;
    while(true){
        int nx = x1, ny = y1;

        rep(i, 0, s.size()){
            ans++;

            int d1 = dist(x1, y1, x2, y2);
            int d2 = dist(x1+X(s[i]), y1+Y(s[i]), x2, y2);
            int d3 = dist(x1 + val(s[i], 'U').first, y1 + val(s[i], 'U').second, x2, y2);
            int d4 = dist(x1 + val(s[i], 'D').first, y1 + val(s[i], 'D').second, x2, y2);
            int d5 = dist(x1 + val(s[i], 'R').first, y1 + val(s[i], 'R').second, x2, y2);
            int d6 = dist(x1 + val(s[i], 'L').first, y1 + val(s[i], 'L').second, x2, y2);

            debug cout<<"check: "<<x1<<sp<<y1<<endl;
            debug cout<<"dist: "<<d1<<sp<<d2<<sp<<d3<<sp<<d4<<sp<<d5<<sp<<d6<<endl;

            int mx = min(min3(d1, d2, d3), min3(d4, d5, d6));

            if(mx == 0){
                cout<<ans<<endl;
                return;
            }
            else if(mx == d2){
                x1 = x1+X(s[i]), y1 = y1+Y(s[i]);
            }
            else if(mx == d3){
                x1 = x1 + val(s[i], 'U').first; y1 = y1 + val(s[i], 'U').second;
            }
            else if(mx == d4){
                x1 = x1 + val(s[i], 'D').first, y1 = y1 + val(s[i], 'D').second;
            }
            else if(mx == d5){
                x1 = x1 + val(s[i], 'R').first, y1 = y1 + val(s[i], 'R').second;
            }
            else if(mx == d6){
                x1 = x1 + val(s[i], 'L').first, y1 = y1 + val(s[i], 'L').second;
            }
        }
        if(nx == x1 and ny == y1){
            cout<<-1<<endl;
            return;
        }
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

