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
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int first = -1, last = -1;
    for(int i=0; i<n; i++){
        if(s[i]=='*' && first==-1) first = i;
        if(s[i]=='*') last = i;
    }

    if(first == last){
        cout << 1 << endl;
        return;
    }

    int ans = 2, prev = first, recent_star;
    for(int i=first; i<last-k; i++){
        for(int j=i; j<i+k; j++){
            if(s[j]=='*' && j-prev<=k){
                recent_star = j;
            }
        }
        i = recent_star;
        prev = recent_star;
        //debug cout << i << ": " << recent_star << endl;
        ans++;
    }

    cout << ans + 1 << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

