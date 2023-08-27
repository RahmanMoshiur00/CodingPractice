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
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    bool vis[n]; ZERO(vis);

    for(int i=0; i<n; i++){
        if(!vis[i] && s[i] != '?'){
            for(int j=i; j<n; j+=k){
                if(s[j]!='?' && s[i]!=s[j]){
                    cout << "NO" << endl;
                    return;
                }
                s[j] = s[i];
                vis[j] = true;
            }
            for(int j=i; j>=0; j-=k){
                if(s[j]!='?' && s[i]!=s[j]){
                    cout << "NO" << endl;
                    return;
                }
                s[j] = s[i];
                vis[j] = true;
            }
        }
    }

    int cnt[2][n+5];
    ZERO(cnt);

    for(int i=1; i<=n; i++){
        cnt[0][i] = cnt[0][i-1] + (s[i-1]=='0');
        cnt[1][i] = cnt[1][i-1] + (s[i-1]=='1');
    }

    int zero , one;
    for(int i=0; i<=n-k; i++){
        zero = cnt[0][i+k] - cnt[0][i];
        one = cnt[1][i+k] - cnt[1][i];
        if(zero>(k/2) || one>(k/2)){
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

