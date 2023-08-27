#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long int intl;
typedef unsigned long long intu;
typedef pair<intl, intl> pll;
typedef pair<int, int> pii;
typedef pair<intl, pair<intl,intl> > plll;
typedef pair<int, pair<int,int> > piii;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //e.g. ordered_set<int> s; s.insert(3); cout<<s.ook(3)<<*s.fbo(3);
#define ook           order_of_key
#define fbo           find_by_order //returns pointer
#define all(a)        a.begin(),a.end()
#define Unique(a)     sort(all(a)),a.erase(unique(all(a)),a.end())
#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sfi(x)        scanf("%d", &x)
#define sfl(x)        scanf("%lld", &x)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfu(x)        scanf("%llu", &x)
#define pfi(x)        printf("%d\n", x)
#define pfl(x)        printf("%lld\n", x)
#define pfu(x)        printf("%llu\n", x)
#define endl          '\n'
#define sp            ' '
#define debug(x)      cout<<">debug> "<< #x <<" : "<<x<<endl
#define FOREACH(it, x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define FOR(i,a,b)    for(intl i=(intl)(a);i<=(intl)(b);++i)
#define ROF(i,a,b)    for(intl i=(intl)(a);i>=(intl)(b);--i)
#define pb            push_back
#define MP            make_pair
#define ff            first
#define ss            second
#define sf            second.first
#define sd            second.second
#define mem(a,v)      memset((a), v, sizeof(a))
#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))
#define SQ(a)         ((a)*(a))
#define ABS(x)        ((x)<0?-(x):(x))
#define PI            acos(-1.0)
#define ERR           0.000000001
#define INF           1000000000
#define mod           1000000007
#define mxn           1000010

intl gcd (intl a, intl b, intl & x, intl & y) {
	if (a == 0LL) {
		x = 0LL; y = 1LL;
		return b;
	}
	intl x1, y1;
	intl d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

bool find_any_solution (intl a, intl b, intl c, intl & x0, intl & y0, intl & g) {
	g = gcd (abs(a), abs(b), x0, y0);
	if (c % g != 0)
		return false;
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0)   x0 *= -1LL;
	if (b < 0)   y0 *= -1LL;
	return true;
}

void shift_solution(intl & x, intl & y, intl a, intl b, intl cnt) {
	x += cnt * b;
	y -= cnt * a;
}

intl find_all_solutions(intl a, intl b, intl c, intl minx, intl maxx, intl miny, intl maxy) {
	intl x, y, g;
	if (! find_any_solution (a, b, c, x, y, g))
		return 0LL;
	a /= g;  b /= g;

	intl sign_a = a>0 ? +1LL : -1LL;
	intl sign_b = b>0 ? +1LL : -1LL;

	shift_solution (x, y, a, b, (minx - x) / b);
	if (x < minx)
		shift_solution (x, y, a, b, sign_b);
	if (x > maxx)
		return 0;
	intl lx1 = x;

	shift_solution (x, y, a, b, (maxx - x) / b);
	if (x > maxx)
		shift_solution (x, y, a, b, -sign_b);
	intl rx1 = x;

	shift_solution (x, y, a, b, - (miny - y) / a);
	if (y < miny)
		shift_solution (x, y, a, b, -sign_a);
	if (y > maxy)
		return 0;
	intl lx2 = x;

	shift_solution (x, y, a, b, - (maxy - y) / a);
	if (y > maxy)
		shift_solution (x, y, a, b, sign_a);
	intl rx2 = x;

	if (lx2 > rx2)
		swap (lx2, rx2);
	intl lx = max (lx1, lx2);
	intl rx = min (rx1, rx2);

	return ((rx - lx) / abs(b)) + 1LL;
}


int main()
{
    intl maxx, maxy, n, m;
    cin>>maxx>>maxy>>n>>m;

    intl ans = find_all_solutions(m, -n, 0LL, 1LL, maxx, 1LL, maxy);
    cout<<ans<<endl;


    return 0;
}

