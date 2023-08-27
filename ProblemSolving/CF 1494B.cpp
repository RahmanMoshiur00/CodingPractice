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
    int n, u, r, d, l;
    cin >> n >> u >> r >> d >> l;

    int uu = u, rr = r, dd = d, ll = l;

    int block[2][2] = {0};
    ZERO(block);

    if(u>n-2){
        if(u==n) block[0][0] = block[0][1] = 1, l--, d--;
        else{
            if(r>=l) block[0][1] = 1, r--;
            else block[0][0] = 1, l--;
        }
    }
    if(r>n-2){
        if(r==n) block[0][1] = block[1][1] = 1, u--, d--;
        else{
            if(u>=d) block[0][1] = 1, u--;
            else block[1][1] = 1, d--;
        }
    }
    if(d>n-2){
        if(d==n) block[1][0] = block[1][1] = 1, l--, r--;
        else{
            if(r>=l) block[1][1] = 1, r--;
            else block[1][0] = 1, l--;
        }
    }
    if(l>n-2){
        if(l==n) block[0][0] = block[1][0] = 1, u--, d--;
        else{
            if(u>=d) block[0][0] = 1, u--;
            else block[1][0] = 1, d--;
        }
    }

//    for(int i=0; i<2; i++){
//        for(int j=0; j<2; j++) cout << block[i][j] << ' ';
//        cout << endl;
//    }

    if((block[0][0] + block[0][1]>uu) or (block[0][1]+block[1][1]>rr) or (block[1][0]+block[1][1]>dd) or (block[0][0]+block[1][0]>ll)){
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
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

