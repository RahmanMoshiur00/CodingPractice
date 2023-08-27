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

    int soup[n], oven[m];
    for(int i=0; i<n; i++) cin >> soup[i];
    for(int i=0; i<m; i++) cin >> oven[i];

    int waste = 0, i, j;
    for(i=0, j=0; i<n; i++, j++){
        if(soup[i] < oven[j]){
            waste += oven[j] - soup[i];
        }
        else if(soup[i] > oven[j]){
            waste += oven[j++];
        }
    }
    while(j<m) waste += oven[j++];

    cout << waste << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve(1);
    //int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

