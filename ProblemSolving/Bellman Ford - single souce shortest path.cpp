#include<bits/stdc++.h>
using namespace std;
#define MX 1005
#define INF 1000000000
#define pb push_back
#define mp make_pair
#define ff first
#define ss second.first
#define tt second.second

typedef pair<int, pair<int, int> > piii;

vector< piii > edges;
int parent[MX];
int cost[MX];
set<int> nodes;

void initalization(){
    for(int i=0; i<MX; i++){
        cost[i] = INF;
        parent[i] = INF;
    }
}

void BellmanFord(int s, int n){
    initalization();
    cost[s] = 0;
    int sz = edges.size(), u, v, w;
    for(int i=1; i<=n-1; i++){
        for(int j=0; j<sz; j++){
            u = edges[j].ff;
            v = edges[j].ss;
            w = edges[j].tt;
            if(cost[v] > cost[u] + w){
                cost[v] = cost[u] + w;
                parent[v] = u;
            }
        }
    }
}

void printPath(int n){
    stack<int> path;
    path.push(n);
    while(parent[n] != INF){
        n = parent[n];
        path.push(n);
    }
    while(!path.empty()){
        cout<<" "<<path.top();
        path.pop();
    }
}

int main()
{
    int u, v, e, w, q, source;
    cout<<"Enter how many edge entries you want to have: ";
    cin>>e;
    cout<<"Enter two nodes and their weight:\n";

    for(int i=0; i<e; i++){
        cin>>u>>v>>w;
        edges.pb(mp(u, mp(v,w))); //directed graph
        nodes.insert(u); // for storing distinct nodes
        nodes.insert(v);
    }

    cout<<"Enter the source vertex: ";
    cin>>source;

    int sz = nodes.size();
    BellmanFord(source, sz);

    cout<<"Enter how many shortest path search queries you want to have: ";
    cin>>q;

    for(int i=0; i<q; i++){
        cin>>u;
        if(cost[u] != INF){
            cout<<"Shortest distance from the source node "<<source<<" to "<<u<<" :  "<<cost[u]<<endl;
            cout<<"Path:";
            printPath(u);
            cout<<endl;
        }
        else cout<<"There is no path from source "<<source<<" :  "<<u<<endl;
    }

    return 0;
}

