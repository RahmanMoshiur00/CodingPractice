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

    int arr[n], last_even = -1, last_odd = -1;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<n; i++){
        if(arr[i]%2==0){
            if(last_even == -1){
                last_even = arr[i];
            }
            else{
                if(arr[i]<last_even){
                    cout << "No" << endl;
                    return;
                }
                else{
                    last_even = arr[i];
                }
            }
        }
        else{
            if(last_odd == -1){
                last_odd = arr[i];
            }
            else{
                if(arr[i]<last_odd){
                    cout << "No" << endl;
                    return;
                }
                else{
                    last_odd = arr[i];
                }
            }
        }
    }
    cout << "Yes" << endl;

}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

