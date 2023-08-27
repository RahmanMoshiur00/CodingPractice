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
    int n, k;
    cin >> n >> k;

    if(n==1){
        cout << "R" << endl;
        return;
    }

    int possible = (n/2) + (n%2);
    if(k <= possible){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i%2==0 && i==j && k){
                    cout << 'R';
                    k--;
                }
                else{
                    cout << '.';
                }
            }
            cout << endl;
        }
    }
    else{
        cout<< -1 << endl;
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

