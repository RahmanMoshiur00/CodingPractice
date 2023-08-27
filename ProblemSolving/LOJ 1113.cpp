#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
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
#define mxn           100010



int main()
{
    FasterIO

    int tc, cnt; sfi(tc);
    string cmd, link;
    vector<string> ar(110);
    for(int t=1; t<=tc; t++){
        printf("Case %d:\n", t);
        ar.clear();
        fill(all(ar), "");
        ar[0] = "http://www.lightoj.com/";
        cnt = 0;
        while(true){
            cin>>cmd;
            if(cmd=="QUIT") break;
            else if(cmd=="VISIT"){
                cin>>link;
                cout<<link<<endl;
                ar[++cnt] = link;
                for(int j=cnt+1; j<110; j++) ar[j] = "";
            }
            else if(cmd=="BACK"){
                --cnt;
                if(cnt<0) cnt = 0, cout<<"Ignored"<<endl;
                else cout<<ar[cnt]<<endl;
            }
            else if(cmd=="FORWARD"){
                cnt++;
                if(ar[cnt]=="") cnt--, cout<<"Ignored"<<endl;
                else cout<<ar[cnt]<<endl;
            }
        }

    }

    return 0;
}

