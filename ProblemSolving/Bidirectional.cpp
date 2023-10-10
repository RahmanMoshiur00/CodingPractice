#include <bits/stdc++.h>
using namespace std;

const int mxn = 100010;
vector<int> adj[mxn];
bool vis1[mxn], vis2[mxn];


int isFound(queue<int> q1, queue<int> q2){
    vector<int> v1, v2;
    int x;
    while(!q1.empty()){
        x = q1.front(); q1.pop();
        v1.push_back(x);
    }
    while(!q2.empty()){
        x = q2.front(); q2.pop();
        v2.push_back(x);
    }

    for(int i=0; i<v1.size(); i++){
        for(int j=0; j<v2.size(); j++){
            if(v1[i]==v2[j]){
                return v1[i];
            }
        }
    }

    return -1;
}

void Bidirection_Search(int x, int y)
{
    queue<int> qu1, qu2;
    qu1.push(x);
    qu2.push(y);
    vis1[x] = vis2[y] = true;

    int ux, uy, vx, vy, flag;
    while(!qu1.empty() && !qu2.empty()){
        flag = isFound(qu1, qu2);
        if(flag != -1){
            cout << "Joins at: " << flag << endl;
            return;
        }
        ux = qu1.front(); qu1.pop();
        uy = qu2.front(); qu2.pop();

        for(int i=0; i<adj[ux].size(); i++){
            vx = adj[ux][i];
            if(!vis1[vx]){
                vis1[vx] = true;
                qu1.push(vx);
            }
        }

        for(int i=0; i<adj[uy].size(); i++){
            vy = adj[uy][i];
            if(!vis2[vy]){
                vis2[vy] = true;
                qu2.push(vy);
            }
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
        vis1[i] = vis2[i] = false;
    }

    for(int i=0; i<m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Bidirection_Search(x, y);
}

/*
4 8
7
1 2
1 3
2 4
2 5
6 3
3 7
8 3
*/

