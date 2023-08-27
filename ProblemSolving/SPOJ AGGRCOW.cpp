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

bool ok(int a[], int n, int c, int x){

    int cows = 1 , current = 0; //first cow is placed in the left most stall
    for(int i=1; i<n; i++){
        if(current + a[i] - a[i-1] <= x) current += a[i] - a[i-1];
        else cows++, current = 0; //assigning another cow in the stalls
    }
    return (cows>=c); //returns if cows needed for x is greater than or equal to c or not
}

int main()
{
    FasterIO

    int t, n, c , lo, mid, hi;
    cin>>t;

    while(t--){
        cin>>n>>c;

        int a[n];

        for(int i=0; i<n; i++) cin>>a[i];
        sort(a, a+n);

        lo = 0; //minimum distance between two cows can be at least 0
        hi = a[n-1] - a[0]; //maximum difference between two cows can be at most the difference between first and last stall where cows are placed

        while(lo<hi){
            mid = (hi+lo+1)/2;
            if(ok(a, n, c, mid)) lo = mid; //if number of cows for x is greater than or equal to c, then we have to increase the lower bound. because X is inversly propotional to C and we are finding maximum X
            else hi = mid-1; //as cows for x is less then c, reducing the higher bound
        }

        cout<<lo+1<<endl;
    }

    return 0;
}
