#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 100010;


void demo()
{
    int n;
    cin >> n;

    for(int i=2; i<=n; i+=2){
        for(int j=2; j<=i+1; j++){
            if(i%j!=0){
                cout << "f(" << i << ") = " << j << endl;
                break;
            }
        }
    }
}

void solve(int test_case)
{

}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    demo();

    //solve(1);
    //int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

