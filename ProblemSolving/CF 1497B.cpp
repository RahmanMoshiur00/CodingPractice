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
    int n, m;
    cin >> n >> m;

    int arr[n], rem[m] = {0};
    for(int i=0; i<n; i++){
        cin >> arr[i];
        rem[arr[i]%m]++;
    }

    int ans = 0;
    for(int i=0; 2*i<m; i++){
        if(i==0){
            if(rem[0]!=0) ans++;
        }
        else{
            if(rem[i]>0 or rem[m-i]>0) ans++;
            if(abs(rem[i]-rem[m-i]) > 1) ans += abs(rem[i]-rem[m-i]) - 1;
        }
    }
    if(m%2==0 && rem[m/2]!=0) ans++;

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

