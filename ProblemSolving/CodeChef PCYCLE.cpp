#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds;
typedef long long int intl;
typedef unsigned long long intu;
typedef pair<intl,intl> pii;
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
#define mxn            1010

vector<int> adj[mxn];
int arr[mxn];
bool visited[mxn];

void BFS_print(int s){
    cout<<s;
    visited[s] = true;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        int sz = adj[u].size();
        for(int i=0; i<sz; i++){
            int v = adj[u][i];
            if(!visited[v]){
                cout<<' '<<v;
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout<<' '<<s<<endl;
}

void BFS(int s){
    //cout<<s;
    visited[s] = true;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        int sz = adj[u].size();
        for(int i=0; i<sz; i++){
            int v = adj[u][i];
            if(!visited[v]){
                //cout<<' '<<v;
                visited[v] = true;
                q.push(v);
            }
        }
    }
    //cout<<' '<<s<<endl;
}

int main()
{
    FasterIO
    while(false){}

    int n; cin>>n;


    for(int i=1; i<=n; i++){
        cin>>arr[i];
        adj[i].pb(arr[i]);
    }

    vector<int> roots;
    for(int i=1; i<=n; i++){
        if(!visited[i]){ roots.pb(i); BFS(i); }
    }

    mem(visited, false);
    cout<<roots.size()<<endl;
    for(int i=1; i<=n; i++){
        if(!visited[i])BFS_print(i);
    }

    return 0;
}

