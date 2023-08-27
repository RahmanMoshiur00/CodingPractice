#include <bits/stdc++.h>
using namespace std;

#define debug      if(1)

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1}; // 4 Directions (up, down, left, right)

bool graph[105][105][4], vis[105][105];
int n, m;
char s[105][105];

int bfs(int x, int y)
{
    int cnt = 1;
    vis[x][y] = true;

    queue< pair<int,int> > qu;
    qu.push({x, y});

    while(!qu.empty()){
        x = qu.front().first, y = qu.front().second;
        qu.pop();

        for(int i=0; i<4; i++){
            int X = x + dx[i], Y = y + dy[i];
            if(X>=0 && X<n && Y>=0 && Y<m && vis[X][Y]==false && graph[x][y][i]==true){
                vis[X][Y] = true;
                qu.push({X, Y});
                cnt++;
            }
        }
    }



    return cnt;
}

void solve(int tc)
{
    scanf("%d %d ", &n, &m);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<4; k++) graph[i][j][k] = true;
            vis[i][j] = false;
        }
    }

    for(int i=0; i<n; i++) scanf("%s", s[i]);

    for(int i=0; i+1<n; i++){
        for(int j=0; j+1<m; j++){
            if(s[i][j] == 'B') graph[i][j][0] = graph[i][j][2] = false; // up & left
            if(s[i][j] == 'R') graph[i][j][0] = false; // up
            if(s[i][j] == 'D') graph[i][j][2] = false; // left

            if(s[i][j+1]=='B' || s[i][j+1]=='D') graph[i][j][3] = false; // right
            if(s[i+1][j]=='B' || s[i+1][j]=='R') graph[i][j][1] = false; // down
        }
    }

    n--, m--;

    int ans = 0;
    for(int j=0; j<m; j++){
        if(!vis[0][j] && !(s[0][j]=='B' || s[0][j]=='R')){
            ans += bfs(0, j);
        }
    }

    printf("Case %d: %d\n", tc, ans);
}

int main()
{
    int tc; scanf("%d", &tc);
    for(int t=1; t<=tc; t++) solve(t);
    return 0;
}
