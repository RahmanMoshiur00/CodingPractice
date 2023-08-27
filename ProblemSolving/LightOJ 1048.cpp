#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define repeach(it, x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(0); cin.tie(0);
#define debug(x)      cout<<" <<debug>> "<< #x <<": "<<x<<endl
#define debugi(x, i)  cout<<" <<debug>> "<< #x <<"["<<i<<"]"<<": "<<x<<endl
#define all(a)        a.begin(),a.end()
#define find(x, a)    x.find(a) != x.end()
#define endl          '\n'
#define sp            ' '
#define ff            first
#define ss            second
#define sf            second.first
#define sd            second.second
#define mem(a,v)      memset((a), v, sizeof(a))
#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define CEIL(x,y)     ((x)%(y)==0 ? (x)/(y) : ((x)/(y))+1)
#define ABS(x)        ((x)<0?-(x):(x))
#define PI            acos(-1.0)
#define ERR           0.000000001
#define INF           1000000007
#define mod           1000000007
#define mxn           1010

int d[mxn], n, k;

bool f(int x)
{
    int camps = 0, walk_in_a_day = 0;
    rep(i, 0, n){
        if(d[i]>x) return false;
        if(walk_in_a_day + d[i] > x){
            camps++;
            walk_in_a_day = d[i];
        }
        else walk_in_a_day += d[i];
    }

    return (camps <= k);
}

void print_solution(int x)
{
    int camps = 0, walk_in_a_day = 0, print_left = k+1;
    rep(i, 0, n){
        if(print_left <= n-i){ // if we have more elements left than the number of elements we need to print till now, we can maximize walking in a day
            if(walk_in_a_day + d[i] > x){
                cout<<walk_in_a_day<<endl;
                walk_in_a_day = d[i];
                print_left--;
            }
            else walk_in_a_day += d[i];
        }
        else{ // we have same number of camping and days of walking left; so we have to camp after each day walk
            cout<<walk_in_a_day<<endl;
            walk_in_a_day = d[i];
            print_left--;
        }
    }
    cout<<walk_in_a_day<<endl; //last day of walking
}

void solve(int tc)
{
    int sum = 0;
    cin>>n>>k;
    n++;

    rep(i, 0, n) cin>>d[i] , sum += d[i];

    int lo = 0, hi = sum, mid, ans = -1;
    while(lo<hi){
        mid = (hi+lo) / 2;
        if(f(mid)) ans = hi = mid;
        else lo = mid + 1;
    }

    cout<<"Case "<<tc<<": "<<ans<<endl;
    print_solution(ans);
}

int main()
{
    int tc; cin>>tc;

    rep(t, 1, tc+1) solve(t);

    return 0;
}


