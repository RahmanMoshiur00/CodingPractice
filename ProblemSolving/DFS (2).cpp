#include <bits/stdc++.h>
using namespace std;

const int mxn = 100010;
vector<int> adj[mxn];
bool vis[mxn];

void DFS(int x, int y)
{
    vis[x] = true;
    if(x == y){
        cout << "Destination is reached!" << endl;
        return;
    }

    int u, v;
    for(int i=0; i<adj[x].size(); i++){
        v = adj[x][i];
        if(!vis[v]){
            DFS(v, y);
        }
    }

}

int main()
{
    int n, m, x, y, u, v;

    cout << "Enter the source and destination nodes respectively: ";
    cin >> x >> y;

    cout << "Enter the number of edges: ";
    cin >> m;

    for(int i=0; i<mxn; i++){
        adj[i].clear();
        vis[i] = false;
    }

    for(int i=0; i<m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(x, y);
}
