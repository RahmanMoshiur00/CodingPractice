#include <bits/stdc++.h>
using namespace std;
#define int           long long
#define endl          '\n'
#define all(a)        a.begin(), a.end()
#define ZERO(a)       memset(a, 0, sizeof(a))
#define MINUS(a)      memset(a, 0xff, sizeof(a))
#define debug         if( 0 )

const int mxn = 1010;
int n, m;
bool vis[mxn][mxn];
string adj[mxn];
char path[mxn][mxn];

int dx[] = {0, 0, -1, +1}; //L R U D
int dy[] = {-1, +1, 0, 0};

bool isPossible(int i, int j)
{
    if(i>=0 && i<n && j>=0 && j<m && adj[i][j]!='#') return true;
    else return false;
}

bool bfs(int i, int j)
{
    queue< pair<int,int> > qu;
    qu.push(make_pair(i, j));
    vis[i][j] = true;
    path[i][j] = '~';

    string direction = "LRUD";
    pair<int,int> p;
    while(!qu.empty()){
        p = qu.front();
        qu.pop();

        if(adj[p.first][p.second] == 'B'){
            return true;
        }
        for(int k=0; k<4; k++){
            int ii = p.first + dx[k], jj = p.second + dy[k];
            if(isPossible(ii, jj) && !vis[ii][jj]){
                qu.push(make_pair(ii, jj));
                vis[ii][jj] = true;
                path[ii][jj] = direction[k];
            }
        }
    }
    return false;
}

void path_build(int i, int j, int cnt)
{
    if(adj[i][j] == 'A'){
        cout << cnt << endl;
        return;
    }
    int ii = i, jj = j;
    if(path[i][j] == 'L') jj++;
    if(path[i][j] == 'R') jj--;
    if(path[i][j] == 'U') ii++;
    if(path[i][j] == 'D') ii--;

    path_build(ii, jj, cnt+1);
    cout << path[i][j];
}

void solve(int test_case)
{
    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> adj[i];
    }

    int si, sj, ei, ej;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(adj[i][j]=='A'){
                si = i;
                sj = j;
            }
            else if(adj[i][j] == 'B'){
                ei = i;
                ej = j;
            }
        }
    }


    if(bfs(si, sj) == false){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        path_build(ei, ej, 0);
        cout << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    solve(1);
    //int tc; cin >> tc; for(int t=1; t<=tc; t++) solve(t);

    return 0;
}

