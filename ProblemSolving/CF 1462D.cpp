#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 1 )

const int mxn = 100010;



void solve(int test_case)
{
    int n;
    cin >> n;

    int arr[n], sum = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    int seg_sum, seg_tot;
    for(int i=0; i<=n; i++){
        if(sum % (n-i) != 0) continue;
        seg_sum = sum / (n-i);
        seg_tot = 0;
        bool flag = true;
        for(int j=0; j<n; j++){
            seg_tot += arr[j];
            if(seg_tot == seg_sum) seg_tot = 0;
            else if(seg_tot > seg_sum){
                flag = false;
                continue;
            }
        }
        if(flag){
            cout << i << endl;
            return;
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
