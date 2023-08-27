#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long int intl;
typedef unsigned long long intu;
typedef pair<intl, intl> pll;
typedef pair<int, int> pii;
typedef pair<intl, pair<intl,intl> > plll;
typedef pair<int, pair<int,int> > piii;
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
#define MP            make_pair
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
#define mxn           1000010



int main()
{
    //INPUT
    int t; cin>>t;
    string old, nw;

    while(t--){
        cin>>old>>nw;
        map<string, string> mp1, mp2;

        string key = "", val = "";
        for(int i=0; old[i]; i++){
            if(old[i]>='a' && old[i]<='z') key += old[i];
            else if(old[i]>='0' && old[i]<='9') val += old[i];

            if((old[i]==',' || old[i]=='}') && key!=""){
                mp1[key] = val;
                key = val = "";
            }
        }
        key = val = "";
        for(int i=0; nw[i]; i++){
            if(nw[i]>='a' && nw[i]<='z') key += nw[i];
            else if(nw[i]>='0' && nw[i]<='9') val += nw[i];

            if((nw[i]==',' || nw[i]=='}') && key!=""){
                mp2[key] = val;
                key = val = "";
            }
        }


        vector<string> added;
        for(auto it : mp2){
            if(mp1.find(it.ff) == mp1.end()) added.pb(it.ff);
        }
        if(added.size()){
            sort(all(added));
            for(int i=0; i<added.size(); i++){
                if(!i) cout<<"+";
                else cout<<",";
                cout<<added[i];
            } cout<<endl;
        }


        vector<string> dropped;
        for(auto it : mp1){
            if(mp2.find(it.ff) == mp2.end()) dropped.pb(it.ff);
        }
        if(dropped.size()){
            sort(all(dropped));
            for(int i=0; i<dropped.size(); i++){
                if(!i) cout<<"-";
                else cout<<",";
                cout<<dropped[i];
            } cout<<endl;
        }


        vector<string> changed;
        for(auto it : mp1){
            if(mp2.find(it.ff)!=mp2.end() && mp1[it.ff]!=mp2[it.ff]) changed.pb(it.ff);
        }
        if(changed.size()){
            sort(all(changed));
            for(int i=0; i<changed.size(); i++){
                if(!i) cout<<"*";
                else cout<<",";
                cout<<changed[i];
            } cout<<endl;
        }

        if(added.size() + dropped.size() + changed.size() == 0) cout<<"No changes"<<endl;

        cout<<endl;
    }


    return 0;
}

