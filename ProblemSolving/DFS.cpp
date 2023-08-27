#include<bits/stdc++.h>
using namespace std;
#define white 0
#define gray 1
#define black 2
#define pb push_back
#define MAX 100

int Time = 0;
vector<int> adj[MAX];
int color[MAX];
int parent[MAX];
int dis[MAX]; //distance is not garraunteed to shortest in DFS; so this array almost not useful
int d[MAX]; //discovery time array
int f[MAX]; //finish time array

void DFS(int source){
    color[source] = gray;
    Time++;
    d[source] = Time;
    for(int i=0; i<adj[source].size(); i++){
        int v = adj[source][i];
        if(color[v]==white){
            parent[v] = source;
            dis[v] = dis[source] + 1;
            DFS(v);
        }
    }
    color[source] = black;
    Time++;
    f[source] = Time;
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
    for(int i=0; i<MAX; i++){
        color[i] = white;
        parent[i] = INT_MIN;
        dis[i] = -1;
        d[i] = 0;
        f[i] = 0;
    }

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

    dis[source] = 0;//initializing zero to the distance of source node

    DFS(source);

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
