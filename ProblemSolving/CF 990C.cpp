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
#define sfi(x)        scanf("%d", &x)
#define sfl(x)        scanf("%lld", &x)
#define sfu(x)        scanf("%llu", &x)
#define pfi(x)        printf("%d\n", x)
#define pfl(x)        printf("%lld\n", x)
#define pfu(x)        printf("%llu\n", x)
#define DBG(x)        cout<<">DBG> "<< #x <<" : "<<x<<endl;
#define fr(i,a,b)     for(intl i = (a) ; i <= (b) ; i++)
#define pb            push_back
#define mp            make_pair
#define ff            first
#define ss            second
#define sf            second.first
#define ssd           second.second
#define ook           order_of_key
#define fbo           find_by_order
#define all(a)        a.begin(),a.end()
#define mem(a,v)      memset((a), v, sizeof(a))
#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define SQ(a)         ((a)*(a))
#define ABS(x)        ((x)<0?-(x):(x))
#define PI            acos(-1.0)
#define INF           1000000000
#define mod           1000000007
#define mxn           300010

bool OK(string& str){
    stack<char> st;
    int sz = str.length();
    st.push(str[0]);
    for(int i=1; i<sz; i++){
        if(!st.empty() && str[i]==')' && st.top()=='(') st.pop();
        else st.push(str[i]);
    }

}

int main()
{
    FasterIO

    int n; cin>>n;
    string tmp;
    vector<string> str(n);
    intu m=0LL, counter = 0LL;
    for(int i=0; i<n; i++) cin>>str[i];

    bool ok[n]; fill(ok, ok+n, false);

    for(int i=0; i<n; i++){
        if(OK(str[i])){ ok[i]=true; m++; continue; }
        for(int j=0; j<n; j++){
            if(ok[j]==true) continue;
            tmp = str[i] + str[j];
            if(OK(tmp)) counter++;
        }
    }

    cout<<(m*m)+counter<<endl;

    return 0;
}
