#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 100010;



void solve(int test_case)
{
    int w, h;
    cin >> w >> h;

    int AB, BC, CD, AD, ABl, ABh, BCl, BCh, CDl, CDh, ADl, ADh;
    int k;

    cin >> k;
    int fi, la, v;
    for(int i=0; i<k; i++){
        cin >> v;
        if(i==0){
            fi = v;
        }
        else if(i == k-1){
            la = v;
        }
    }
    AB = la - fi;
    ABl = fi;
    ABh = la;

    cin >> k;
    for(int i=0; i<k; i++){
        cin >> v;
        if(i==0){
            fi = v;
        }
        else if(i==k-1){
            la = v;
        }
    }
    CD = la - fi;
    CDl = fi;
    CDh = la;

    cin >> k;
    for(int i=0; i<k; i++){
        cin >> v;
        if(i==0){
            fi = v;
        }
        else if(i==k-1){
            la = v;
        }
    }
    AD = la - fi;
    ADl = fi;
    ADh = la;

    cin >> k;
    for(int i=0; i<k; i++){
        cin >> v;
        if(i==0){
            fi = v;
        }
        else if(i==k-1){
            la = v;
        }
    }
    BC = la - fi;
    BCl = fi;
    BCh = la;


    int ans = 0;
    ans = max(ans, max(AB*BCh , BC*(w-ABl))); //AB+BC
    ans = max(ans, max(AB*h , CD*h)); //AB+CD
    ans = max(ans, max(AB*ADh , AD*ABh)); //AB+AD
    ans = max(ans, max(BC*(w-CDl), CD*(h-BCl))); //BC+CD
    ans = max(ans, max(BC*w , AD*w)); //BC+AD
    ans = max(ans, max(CD*(h-ADl) , AD*CDh)); //CD+AD

    cout << ans << endl;

}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

