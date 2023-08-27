#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long int intl;
typedef unsigned long long intu;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //e.g. ordered_set<int> s; s.insert(3); cout<<s.ook(3)<<*s.fbo(3);
#define ook           order_of_key
#define fbo           find_by_order //returns pointer
#define all(a)        a.begin(),a.end()
#define Unique(a)     sort(all(a)),a.erase(unique(all(a)),a.end())
#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sfi(x)        scanf("%d", &x)
#define sfl(x)        scanf("%lld", &x)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfu(x)        scanf("%llu", &x)
#define pfi(x)        printf("%d\n", x)
#define pfl(x)        printf("%lld\n", x)
#define pfu(x)        printf("%llu\n", x)
#define endl          '\n'
#define sp            ' '
#define debug(x)      cout<<">debug> "<< #x <<" : "<<x<<endl
#define fr(i,a,b)     for(int i=(a); i<=(b); i++)
#define pb            push_back
#define mp            make_pair
#define ff            first
#define ss            second
#define sf            second.first
#define ssd           second.second
#define mem(a,v)      memset((a), v, sizeof(a))
#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define SQ(a)         ((a)*(a))
#define ABS(x)        ((x)<0?-(x):(x))
#define PI            acos(-1.0)
#define ERR           0.000000001
#define INF           1000000000
#define mod           1000000007
#define mxn           3010

int vote[mxn];
int cost[mxn];
int party[mxn];
int n, m;

bool ok(int v, int x){
    int check = false;
    int mx = INT_MIN;
    if(x)
    for(int i=2; i<mxn; i++){
        if(vote[i]>mx){
            mx = vote[i];
        }
    }
    return (v>mx);
}

intl solve(int i, int v){
    if(i==n) return INT_MAX;
    if(ok(v, i-1)) return 0;
    intl x, y;
    x = solve(i+1, v);
    y = cost[i]+solve(i+1, v+1);
    if(x<y){
        vote[party[i]]++;
        return x;
    }
    else{
        return y;
    }
}

int main()
{
    cin>>n>>m;

    vector< pair<int, int> > p(n);

    for(int i=0; i<n; i++){
        int p, c;
        cin>>p>>c;
        cost[i] = c;
        party[i] = p;
        vote[p]++;
    }

    if(ok(vote[1])){
        cout<<"0"<<endl;
        return 0;
    }

    cout<<solve(0, vote[1])<<endl;

    return 0;
}

