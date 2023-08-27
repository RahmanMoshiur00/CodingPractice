#include <bits/stdc++.h>
using namespace std;

void solve(int tc)
{
    int n, l, r, val;
    cin >> n >> l >> r;

    int ans[n];
    for(int i=1; i<=n; i++){
        val = r / i;
        if(val*i == r){
            ans[i-1] = r;
        }
        else{
            val = val * i;
            if(val<l){
                cout << "NO" << endl;
                return;
            }
            else{
                ans[i-1] = val;
            }
        }
    }

    cout << "YES" << endl;
    for(int i=0; i<n; i++) cout << ans[i] << ' ';
    cout << endl;
}

int main()
{
    int tc;
    cin >> tc;

    for(int i=1; i<=tc; i++) solve(i);

    return 0;
}
