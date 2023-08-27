#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int intl;
typedef unsigned long long intu;
#define Unique(a)     sort(all(a)),a.erase(unique(all(a)),a.end())
#define INOUT         freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define FasterIO      ios_base::sync_with_stdio(false);cin.tie(NULL);
#define DBG(x)        cout<<">DBG> "<< #x <<" : "<<x<<endl;
#define fr(i,a,b)     for(intl i = (a) ; i <= (b) ; i++)
#define pb            push_back
#define mp            make_pair
#define ff            first
#define ss            second
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

#define sf(x)         scanf("%d", &x)
#define pf(x)         printf("%d\n", x)

int main()
{
    FasterIO

    int n,t;

    priority_queue<int> mx;
    priority_queue<int, vector<int>, greater<int> > mn; //min priority queue

    while(sf(n)!=EOF){
        if(n==0){
            printf("\n");
            mx = priority_queue <int>();
            mn = priority_queue<int, vector<int>, greater<int> >();
        }
        else if(n==-1){
            if(mx.size() == mn.size()){
                pf(mx.top()); mx.pop();
                mx.push(mn.top()); mn.pop();
            }
            else if(mx.size()>mn.size()){
                pf(mx.top()); mx.pop();
            }
        }
        else{
            if(mx.empty() && mn.empty()) mx.push(n);
            else if(mx.size()>0 && mn.size()==0){
                if(n>=mx.top()) mn.push(n);
                else{
                    mn.push(mx.top()); mx.pop();
                    mx.push(n);
                }
            }
            else if(mx.size()==mn.size()){
                if(n<=mn.top()) mx.push(n);
                else{
                    mx.push(mn.top()); mn.pop();
                    mn.push(n);
                }
            }
            else if(mx.size()>mn.size()){
                if(n<mx.top()){
                    mn.push(mx.top()); mx.pop();
                    mx.push(n);
                }
                else mn.push(n);
            }
        }
    }
    printf("\n");


    return 0;
}
