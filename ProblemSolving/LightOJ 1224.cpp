#include <bits/stdc++.h>
using namespace std;
typedef long long int intl;
typedef unsigned long long intu;
#define all(a)        a.begin(),a.end()
#define Unique(a)     sort(all(a)),a.erase(unique(all(a)),a.end())
#define INPUT         freopen("input.txt","r",stdin);
#define OUTPUT        freopen("output.txt","w",stdout);
#define FastRead      ios::sync_with_stdio(0); cin.tie(0);
#define sfi(x)        scanf("%d", &x)
#define sfl(x)        scanf("%lld", &x)
#define sfc(x)        scanf(" %c", &x)
#define sfs(x)        scanf(" %s", x)
#define sfu(x)        scanf("%llu", &x)
#define pfi(x)        printf("%d\n", x)
#define pfl(x)        printf("%lld\n", x)
#define pfu(x)        printf("%llu\n", x)
#define endl          "\n"
#define sp            " "
#define debug(x)      cout<<" <<debug>> "<< #x <<": "<<x<<endl
#define debugi(i, x)  cout<<" <<debug>> "<< #x <<"["<<i<<"]"<<": "<<x<<endl
#define repeach(it, x) for(__typeof__((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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
#define INF           1073741820
#define mod           1000000007
#define mxn           1000010

struct node{
    intl cnt;
    node* next[4];

    node(){
        cnt = 0LL;
        rep(i, 0, 4) next[i] = NULL;
    }
};

int idx(char ch){
    if(ch == 'A') return 0;
    else if(ch == 'C') return 1;
    else if(ch == 'G') return 2;
    else if(ch == 'T') return 3;
}

intl INSERT(string& s, node* root){
    node* temp = root;
    int l = s.size();

    intl ret = 0LL;
    rep(i, 0, l){
        int v = idx(s[i]);
        if(temp->next[v] == NULL) temp->next[v] = new node;
        temp = temp->next[v];
        temp->cnt += 1;
        ret = max(ret, temp->cnt * (i+1));
    }

    return ret;
}

void DELETE(node* root){
    rep(i, 0, 4){
        if(root->next[i] != NULL) DELETE(root->next[i]);
        delete root->next[i];
    }
}

void solve(int t){
    int n; cin>>n;
    string s;

    node* root = new node;

    intl ans = 0;
    while(n--){
        cin>>s;
        ans = max(ans , INSERT(s, root));
    }

    DELETE(root);
    delete root;

    cout<<"Case "<<t<<": "<<ans<<endl;
}

int main()
{
    int tc; cin>>tc;

    rep(t, 1, tc+1){
        solve(t);
    }

    return 0;
}


