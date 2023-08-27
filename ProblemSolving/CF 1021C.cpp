#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long intu;
typedef long long int intl;
#define int             long long
#define pfi(a)          printf("%lld", (intl)a)
#define pfin(a)         printf("%lld", (intl)a), printf("\n")
#define pfis(a)         printf("%lld", (intl)a), printf(" ")
#define pfc(a)          printf("%c", a)
#define pfs(a)          printf("%s", a)
#define pfsn(a)         printf("%s", a), printf("\n")
#define space           printf(" ")
#define newl            printf("\n")
#define endl            '\n'
#define sp              ' '

#define sfi(a)          scanf("%lld", &a)
#define sfi2(a,b)       sfi(a), sfi(b)
#define sfi3(a, b, c)   sfi(a), sfi(b), sfi(c)
#define sfc(a)          scanf(" %c", &a)
#define sfs(a)          scanf(" %s", a)
#define sfsn(a)         scanf(" %[^\n]s", a)
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define rep(i, begin, end) for(int i = (begin), ed = (end); i < (ed); ++i)
#define per(i, end, begin) for(int i = (end)-1, ed = (begin); i >= (ed); --i)
#define repit(it, x)  for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define perit(it, x)  for(__typeof__((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
#define watch(a)        cout<<":>>   "<< #a <<" : "<<a<<endl
#define watchi(a, i)    cout<<":>>   "<< #a <<"-> ["<<i<<"]"<<" : "<<a<<endl
#define FastRead        ios::sync_with_stdio(0); cin.tie(0);
#define INPUT           freopen("input.txt","r",stdin);
#define OUTPUT          freopen("output.txt","w",stdout);
#define all(a)          a.begin(), a.end()
#define MP              make_pair
#define PB              push_back
#define setmem(a, v)    memset((a), v, sizeof(a))
#define mem(a, v)       for(int i=0, sz=(sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }
#define max3(a, b, c)   max(a,max(b,c))
#define min3(a, b, c)   min(a,min(b,c))
#define ss              second
#define ff              first
#define PI              acos(-1.00)
#define ERR             1e-9
#define mod             1000000007
#define INF             1000000007
#define debug           if( 0 )
#define mxn             100010


void solve(int tc)
{
    int n, k;
    sfi2(n, k);

    int arr[n];
    int p = 0;

    stack<int> st[k];

    rep(i, 0, n){
        sfi(arr[i]);
    }

    k = min(k, n);

    int i=0;
    while(i<n){
        for(int j=0; i<n and j<k; j++)){
            if(st[j].empty()){
                st[j].push(arr[i]);
                i++;
            }
        }
    }
    rep(i, 0, n){


        rep(j, 0, k){
            if(!st.empty())
        }
    }
}

int32_t main()
{
    //INPUT  //OUTPUT
    //FastRead

    solve(1);
    //int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

