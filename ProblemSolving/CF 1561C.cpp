#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 100010;
vector< int > vp;
int n;

bool ok(int x){
    int cave;
    for(int i=0; i<n; i++){
        if(x)
    }
    return true;
}

void solve(int test_case)
{
    cin >> n;

    vp.clear();
    for(int i=0; i<n; i++) v[i].clear();

    int armor, max_armor, k, max_armor_index;

    for(int i=0; i<n; i++){
        cin >> k;
        max_armor = 0, max_armor_index = -1;
        for(int j=0; j<k; j++){
            cin >> armor;
            if(max_armor < armor){
                max_armor = armor;
                max_armor_index = j;
            }
        }
        vp.push_back(max_armor-max_armor_index+1);
    }

    sort(all(vp));

    int lo = 0, hi = 1e15, mid;

    while(hi-lo>1){
        mid = (lo+hi) / 2;
        if(ok(mid)) hi = mid;
        else lo = mid;
    }

    for(int i=lo; i<=hi; i++){
        if(ok(i)){
            cout << i << endl;
            return;
        }
    }

}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

