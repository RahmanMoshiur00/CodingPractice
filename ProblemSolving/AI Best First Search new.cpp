#include <bits/stdc++.h>
using namespace std;

const int mxn = 105;
vector< int > adj[mxn];
vector< pair<int,int> > path;
int cost[mxn][mxn];
int pathCost[mxn];
int dist[mxn];
int parent[mxn];
int Hsld[mxn];


int Greedy_Best_First_Search(int source, int destination)
{
    for(int i=0; i<mxn; i++){
        parent[i] = -1;
        pathCost[i] = dist[i] = 0;
    }

    priority_queue< pair<int,int>, vector<pair<int,int>>, greater< pair<int,int> > > pq;
    pq.push({0, source});

    int u, v;
    pair<int,int> p;
    while(!pq.empty()){
        p = pq.top();
        pq.pop();
        u = p.second;
        if(parent[u] != -1) path.push_back({parent[u], u});

        if(u == destination){
            return 1;
        }

        for(int i=0; i<adj[u].size(); i++){
            v = adj[u][i];
            pathCost[v] = pathCost[u] + cost[u][v];
            dist[v] = Hsld[v];
            parent[v] = u;
            pq.push({dist[v], v});
        }
    }

    return 0;
}


void Print_Path()
{
    for(int i=0; i<path.size(); i++){
        cout << path[i].first << " -> " << path[i].second << endl;
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes;

    int u, v, h, w;
    for(int i=0; i<nodes; i++){
        cin >> u >> h;
        Hsld[u] = h;
    }

    cin >> edges;
    for(int i=0; i<edges; i++){
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cost[v][u] = cost[u][v] = w;
    }

    int source, destination;
    cin >> source >> destination;

    if(Greedy_Best_First_Search(source, destination)){
        cout << "Result is found!" << endl;
        cout << "Total cost: " << pathCost[destination] << endl;
        Print_Path();
    }
    else{
        cout << "Result is not found!" << endl;
    }

}

/*
20
1 366
2 0
3 160
4 242
5 161
6 176
7 77
8 151
9 226
10 244
11 241
12 234
13 380
14 100
15 193
16 253
17 329
18 80
19 199
20 374

23
1 20 75
20 13 71
13 16 151
1 16 140
1 17 118
16 6 99
16 15 80
6 2 211
15 14 97
14 2 101
15 3 146
14 3 138
17 10 111
10 11 70
11 4 75
4 3 120
7 2 90
12 9 87
9 19 92
19 18 142
18 8 98
8 5 86
2 18 85

1 2

*/

