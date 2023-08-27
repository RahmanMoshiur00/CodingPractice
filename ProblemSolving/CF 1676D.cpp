#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 205;
int arr[mxn][mxn], n, m;

int dr(int x, int y)
{
    int i = x, j = y, sum = 0;
    while((i>=0 && i<n) && (j>=0 && j<m)){
        sum += arr[i][j];
        i++, j++;
    }
    i = x, j = y;
    sum -= arr[x][y];
    while((i>=0 && i<n) && (j>=0 && j<m)){
        sum += arr[i][j];
        i--, j--;
    }

    return sum;
}

int ur(int x, int y)
{
    int i = x, j = y, sum = 0;
    while((i>=0 && i<n) && (j>=0 && j<m)){
        sum += arr[i][j];
        i++, j--;
    }
    i = x, j = y;
    sum -= arr[x][y];
    while((i>=0 && i<n) && (j>=0 && j<m)){
        sum += arr[i][j];
        i--, j++;
    }

    return sum;
}

void solve(int test_case)
{
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    int ans = 0, v;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            v = dr(i, j) + ur(i, j) - arr[i][j];
            ans = max(ans, v);
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

