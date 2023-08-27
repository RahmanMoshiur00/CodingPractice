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
    int n;
    cin >> n;

    int arr[n+1];
    for(int i=1; i<=n; i++) cin >> arr[i];

    int j, k, idx;
    for(int i=1; i<=n; i++){
        if(arr[i] != i){
            for(j=i+1; j<=n; j++){
                if(arr[j]==i){
                    for(k=j; k>=i; k--){
                        cout << arr[k] << ' ';
                    }
                    for(k=j+1; k<=n; k++){
                        cout << arr[k] << ' ';
                    }
                    cout << endl;
                    return;
                }
            }
            i = j;
        }
        cout << arr[i] << ' ';
    }
    cout << endl;

}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

