#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 100010;

bool f(double h, double s, double c)
{
    double r = ((h*h) + (c*c)) / (2*h);
    double sr =  r * 2 * asin(c/r);
    return sr >= s;
}

void solve(int test_case)
{
    double l, n, c;
    cin >> l >> n >> c;

    double s = l + (n*l*c);

    double lo = 0, hi = l, mid;
    for(int i=0; i<300; i++){
        mid = (lo + hi) / 2;
        if(f(mid, s, l/2)) hi = mid;
        else lo = mid;
    }

    cout << "Case " << test_case << ": " << fixed << setprecision(12) << mid << endl;
}

int32_t main()
{
    //freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    //solve(1);
    int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

