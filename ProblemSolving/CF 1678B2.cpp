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
    string s;
    cin >> n >> s;

    int ans = 0, m = n/2, m_count = 0;
    int arr[m];
    for(int i=0, j=0; i+1<n; i+=2){
        if(s[i] != s[i+1]){
            ans++;
        }
        else{
            if(s[i] == '0') arr[m_count++] = 0;
            else arr[m_count++] = 1;
        }
    }


    int seg = 0;
    for(int i=0; i<m_count; i++){
        seg++;
        int j = i+1;
        for(; j<m; j++){
            if(arr[j] != arr[i]){
                break;
            }
        }
        i = j-1;
    }

    seg = max(1LL, seg);

    cout << ans << ' ' << seg << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}


