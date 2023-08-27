#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define int           long long

#define sfi(x)        scanf("%lld", &x)
#define sfi2(x, y)    sfi(x) , sfi(y)
#define sfi3(x, y, z) sfi(x) , sfi(y) , sfi(z)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfsn(x)       scanf(" %[^\n]s", x)

#define pfi(x)        printf("%lld", (intl)x)
#define pfin(x)       printf("%lld", (intl)x), printf("\n")
#define pfis(x)       printf("%lld", (intl)x), printf(" ")
#define pfc(x)        printf("%c", x)
#define pfs(x)        printf("%s", x)
#define pfsn(x)       printf("%s", x), printf("\n")
#define spc           printf(" ")
#define nwl           printf("\n")
#define endl          '\n'
#define sp            ' '

#define watch(x)      cout<<"::debug::   "<< #x <<" : "<<x<<endl
#define watchi(x, i)  cout<<"::debug::   "<< #x <<"-> ["<<i<<"]"<<" : "<<x<<endl

#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(false), cin.tie(0);

#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define repit(it, x)  for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define perit(it, x)  for(__typeof((x).rbegin()) it = (x).rbegin(); it != (x).rend(); ++it)
#define rep(i, begin, end) for(int i = (begin), ed = (end); i < (ed); ++i)
#define per(i, end, begin) for(int i = (end)-1, bg = (begin); i >= (bg); --i)

#define setval(a, v)  for(int i = 0, sz = (sizeof(a)/sizeof(*a)); i<sz; i++){ a[i] = v; }
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))

#define all(a)        a.begin(), a.end()
#define min3(x, y, z) min(x,min(y,z))
#define max3(x, y, z) max(x,max(y,z))
#define INF           1000000007
#define debug         if( 0 )

#define mxn           200010 // max size of the array
#define mxq           200010 // max no. of Query
#define mxv           1000010 // max value of the input element

const int block_size = 746;
int arr[mxn], ans[mxq];

struct Query
{
    int l, r, id;
    Query() {}
    Query(int _l, int _r, int _id){
        l = _l, r = _r, id = _id;
    }

    bool operator<(Query b)
    {
        if(l/block_size == b.l/block_size) return r < b.r;
        return l/block_size < b.l/block_size;
    }
};

struct MOs
{
    int data[mxv]; // mxv: max value of the input array element
    int answer;

    MOs(){
        memset(data, 0, sizeof data);
        answer = 0LL;
    }

    void add(int v){
        answer -= data[v] * data[v] * v;
        data[v]++;
        answer += data[v] * data[v] * v;
    }
    void remove(int v){
        answer -= data[v] * data[v] * v;
        data[v]--;
        answer += data[v] * data[v] * v;
    }
    int solution(){
        return answer;
    }
};

void solve(int tc)
{
    int n, q, l, r; sfi2(n, q);

    rep (i, 0, n) sfi(arr[i]);

    vector< Query > vq(q);
    rep (i, 0, q) {
        sfi2(l, r);
        l--, r--;
        vq[i] = Query(l, r, i);
    }

    sort(all(vq));

    MOs result;

    int mo_left = 0, mo_right = -1;
    rep (i, 0, q) {
        int left = vq[i].l;
        int right = vq[i].r;

        while(mo_right < right){
            mo_right++;
            result.add(arr[mo_right]);
        }
        while(mo_right > right){
            result.remove(arr[mo_right]);
            mo_right--;
        }

        while(mo_left < left){
            result.remove(arr[mo_left]);
            mo_left++;
        }
        while(mo_left > left){
            mo_left--;
            result.add(arr[mo_left]);
        }

        ans[vq[i].id] = result.solution();
    }

    rep(i, 0, q) pfin(ans[i]);
}

int32_t main()
{
    solve(1);

    return 0;
}

