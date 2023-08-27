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

bool cmp(string s1, string s2){
    if(s1.size()==s2.size()){
        return (s1<s2);
    }
    else return (s1.size()<s2.size());
}


int main()
{
    FasterIO

    int n; cin>>n;
    vector<string> str1(n), str2(n);

    for(int i=0; i<n; i++) cin>>str1[i];
    for(int i=0; i<n; i++) cin>>str2[i];

    sort(all(str1), cmp) , sort(all(str2), cmp);

    int ans = 0;
    bool ok;
    for(int i=0; i<n; i++){
        ok = false;
        for(int j=0; j<n; j++) if(str1[i]==str2[j]){ str2[j] = ""; ok = true; break; }
        if(!ok) ans++;
    }
    cout<<ans<<endl;

    return 0;
}
