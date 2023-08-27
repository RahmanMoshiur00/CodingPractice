#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 100010;

bool All(string s, char c)
{
    vector<int> v;
    for(int i=0; i<s.size(); i++){
        if(s[i]==c) v.push_back(i);
    }

    for(int i=1; i<v.size(); i++){
        if(v[i-1]+1==v[i]) return false;
    }

    return true;
}

bool zero_one(string s)
{
    for(int i=1; i<s.size(); i++){
        if(s[i-1]==s[i] && s[i]=='1'){
            for(int j=i+1; j+1<s.size(); j++){
                if(s[j]==s[j+1] && s[j]=='0') return false;
            }
            return true;
        }
    }
    return true;
}

void solve(int test_case)
{
    string s;
    cin >> s;

    if(All(s, '0')){
        //cout << "Remove Zero: ";
        cout << "YES" << endl;
    }
    else if(All(s, '1')){
        //cout << "Remove One: ";
        cout << "YES" << endl;
    }
    else if(zero_one(s)){
       // cout << "Zero One: ";
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

