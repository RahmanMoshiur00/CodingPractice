#include <bits/stdc++.h>
using namespace std;
typedef long long int intl; //
typedef unsigned long long intu; //
#define int             long long
#define sfi(a)          scanf("%lld", &a)
#define sfi2(a,b)       sfi(a), sfi(b)
#define sfi3(a, b, c)   sfi(a), sfi(b), sfi(c)
#define sfd(a)          scanf("%lf", &a)
#define sfd2(a,b)       scanf("%lf %lf", &a, &b)
#define sfd3(a, b, c)   scanf("%lf %lf %lf", &a, &b, &c)
#define sfc(a)          scanf(" %c", &a)
#define sfs(a)          scanf(" %s", a)
#define sfsn(a)         scanf(" %[^\n]s", a)
#define pfi(a)          printf("%lld", (intl)a)
#define pfc(a)          printf("%c", a)
#define pfs(a)          printf("%s", a)
#define space           printf(" ")
#define newl            printf("\n")
#define endl            '\n'
#define sp              ' '
#define INPUT           freopen("input.txt","r",stdin);
#define OUTPUT          freopen("output.txt","w",stdout);
#define FastRead        ios::sync_with_stdio(0); cin.tie(0);
#define watch(a)        cout<<":>>   "<< #a <<" : "<<a<<endl
#define watchi(a, i)    cout<<":>>   "<< #a <<"-> ["<<i<<"]"<<" : "<<a<<endl
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define repit(it, a)  for(__typeof__((a).begin()) it = (a).begin(); it != (a).end(); ++it)
#define rep(i, begin, end) for (__typeof(end) i = (begin); i < (end); i += 1)
#define per(i, end, begin) for (__typeof(end) i = (end)-1; i >= (begin); i -= 1)
#define all(a)          a.begin(), a.end()
#define PB              push_back
#define mem(a, v)       for(int i=0, sz=sizeof(a)/sizeof(*a); i<sz; i++){ a[i] = v; }
#define setval(a, v)    memset((a), v, sizeof(a))
#define min3(a, b, c)   min(a,min(b,c))
#define max3(a, b, c)   max(a,max(b,c))
#define ff              first
#define ss              second
#define CEIL(a, b)      ((a)%(b)==0 ? (a)/(b) : ((a)/(b))+1)
#define ABS(a)          ((a)<0?-(a):(a))
#define SQ(a)           ((a)*(a))
#define PI              acos(-1.00)
#define ERR             1e-9
#define INF             1000000007
#define mod             1000000007
#define debug           if( 1 )
#define mxn             100010

char other(char a, char b)
{
    char c = min(a, b);
    char d = max(a, b);

    if(c=='B'){
        if(d=='G') return 'R';
        else return 'G';
    }
    else if(c=='G'){
        if(d=='B') return 'R';
        else return 'B';
    }
    else{ // R
        if(d=='B') return 'G';
        else return 'B';
    }
}

void solve(int tc)
{
    int n; cin>>n;
    string s; cin>>s;

    if(n==1){
        cout<<0<<endl;
        cout<<s<<endl;
        return;
    }
    else if(n==2){
        if(s[0]==s[1]){
            cout<<1<<endl;
            if(s[0]=='R') cout<<'G'<<endl;
            else cout<<'R'<<endl;
        }
        else{
            cout<<0<<endl;
            cout<<s<<endl;
        }
        return;
    }

    int cnt = 0;
    rep(i, 1, n-3){
        if(s[i-1]!=s[i] and s[i+1]!=s[i]){
            //s[i] = s[i];
            continue;
        }
        else{
            s[i] = other(s[i-1], s[i+1]);
            cnt++;
        }
    }

    int j = n-2, i = n-3, k = n-1;

    if(s[j]!=s[i] and s[j]!=s[k]){
        //str += s[i];
    }
    else{
        int ch = s[n-2];
        if(ch==s[n-1] and ch==s[n-3]){
            if(ch == 'R') s[j] = 'G';
            else s[j] = 'R';
        }
        else{
            s[j] = other(s[i], s[k]);
        }
        cnt++;
    }


    cout<<cnt<<endl;
    cout<<s<<endl;
}

int32_t main()
{
    //INPUT
    //FastRead

    solve(1);
    //int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

