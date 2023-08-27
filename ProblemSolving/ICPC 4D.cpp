#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 10;

bool check(int n[])
{
    int a = (n[0]+n[1]-n[4]) / 2,
        b = (n[0]-n[1]+n[4]) / 2,
        c = (n[1]-n[0]+n[4]) / 2,
        d = (2*n[2] - n[0] - n[1] + n[4]) / 2,
        e = (2*n[3] - n[0] - n[1] + n[4]) / 2;

    if(a+b==n[0] &&
       a+c==n[1] &&
       a+d==n[2] &&
       a+e==n[3] &&
       b+c==n[4] &&
       b+d==n[5] &&
       b+e==n[6] &&
       c+d==n[7] &&
       c+e==n[8] &&
       d+e==n[9] ){
       int ans[5] = {a, b, c, d, e};
       sort(ans, ans+5);
       for(int i=0; i<5; i++) cout << ' ' << ans[i];
       cout << endl;
       return true;
    }

    return false;
}

void solve(int test_case)
{
    int num[10];
    for(int i=0; i<mxn; i++) cin >> num[i];

    sort(num, num+mxn);

    cout << "Case " << test_case << ":";
    do{
        if(check(num)) return;
    } while(next_permutation(num, num+mxn));
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

