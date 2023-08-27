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

    int a[n], b[n];
    pair<int, pair<int,int>> p[2*n];
    for(int i=0; i<n; i++){
        cin >> a[i];
        p[i] = make_pair(a[i], make_pair(1, i));
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
        p[n+i] = make_pair(b[i], make_pair(2, i));
    }

    sort(p, p+(2*n));

    int val = 0;
    //minimum
    for(int i=0; i<n; i++){
        val = *lower_bound(b, b+n, a[i]) - a[i];
        cout << val << ' ';
    } cout << endl;

    debug{
        cout<<"Checking pair: ";
        for(int i=0; i<2*n; i++){
            cout << p[i].first<<" ";
        } cout << endl;
    }

    //maximum
    int ans[n], idx = n-1, cnt = 0;
    MINUS(ans);
    for(int i=2*n-1; i>=0; i--){
        if(p[i].second.first == 2){ //blue
            cnt++;
            if(cnt == 2){
                for(int j=0; j<=idx; j++) ans[j] =  p[i+1].first - a[j];
                break;
            }
        }
        else{ //red
            ans[idx] = p[i+1].first - a[idx];
            idx--;
            cnt = 0;
        }
    }

    for(int i=0; i<n; i++) cout << ans[i] << ' ';
    cout << endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

