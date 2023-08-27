#include<bits/stdc++.h>
using namespace std;
#define white 0
#define gray 1
#define black 2
#define MAX 100 //MAX is the maximum value a vertex can have

vector<int> adj[MAX];
int color[MAX];
int parent[MAX];
int dis[MAX];

void BFS(int source){
    for(int i=0; i<MAX; i++){
        color[i] = white;
        parent[i] = INT_MIN;
        dis[i] = -1;
    }

    queue<int> q;
    q.push(source);
    color[source] = gray;
    dis[source] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++){
            int v = adj[u][i];
            if(color[v]==white){
                q.push(v);
                color[v] = gray;
                parent[v] = u;
                dis[v] = dis[u] + 1;
            }
        }
        color[u] = black;
    }
}

void printPath(int source, int target){
    vector<int> path;

    while(source != target){
        path.push_back(target);
        target = parent[target];
    }
    path.push_back(source);

    cout<<"Path: ";
    for(int i=path.size()-1; i>=0; i--) cout<<path[i]<<" ";
    cout<<endl;
}

int main()
{
    cout<<"Enter how many entries(edges) you want to have: ";
    int edge; cin>>edge;

    int vertex1, vertex2;

    for(int i=0; i<edge; i++){
        cin>>vertex1>>vertex2;
        //for undirected graph
        adj[vertex1].push_back(vertex2);
        adj[vertex2].push_back(vertex1);

        //for directed graph; for edge vertex1 to vertex2
        //adj[vertex1].push_back(vertex2);
    }

    cout<<"Enter the value of the source node: ";
    int source;
    cin>>source;

    BFS(source);

    cout<<"Enter how many distance query from source you want to have: ";
    int query;
    cin>>query;

    for(int i=0; i<query; i++){
        int q;
        cin>>q;

        int dstnc = dis[q];

        if(dstnc != -1){
            cout<<"Distance: "<<dstnc<<endl;
            printPath(source, q);
        }
        else cout<<"There is no path from "<<source<<" to "<<q<<endl;
    }

    return 0;
}
