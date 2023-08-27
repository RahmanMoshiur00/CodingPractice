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
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfu(x)        scanf("%llu", &x)
#define pfi(x)        printf("%d\n", x)
#define pfl(x)        printf("%lld\n", x)
#define pfu(x)        printf("%llu\n", x)
#define endl          "\n"
#define sp            " "
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
#define INF           1000000000
#define mod           1000000007
#define mxn           10010

//DP: Edit Distance (library)


int mm[mxn][mxn], dp[mxn][mxn], modp[2][mxn]; //memo for recursive, bottom-up and memory-optimized bottom-up dp respectively
string str1, str2;
int L1, L2; //length of given strings

int editDistance(int l1, int l2){
    if(mm[l1][l2] != -1) return mm[l1][l2];

    if(l1>=L1 and l2>=L2) return dp[l1][l2] = 0;
    else if(l1>=L1) return dp[l1][l2] = L2 - l2;
    else if(l2>=L2) return dp[l1][l2] = L1 - l1;

    if(str1[l1]==str2[l2]) return dp[l1][l2] = editDistance(l1+1, l2+1);
    else{
        return dp[l1][l2] = 1 + min3(editDistance(l1+1, l2+1), editDistance(l1, l2+1), editDistance(l1+1, l2));
    }
}


int main()
{
    FasterIO

    cin>>str1>>str2;
    L1 = str1.size() , L2 = str2.size();

    //iterative solution
    for(int i=0; i<=L1; i++) dp[i][0] = i;
    for(int j=0; j<=L2; j++) dp[0][j] = j;
    for(int i=1; i<=L1; i++){
        for(int j=1; j<=L2; j++){
            if(str1[i-1]==str2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min3(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);
        }
    }
    cout<<"Bottom-up solution: "<<dp[L1][L2]<<endl;

    //memory-optimized bottom-up soltion [recommended]
    if(L1<L2){ //this is for O(2*min(l1,l2)) memory complexity
        swap(str1, str2);
        L1 = str1.size();
        L2 = str2.size();
    }
    for(int j=0; j<=L2; j++) modp[0][j] = j;
    for(int i=1; i<=L1; i++){
        for(int j=0; j<=L2; j++){
            if(j==0) modp[i%2][0] = i;
            else if(str1[i-1]==str2[j-1]) modp[i%2][j] = modp[(i-1)%2][j-1];
            else modp[i%2][j] = 1 + min3(modp[(i-1)%2][j-1], modp[i%2][j-1], modp[(i-1)%2][j]);
        }
    }
    cout<<"Memory optimized dp sol: "<<modp[L1%2][L2]<<endl;


    //recursive solution; it takes too long time inspite of memoizing! i think it takes O(n^3) time
    //mem(mm, -1);
    //cout<<"Recursive solution: "<<editDistance(0,0)<<endl;

    return 0;
}

