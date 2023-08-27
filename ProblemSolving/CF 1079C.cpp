#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define all(a)        a.begin(),a.end()
#define Unique(a)     sort(all(a)),a.erase(unique(all(a)),a.end())
#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sfi(x)        scanf("%d", &x)
#define sfl(x)        scanf("%lld", &x)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfu(x)        scanf("%llu", &x)
#define pfi(x)        printf("%d\n", x)
#define pfl(x)        printf("%lld\n", x)
#define pfu(x)        printf("%llu\n", x)
#define endl          "\n"
#define sp            " "
#define debug(x)      cout<<" <<debug>> "<< #x <<": "<<x<<endl
#define debugi(i, x)  cout<<" <<debug>> "<< #x <<"["<<i<<"]"<<": "<<x<<endl
#define repeach(it, x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pb            push_back
#define MP            make_pair
#define ff            first
#define ss            second
#define sf            second.first
#define sd            second.second
#define mem(a,v)      memset((a), v, sizeof(a))
#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define SQ(a)         ((a)*(a))
#define ABS(x)        ((x)<0?-(x):(x))
#define PI            acos(-1.0)
#define ERR           0.000000001
#define INF           1073741820
#define mod           1000000007
#define mxn           100010

int a[mxn];

bool isSame(int i){
    int v = a[i];
    for(int j=i+1; j<i+5; j++){
        if(a[j] != v) return false;
    }
    return true;
}

bool isIncreasing(int i){
    int v = a[i];
    for(int j=i+1; j<i+5; j++){
        if(a[j] <= v) return false;
        v = a[j];
    }
    return true;
}

bool isDecreasing(int i){
    int v = a[i];
    for(int j=i+1; j<i+5; j++){
        if(a[j] >= v) return false;
        v = a[j];
    }
    return true;
}

void print(int i){


    for(int j=i+1; j<i+5; j++){
        if(a[i]<=a[i+1]) v--;
        else v++;
    }
}

int main()
{
    FastRead;

    int n; cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];

    for(int i=2; i<=n-1; i++){
        if(a[i-1]<=a[i] and a[i]<=a[i+1]) v++ , res.pb(v);
        else if(a[i-1]>=a[i] and a[i]<=a[i+1]) v = 1 , res.pb(v);
        else if(a[i-1]>=a[i] and a[i]>=a[i+1]) v-- , res.pb(v);
        else if(a[i-1]<=a[i] and a[i]>=a[i+1]) v = 5 , res.pb(v);
        if(v<1 or v>5){
            cout<<-1<<endl;
            return 0;
        }
    }
    for(int i=0; i<n; i++) cout<<res[i]<<sp;

    return 0;
}


