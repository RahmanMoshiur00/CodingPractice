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
#define endl          "\n"
#define sp            " "
#define sfi(x)        scanf("%d", &x)
#define sfl(x)        scanf("%lld", &x)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfu(x)        scanf("%llu", &x)
#define pfi(x)        printf("%d\n", x)
#define pfl(x)        printf("%lld\n", x)
#define pfu(x)        printf("%llu\n", x)
#define debug(x)      cout<<">debug> "<< #x <<" : "<<x<<endl
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
#define mxn           1010

int R, C, sr, sc, er, ec; //row, colum of the grid; sr,sc=start row, col and er,ec=end(destination) row,col
int dp[mxn][mxn], cost[mxn][mxn];


int solve(int i, int j){
    if(i==sr && j==sc) //reached the start node; cost to reach a node from itself is the cost assigned to it
        return dp[i][j] = cost[i][j];
    if(!((i>=sr && i<=er) && (j>=sc && j<=ec))) //out of required grid area or out of the grid
        return INT_MAX;
    if(dp[i][j]==-1)
        dp[i][j] = cost[i][j] + min(solve(i, j-1), solve(i-1, j)); //grid[i][j] can be reached from grid[i][j-1] and grid[i-1][j]
    return dp[i][j];
}


int check(int i, int j){ //this function belongs to iterative solution
    if(i==sr && j==sc) //reached the start node; cost to reach a node from itself is the cost assigned to it
        return dp[i][j] = cost[i][j];
    if(!((i>=sr && i<=er) && (j>=sc && j<=ec))) //out of required grid area or out of the grid
        return INF;
    return dp[i][j];
}

int main()
{
    cin>>R>>C;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++) cin>>cost[i][j];
    }

    cin>>sr>>sc>>er>>ec; //if problem asks to go from (1,1) to cell (n,m) by default: set sr=sc=1 and er=n, ec=m

    //recursive
    mem(dp, -1);
    cout<<"OUTPUT(recursive): "<<solve(er,ec)<<endl;


    //iterative
    for(int i=sr; i<=er; i++){
        for(int j=sc; j<=ec; j++){
            dp[i][j] = cost[i][j] + min(check(i,j-1), check(i-1, j));
        }
    }
    cout<<"OUTPUT(iterative): "<<dp[er][ec]<<endl;

    return 0;
}

