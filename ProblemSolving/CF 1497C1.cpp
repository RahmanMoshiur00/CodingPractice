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
    int n, k, m;
    cin >> n >> k;


    if(n%2==1){
        cout << 1 << ' ' << (n-1)/2 << ' ' << (n-1)/2 << endl;
    }
    else if(n%3==0){
        cout << n/3 << ' ' << n/3 << ' ' << n/3 << endl;
    }
    else{
        for(int i=2; i<=n; i*=2){
            if(i==n){
                cout << n/4 << ' ' << n/4 << ' ' << n/2 << endl;
                break;
            }
            m = (n-i)/2;
            if(m%2==0 && m%i==0 && (m+m+i)==n){
                cout << i << ' ' << m << ' ' << m << endl;
                break;
            }
        }
//        if(m%2==0) cout << m << ' ' << m << endl;
//        else cout << m-1 << ' ' << m+1 << endl;
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

