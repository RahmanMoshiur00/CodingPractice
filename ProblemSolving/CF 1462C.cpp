#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 100010;

int num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

vector<string> ans;
string tmp;

int sum(string s)
{
    int tot = 0;
    for(int i=0; i<s.size(); i++){
        tot += s[i] - '0';
    }
    return tot;
}

string f(int i, string s, int n)
{
    if(i>=10) return "";

    tmp = s;
    tmp += num[i] + '0';

    if(sum(s) == n){
        ans.push_back(s);
    }
    if(sum(s) + num[i] == n){
        ans.push_back(tmp);
    }

    f(i+1, tmp, n);
    f(i+1, s, n);
}

bool cmp(string& a, string& b)
{
    if(a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

void solve(int test_case)
{
    int n;
    cin >> n;

    ans.clear();
    f(1, "", n);

    sort(all(ans), cmp);
    if(ans.size() > 0) cout << ans[0] << endl;
    else cout << -1 << endl;

}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

