#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;

#define int           long long // change here
#define sfi(x)        scanf("%lld", &x) // change here

#define sfi2(x, y)    sfi(x) , sfi(y)
#define sfi3(x, y, z) sfi(x) , sfi(y) , sfi(z)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfsn(x)       scanf(" %[^\n]s", x)

#define pfi(x)        printf("%lld", (intl)x)
#define pfis(x)       printf("%lld", (intl)x), printf(" ")
#define pfin(x)       printf("%lld", (intl)x), printf("\n")
#define pfs(x)        printf("%s", x)
#define pfnl          printf("\n")
#define pfsp          printf(" ")
#define endl          '\n'
#define sp            ' '

#define watch(x)      cout<<"::debug::   "<< #x <<" : "<<x<<endl
#define watchi(i, x)  cout<<"::debug::   "<< #x <<"-> ["<<i<<"]"<<" : "<<x<<endl

#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(false), cin.tie(0);

#define FOR(i, begin, end)  for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define repit(it, x)        for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define perit(it, x)        for(__typeof((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
#define rep(i, begin, end)  for(int i = (begin), ed = (end); i < (ed); ++i)
#define per(i, end, begin)  for(int i = (end)-1, bg = (begin); i >= (bg); --i)

#define setvalue(a, v)  for(int i = 0, sz = (sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))

#define all(a)        a.begin(), a.end()
#define min3(x, y, z) min(x,min(y,z))
#define max3(x, y, z) max(x,max(y,z))
#define PI            2*acos(0)
#define INF           1000000007
#define debug         if( 1 )

const int mxn = 100010;

string s;

struct node{
    int cnt[26];
} tree[mxn * 4];

int toInt(char ch)
{
    return (ch - 'a');
}

void build(int ind, int l, int r)
{
    if(l == r){
        for(int i=0; i<26; i++) tree[l].cnt[i] = 0;
        tree[l].cnt[toInt(s[l-1])]++;
        return;
    }

    int mid = (l+r) >> 1;
    int left = ind << 1;
    int right = ind << 1 | 1;

    build(left, l, mid);
    build(right, mid+1, r);

    for(int i=0; i<26; i++){
        tree[ind].cnt[i] = tree[left].cnt[i] + tree[right].cnt[i];
    }
}

void update(int ind, int l, int r, int x, char ch)
{
    if(l == r){
        if(s[l-1] != ch){
            tree[l].cnt[toInt(s[l-1])]--;
            tree[l].cnt[toInt(ch)]++;
        }
        return;
    }

    int mid = (l+r) >> 1;
    int left = ind << 1;
    int right = ind << 1 | 1;

    if(x <= mid) update(left, l, mid, x, ch);
    else update(right, mid+1, r, x, ch);

    for(int i=0; i<26; i++){
        tree[ind].cnt[i] = tree[left].cnt[i] + tree[right].cnt[i];
    }
}

vector<int> query(int ind, int l, int r, int ql, int qr)
{
    if(qr<l || ql>r){
        vector<int> v(26, 0);
        return v;
    }

    if(ql<=l && r<=qr){
        vector<int> v(26);
        for(int i=0; i<26; i++) v[i] = tree[ind].cnt[i];
        return v;
    }

    int mid = (l+r) >> 1;
    int left = ind << 1;
    int right = ind << 1 | 1;

    vector<int> v1 = query(left, l, mid, ql, qr);
    vector<int> v2 = query(right, mid+1, right, ql, qr);

    vector<int> ans(26);
    for(int i=0; i<26; i++){
        ans[i] = v1[i] + v2[i];
    }

    return ans;
}

void solve(int tc)
{
    string s;
    cin >> s;

    int n = s.size();

    build(1, 1, n);

    debug cout << "build completed" << endl;

    int q, typ, l, r;
    char ch;

    sfi(q);
    while(q--){
        sfi(typ);
        if(typ == 1){
            sfi(l), sfc(ch);
            update(1, 1, n, l, ch);
            debug cout << "update: " << l << " " << ch << endl;
        }
        else{
            sfi2(l, r);
            int ans = 0;
            vector<int> v = query(1, 1, n, l, r);
            for(int i=0; i<v.size(); i++){
                if(v[i]) ans++;
            }
            debug cout << "query: " << l << " " << r << endl;
            pfin(ans);
        }
    }
}

int32_t main()
{
    //INPUT //OUTPUT
    //FastRead

    solve(1);
    //int tc; cin>>tc; rep(t, 1, tc+1) solve(t);

    return 0;
}

