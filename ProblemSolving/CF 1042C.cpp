#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
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
    intl n, m; cin>>n;

    vector<intl> zero;
    priority_queue< pair<intl, intl> > pos, neg;
    for(intl i=1; i<=n; i++){
        cin>>m;
        if(m==0){
            zero.pb(i);
        }
        else if(m>0){
            pos.push(MP(m, i));
        }
        else neg.push(MP(m, i));
    }

    intl print = 1;

    bool nega = false;
    if(neg.size() % 2 == 1){
            cout<<2<<sp<<neg.top().ss<<endl;
            neg.pop();
            print++;
            nega = true;
    }
    if(!zero.empty()){
        if(zero.size() == 1 && !nega) cout<<2<<sp<<zero[0]<<endl , print++;
        else if(zero.size() > 1){
            for(int i=0; i<zero.size()-1; i++){
                cout<<1<<sp<<zero[i]<<sp<<zero[i+1]<<endl;
                print++;
            }
            if(!pos.empty() && !nega) cout<<2<<sp<<zero[zero.size()-1]<<endl, print++;
            else pos.push({0, zero[zero.size()-1]});
        }
    }


    int i = 0;
    while(print<=n-1){
        if(!pos.empty() && !neg.empty()){
            cout<<1<<sp<<pos.top().ss<<sp<<neg.top().ss<<endl;
            intl v = pos.top().ff * neg.top().ff;
            i = neg.top().ss;
            pos.pop();
            neg.pop();
            neg.push(MP(v, i));
        }
        else if(!pos.empty()){
            cout<<1<<sp<<pos.top().ss<<sp;
            intl v = pos.top().ff;

            pos.pop();
            i = pos.top().ss;
            cout<<pos.top().ss<<endl;
            v *= pos.top().ff; pos.pop();
            pos.push(MP(v, i));
        }
        else if(!neg.empty()){
            cout<<1<<sp<<neg.top().ss<<sp;
            intl v = neg.top().ff;

            neg.pop();
            v *= neg.top().ff;
            i = neg.top().ss;
            cout<<neg.top().ss<<endl;
            neg.pop();
            pos.push(MP(v, i));
        }
        print++;
    }

    return 0;
}

