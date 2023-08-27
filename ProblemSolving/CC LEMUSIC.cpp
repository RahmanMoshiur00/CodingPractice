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
#define FOREACH(it, x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define FOR(i,a,b)    for(intl i=(intl)(a);i<=(intl)(b);++i)
#define ROF(i,a,b)    for(intl i=(intl)(a);i>=(intl)(b);--i)
#define pb            push_back
#define ff            first
#define ss            second
#define sf            second.first
#define sd            second.second
#define mem(a,v)      memset((a), v, sizeof(a))
#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define SQ(a)         ((a)*(a))
#define ABS(x)        ((x)<0?-(x):(x))
#define PI            acos(-1.0)
#define ERR           0.000000001
#define INF           1000000000
#define mod           1000000007
#define mxn           100000010



int main()
{
    //INPUT
    int tc, n; sfi(tc);

    while(tc--){
        sfi(n);
        vector< pair<intl, intl> > v(n);
        map<intl, intl> mp; // mp[i] = j; means for band i, j is the shortest length song
        set<intl> st; //stores bands

        FOR(i, 0, n-1){
            sfl(v[i].ff) , sfl(v[i].ss);

            st.insert(v[i].ff);

            //storing the song with least time of every bands
            auto it = mp.find(v[i].ff);
            if(it != mp.end()){
                if(v[i].ss < it->ss) mp[v[i].ff] = v[i].ss;
            }
            else mp[v[i].ff] = v[i].ss;
        }


        vector< pair<intl, intl> >p; //stores all distinct bands with corresponding shortest length in ascending order of song length
        for(auto it : st) p.pb(make_pair(mp[it], it));
        sort(all(p));

        intl ans = 0LL, sz = p.size() * 1LL;
        for(int i=1; i<=sz; i++) ans += p[i-1].ff * (long long)i; //finding optimal result for sz distinct bands

        for(int i=0; i<n; i++){ //finding optimal result of n-sz bands
            if(v[i].ss == mp[v[i].ff]) mp[v[i].ff] = -1;
            else ans += v[i].ss * sz;
        }

        pfl(ans);
    }

    return 0;
}

