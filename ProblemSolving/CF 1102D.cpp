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



void solve(int tc)
{
    int n, zero, one, two, each, l;
    string str;

    cin>>n>>str;
    each = n/3;
    l = str.size();

    one = two = zero = 0;
    rep(i, 0, l){
        if(str[i]=='0') zero++;
        else if(str[i]=='1') one++;
        else two++;
    }

    zero -= each, one -= each, two -= each;

    if(zero>0){
        int n0 = 0;
        for(int i=0; i<l and zero; i++){
            if(str[i]=='0'){
                if(n0 < each) n0++;
                else if(one<0) str[i] = '1', one++, zero--;
                else if(two<0) str[i] = '2', two++, zero--;
            }
        }
    }
    if(one>0){
        int n1 = 0;
        for(int i=0; i<l and one; i++){
            if(str[i]=='1'){
                if(zero<0) str[i] = '0', zero++, one--;
                else if(two<0 and n1==each) str[i] = '2', two++, one--;
                else if(n1<each) n1++;
            }
        }
    }
    if(two>0){
        for(int i=0; i<l and two; i++){
            if(str[i]=='2'){
                if(zero<0) str[i] = '0', zero++, two--;
                else if(one<0) str[i] = '1', one++, two--;
            }
        }
    }

    cout<<str<<endl;
}

int32_t main()
{
    //INPUT
    //FastRead
    solve(1);
    //main();
    //int tc; sfi(tc); rep(t, 1, tc+1) solve(t);

    return 0;
}
