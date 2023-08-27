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

    int arr[n], tot = 0, one = 0, two = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        tot += arr[i];
        if(arr[i]==1) one++;
        else two++;
    }

    if(tot%2==0){
        if(n%2==0 || (n%2==1 && one>=2)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    else{
        cout << "NO" << endl;
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

