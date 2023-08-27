#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 1 )

const int MXN = 1010, INF = 1e9;

string adj[MXN];
bool vis[MXN][MXN];
char path[MXN][MXN];
int steps[MXN][MXN];
int n, m;

int dx[] = {0, 0, -1, +1}; //LRUD
int dy[] = {-1, +1, 0, 0};
string direction = "LRUD";

struct tuples{
    int first = 0, second = 0, third = 0;
    tuples(){ }
    tuples(int _first, int _second, int _third){
        first = _first;
        second = _second;
        third = _third;
    }
};


bool isValid(int i, int j)
{
    return (i>=0 && i<n && j>=0 && j<m && adj[i][j]=='.');
}

bool isBorder(int i, int j)
{
    return (i==0 || i==n-1 || j==0 || j==m-1);

}

void bfs_monster(vector< pair<int,int> > monsters)
{
    queue<tuples> q;
    for(int i=0; i<monsters.size(); i++){
        steps[monsters[i].first][monsters[i].second] = 0;
        q.push(tuples(monsters[i].first, monsters[i].second, 0));
    }

    tuples t;
    int x, y;
    while(!q.empty()){
        t = q.front(); q.pop();
        for(int k=0; k<4; k++){
            x = t.first + dx[k];
            y = t.second + dy[k];
            if(isValid(x, y) && t.third + 1 < steps[x][y]){
                steps[x][y] = t.third + 1;
                q.push(tuples(x, y, steps[x][y]));
            }
        }
    }
}

pair<int,int> bfs_player(pair<int,int> s)
{
    queue< tuples > qu;
    qu.push(tuples(s.first, s.second, 0));
    vis[s.first][s.second] = true;

    tuples t;
    int x, y;
    while(!qu.empty()){
        t = qu.front(); qu.pop();

        if(isBorder(t.first, t.second)){
            return make_pair(t.first, t.second);
        }

        for(int k=0; k<4; k++){
            x = t.first + dx[k];
            y = t.second + dy[k];
            if(isValid(x, y) && !vis[x][y] && t.third+1<steps[x][y]){
                path[x][y] = direction[k];
                qu.push(tuples(x, y, t.third+1));
                vis[x][y] = true;
            }
        }
    }

    return make_pair(-1, -1);
}


void print_path(pair<int,int> s, pair<int,int> now, int cnt)
{
    if(s.first == now.first && s.second == now.second){
        cout << cnt << endl;
        return;
    }

    pair<int,int> next = now;
    if(path[now.first][now.second] == 'L') next.second = now.second + 1;
    else if(path[now.first][now.second] == 'R') next.second = now.second - 1;
    else if(path[now.first][now.second] == 'U') next.first = now.first + 1;
    else next.first = now.first - 1;

    print_path(s, next, cnt+1);

    cout << path[now.first][now.second];
}

void data_init()
{
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) steps[i][j] = INF;
    }

}

void solve(int test_case)
{
    cin >> n >> m;

    data_init();

    for(int i=0; i<n; i++) cin >> adj[i];

    vector< pair<int,int> > vp;
    pair<int,int> s, p;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            path[i][j] = '*';
            if(adj[i][j] == 'A'){
                s = make_pair(i, j);
            }
            if(adj[i][j] == 'M'){
                vp.push_back(make_pair(i, j));
            }
        }
    }

    bfs_monster(vp);

    p = bfs_player(s);

    if(p.first == -1 && p.second == -1){
        cout << "NO" << endl;

    }
    else{
        cout << "YES" << endl;
        print_path(s, p, 0);
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve(1);
    //int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

