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
    int arr[n][3];

    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++) cin >> arr[i][j];
    }

    int l = 1e10+5, lmn = 1e10+5, li = -1, r = -1, rmn = 1e10+5, ri = -1, ans = 0;
    for(int i=0; i<n; i++){
        if(arr[i][0]<l){
            l = arr[i][0];
            lmn = arr[i][2];
            li = i;
        }
        else if(arr[i][0]==l){
            if(lmn>=arr[i][2]){
                lmn = arr[i][2];
                li = i;
            }
        }
        if(arr[i][1]>r){
            r = arr[i][1];
            rmn = arr[i][2];
            ri = i;
        }
        else if(arr[i][1]==r){
            if(rmn >= arr[i][2]){
                rmn = arr[i][2];
                ri = i;
            }
        }

        if(li == ri){
            cout << arr[li][2] << endl;
        }
        else if(arr[li][0]==arr[ri][0] && arr[li][1]==arr[ri][1]){
            ans = min(arr[li][2], arr[ri][2]);
            cout << ans << endl;
        }
        else if(arr[li][0] == arr[ri][0]){
            cout << arr[ri][2] << endl;
        }
        else if(arr[li][1] == arr[ri][1]){
            cout << arr[li][2] << endl;
        }
        else{
            ans = arr[li][2] + arr[ri][2];
            cout << ans << endl;
        }


        //cout << "at " << i << ": " << li << ' ' << l << ' ' << lmn << ' ' << ri << ' ' << r << ' ' << rmn << endl;
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

