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
    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    string s;
    cin >> s;

    vector<int> liked, disliked;
    for(int i=0; i<n; i++){
        if(s[i]=='0'){
            disliked.push_back(v[i]);
        }
        else{
            liked.push_back(v[i]);
        }
    }

    sort(all(liked));
    sort(all(disliked));

    map<int, int> mp;
    int counter = 1;
    for(int i=0, sz=disliked.size(); i<sz; i++){
        mp[disliked[i]] = counter++;
    }
    for(int i=0, sz=liked.size(); i<sz; i++){
        mp[liked[i]] = counter++;
    }

    for(int i=0; i<n; i++){
        cout << mp[v[i]] << ' ';
    } cout << endl;

}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

