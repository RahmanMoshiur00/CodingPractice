#include<bits/stdc++.h>
using namespace std;
#define pb push_back

bool visited[21][21];
vector<string> str;
int ans = 1;

void DFS(int x, int r, int y, int c){
    visited[x][y] = true;
    if(str[x][y] == '#') return;
    if( (x<0 && x>=r) || (y<0 && y>=c) ) return;
    ans++;

    if(visited[x-1][y] == false) DFS(x-1, r, y, c);
    if(visited[x+1][y] == false) DFS(x+1, r, y, c);
    if(visited[x][y+1] == false) DFS(x, r, y+1, c);
    if(visited[x][y-1] == false) DFS(x, r, y-1, c);
}

int main(){
    int t, r, c, x, y;
    char ch;
    scanf("%d ", &t);
    for(int tc=1; tc<=t; tc++){
        scanf("%d %d", &c, &r);

        for(int i=0; i<21; i++){
            for(int j=0; j<21; j++) visited[i][j] = false;
        }

        for(int i=0; i<r; i++){
            string s; cin>>s;
            str.pb(s);
        }

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(str[i][j] == '@'){
                    x = i;
                    y = j;
                    break;
                }
            }
        }

        DFS(x, r, y, c);
        printf("Case %d: %d\n", tc, ans);
        ans = 1;
        int sz = str.size();
        for(int i=0; i<sz; i++) str[i].clear();
    }

    return 0;
}
