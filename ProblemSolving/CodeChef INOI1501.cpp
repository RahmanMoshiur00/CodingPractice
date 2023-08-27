#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int intl;
typedef unsigned long long intu;
typedef tree< intl, null_type, less<intl>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define Unique(a)     sort(all(a)),a.erase(unique(all(a)),a.end())
#define INOUT         freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define FasterIO      ios_base::sync_with_stdio(false);cin.tie(NULL);
#define DBG(x)        cout<<">DBG> "<< #x <<" : "<<x<<endl;
#define fr(i,a,b)     for(intl i = (a) ; i <= (b) ; i++)
#define pb            push_back
#define mp            make_pair
#define ff            first
#define ss            second
#define ook           order_of_key
#define fbo           find_by_order
#define all(a)        a.begin(),a.end()
#define mem(a,v)      memset((a), v, sizeof(a))
#define SQ(a)         ((a)*(a))
#define ABS(x)        ((x)<0?-(x):(x))
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

    int n; cin>>n;
    intl a[n+1], b[n+1], p, cal, ans = LONG_LONG_MIN;

    for(int i=1; i<=n; i++) cin>>a[i];
    b[0] = 0LL;
    for(int i=1; i<=n; i++) cin>>p , b[i]=b[i-1]+p; //storing cumulative sum of sequence b[] in b[]

    intl dpf[n+1], dpb[n+1];

    dpf[1] = a[1] - b[1];
    dpb[1] = a[1];
    for(int i=2; i<=n; i++) dpf[i] = max(dpf[i-1], a[i]-b[i]) , dpb[i] = max(dpb[i-1], a[i]+b[i-1]);

    ans = a[1];
    for(int j=2; j<=n; j++) ans = max(ans, max3(a[j], dpf[j-1]+a[j]+b[j-1], dpb[j-1]+a[j]+b[n]-b[j])); //taking max of three possible cases
    /*
    For any pair i , j; we have three choices-> (i=j) , (i<j) , (i>j)
    This checking can be done by checking all possible pairs in brute force in O(n^2):
        for (i=j)=a[i] , (i<j)=a[i]+a[j]+b[j-1]-b[i] and (i>j)=a[i]+a[j]+b[j-1]+b[n]-b[i]

    We can check all three pairs{(i=j) , (i<j) , (i>j)} at a time considering j as fixed position in the formulas we built for O(n^2) solution:
        if we assume (i=j)=a[i] , (i<j)=a[i]+a[j]+b[j-1]-b[i] and (i>j)=a[j]+a[i]+b[i-1]+b[n]-b[j]
            as you noticed for (i>j) pair, indices interchanged among i and j. why? because we take j as greater index and fixed, now we are finding maximum value for any index i less than j with rounding j to n and 0 to i
    */

    cout<<ans<<endl;

/*
O(n^2) solution::
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if(i==j) cal = a[i];
            else if(i<j) cal = a[i] + a[j] + b[j-1] - b[i];
            else         cal = a[i] + a[j] + b[j-1] + b[n] - b[i];   when i & j interchanged, this formula becomes: a[i] + b[i-1] + a[j] + b[n] - b[j]
            if(ans<cal) ans = cal;
        }
    }
    cout<<ans<<endl;
*/
    return 0;
}
