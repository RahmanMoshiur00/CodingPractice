#include <bits/stdc++.h>
using namespace std;
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
    int tc, n, m, x; cin>>tc;
    string cmd;

    for(int t=1; t<=tc; t++){
        cin>>n>>m;
        deque<int> dq;
        cout<<"Case "<<t<<":"<<endl;
        for(int i=0; i<m; i++){
            cin>>cmd;
            if(cmd[1] == 'u'){
                cin>>x;
                if(dq.size()<n){
                    if(cmd == "pushLeft"){
                        cout<<"Pushed in left: "<<x<<endl;
                        dq.push_front(x);
                    }
                    else{
                        cout<<"Pushed in right: "<<x<<endl;
                        dq.push_back(x);
                    }
                }
                else cout<<"The queue is full"<<endl;
            }
            else{
                if(dq.empty()) cout<<"The queue is empty"<<endl;
                else{
                    if(cmd == "popLeft"){
                        x = dq[0];
                        cout<<"Popped from left: "<<x<<endl;
                        dq.pop_front();
                    }
                    else{
                        x = dq[dq.size()-1];
                        cout<<"Popped from right: "<<x<<endl;
                        dq.pop_back();
                    }
                }
            }
        }
    }

    return 0;
}
