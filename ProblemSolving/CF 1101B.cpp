#include <bits/stdc++.h>
using namespace std;
typedef int intt;
typedef long long int intl;
typedef unsigned long long intu;
#define int           long long
#define sfi(x)        scanf("%lld", &x)
#define sfi2(x, y)    scanf("%lld %lld", &x, &y)
#define sfi3(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define pfi(x)        printf("%lld", (intl)x)
#define pfi2(x, y)    printf("%lld %lld", (intl)x, (intl)y)
#define pfi3(x, y, z) printf("%lld %lld %lld", (intl)x, (intl)y, (intl)z)
#define sfd(x)        scanf("%lf", &x)
#define sfd2(x, y)    scanf("%lf %lf", &x, &y)
#define sfd3(x, y, z) scanf("%lf %lf %lf", &x, &y, &z)
#define sfs(x)        scanf("%s", x)
#define sfsn(x)       scanf("%[^\n]s", x)
#define pfs(x)        printf("%s", x)
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
#define rep(i, begin, end) for (__typeof(end) i = (begin); i < (end); i += 1)
#define per(i, end, begin) for (__typeof(end) i = (end)-1; i >= (begin); i -= 1)
#define all(a)        a.begin(), a.end()
#define PB            push_back
#define MP            make_pair
#define mem(a, v)     memset((a), v, sizeof(a))
#define min3(a, b, c) min(a,min(b,c))
#define max3(a, b, c) max(a,max(b,c))
#define ff            first
#define ss            second
#define CEIL(x, y)    ((x)%(y)==0 ? (x)/(y) : ((x)/(y))+1)
#define ABS(x)        ((x)<0?-(x):(x))
#define SQ(x)         ((x)*(x))
#define PI            acos(-1.0)
#define ERR           0.000000001
#define INF           1000000007
#define mod           1000000007
#define debug         if( 1 )
#define mxn           100010

bool isAcc(string s)
{
    stack<char> st;
    int n = s.size();

    if(s.size()<4 or s[0]!='[' or s[s.size() - 1]!=']' or s[1]!=':' and s[s.size()-2]!=':') return false;

    rep(i, 2, n-2){
        if(s[i] != '|') return false;
    }

    return true;
}

void solve(int tc)
{
    string s, str;
    cin>>s;

    int n = s.size();
    rep(i, 0, n) if(!(s[i]>='a' and s[i]<='z')) str += s[i];

    if(isAcc(str)) cout<<str.size()<<endl;
    else{
        bool fb = false, sb = false, fc = false, sc = false;
        int l = -1, r = -1;

        rep(i, 0, n){
            if(s[i]=='[' and !fb) fb = true;
            else if(s[i]==':' and fb){
                l = i;
                break;
            }

        }
        if(l==-1){
            cout<<-1<<endl;
            return;
        }

        per(i, n, l+1){
            if(s[i]==']' and !sb){
                sb = true;
            }
            else if(s[i]==':' and sb){
                r = i;
                break;
            }
        }
        if(r==-1){
            cout<<-1<<endl;
            return;
        }

        int ans = 4;
        rep(i, l+1, r) if(s[i] == '|') ans++;
        cout<<ans<<endl;
    }
}

int32_t main()
{
    //INPUT
    //FastRead
    solve(1);
    //int tc; sfl(tc); rep(t, 1, tc+1) solve(t);

    return 0;
}


