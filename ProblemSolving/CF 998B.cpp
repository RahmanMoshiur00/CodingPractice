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
#define INOUT         freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define FasterIO      ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sfi(x)        scanf("%d", &x)
#define sfl(x)        scanf("%lld", &x)
#define sfu(x)        scanf("%llu", &x)
#define pfi(x)        printf("%d\n", x)
#define pfl(x)        printf("%lld\n", x)
#define pfu(x)        printf("%llu\n", x)
#define DBG(x)        cout<<">DBG> "<< #x <<" : "<<x<<endl
#define fr(i,a,b)     for(intl i=(a); i<=(b); i++)
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
#define INF           1000000000
#define mod           1000000007
#define mxn           100010



int main()
{
    FasterIO

    int n, k;
    cin>>n>>k;
    int ar[n+1];
    for(int i=0; i<n; i++) cin>>ar[i];

    vector<int> ans;

    int even = 0 , odd = 0, ev, od;
    for(int i=0; i+1<n; i++){
        if(ar[i]&1) odd++;
        else even++;
        od = ev = 0;
        for(int j=i+1; j<n; j++){
            if(ar[j]&1) od++;
            else ev++;
        }
        if((even==odd) && (ev==od)) ans.pb(ABS(ar[i]-ar[i+1]));
    }

    sort(all(ans));

    int sum = 0 , cnt = 0;
    for(int i=0; i<ans.size(); i++){
        if(sum+ans[i]>k) break;
        else sum += ans[i] , cnt++;
    }

    cout<<cnt<<endl;

    return 0;
}
