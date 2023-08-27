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
    int n, x, y;
    cin >> n >> x >> y;

    if(x > y) swap(x, y);

    int diff = y - x, tot ;

    for(int i=1; i<=diff; i++){
        if(diff%i == 0){
            tot = (diff / i) + 1;
            if(tot > n) continue;
            tot = y / i;
            if(y%i != 0) tot++;

            int val = y;
            while(n>0 && val>0){
                cout << val << ' ';
                n--, val -= i;
            }
            val = y + i;
            while(n>0){
                cout << val << ' ';
                n--, val += i;
            }
            cout << endl;
        }
    }
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

