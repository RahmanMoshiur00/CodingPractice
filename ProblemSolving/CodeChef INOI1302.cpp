#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds;
typedef long long int intl;
typedef unsigned long long intu;
typedef tree< intl, null_type, less<intl>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define Unique(a)     sort(all(a)),a.erase(unique(all(a)),a.end())
#define INOUT         freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define FasterIO      ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fr(i,a,b)     for(intl i = (a) ; i <= (b) ; i++)
#define sf            scanf
#define pf            printf
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
#define INF           1000000000LL //1e9
#define mod           1000000007LL
#define mxn           100000001      //1e6

typedef vector<int> vi;
int N, K;
vector< vi > v;
map<int, bool> maps;

void map_store(){
    int res = 0 , sz = 0;
    for(int i=1; i<N; i++){
        res = 0; sz = v[i].size();
        for(int j=0; j<sz; j++){
            if(maps.find(v[i][j]) != maps.end()) res++;
        }
        if(res>=K){
            for(int j=0; j<sz; j++) maps[ v[i][j] ] = true;
        }
    }
}

int result(){
    int res = 0, ans = 0, sz = 0;
    for(int i=N-1; i>=1; i--){ //for(i=1 to N-1) will cost WA;
        //because 2nd person may not family of president but family of N th person;
        //which means that 2nd person is family of President also
        res = 0; sz = v[i].size();
        for(int j=0; j<sz; j++){
            if(maps.find(v[i][j]) != maps.end()) res++;
        }
        if(res>=K){
            for(int j=0; j<sz; j++) maps[ v[i][j] ] = true;
            ans++;
        }
    }
    return ans+1;
}

int main()
{
    FasterIO

    cin>>N>>K;

    v.resize(N);
    int n, m;


    cin>>n;
    for(int j=0; j<n; j++){
        cin>>m;
        maps[m] = true;
        v[0].pb(m);
    }

    for(int i=1; i<N; i++){
        cin>>n;
        for(int j=0; j<n; j++){ cin>>m; v[i].pb(m); }
    }

    map_store();
    cout<<result()<<endl;

    return 0;
}

