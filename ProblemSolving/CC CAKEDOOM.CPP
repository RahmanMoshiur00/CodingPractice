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
#define ERR           0.000000001
#define INF           1000000000
#define mod           1000000007
#define mxn           100000010

bool isGood(string s){
    int n = s.size();
    if(s[0]!='?' && s[0] == s[n-1]) return false;
    for(int i=1; i<n; i++)
        if(s[i]!='?' && (s[i]==s[i-1])) return false;
    return true;
}

int main()
{
    //INPUT

    int tc; cin>>tc;
    while(tc--){
        int k, n;
        string s;
        cin>>k>>s;

        n = s.size();

        if(n==1){
            if(s[0]=='?') cout<<'0'<<endl;
            else cout<<s<<endl;
            continue;
        }

        if(!isGood(s)) cout<<"NO"<<endl;
        else{
            if(k==1){
                if(n==1){
                    if(s[0]=='?') cout<<'0'<<endl;
                    else cout<<s<<endl;
                }
                else cout<<"NO"<<endl;
            }
            else if(k==2){
                if(n&1) cout<<"NO"<<endl;
                else{
                    string tmp1 = s, tmp2 = s;
                    for(int i=0; i<n; i++){
                        if(tmp1[i]=='?'){
                            if(i&1) tmp1[i] = '0';
                            else tmp1[i] = '1';
                        }
                    }
                    for(int i=0; i<n; i++){
                        if(tmp2[i]=='?'){
                            if(i&1) tmp2[i] = '1';
                            else tmp2[i] = '0';
                        }
                    }

                    bool check1 = isGood(tmp1), check2 = isGood(tmp2);
                    if(check1 && check2) cout<<min(tmp1, tmp2)<<endl;
                    else if(check1) cout<<tmp1<<endl;
                    else if(check2) cout<<tmp2<<endl;
                    else cout<<"NO"<<endl;
                }
            }
            else{
                for(int i=0; i<n; i++){
                    if(i==0 && s[i]=='?'){
                        for(int j=0; j<k; j++){
                            char ch = j + '0';
                            if(ch!=s[n-1] && ch!=s[i+1]){ s[i] = ch; break; }
                        }
                    }
                    else if(i==n-1 && s[i]=='?'){
                        for(int j=0; j<k; j++){
                            char ch = j + '0';
                            if(ch!=s[0] && ch!=s[i-1]){ s[i] = ch; break; }
                        }
                    }
                    else if(s[i]=='?'){
                        for(int j=0; j<k; j++){
                            char ch = j + '0';
                            if(ch!=s[i-1] && ch!=s[i+1]){ s[i] = ch; break; }
                        }
                    }
                }
                cout<<s<<endl;
            }
        }
    }


    return 0;
}

