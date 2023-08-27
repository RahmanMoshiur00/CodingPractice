#include<bits/stdc++.h>
using namespace std;

#define MAX 1000
int rep[MAX];
vector< pair<int, int> > path; //for storing the edges in the path of MST

struct edge{
    int u, v, w;
};

bool cmp(edge a, edge b){
    return a.w < b.w;
}

void setRepresentator(){
    for(int i=0; i<MAX; i++) rep[i] = i;
}

int findRep(int n){ //using disjoint set
    if(rep[n] == n) return n;
    else return rep[n] = findRep(rep[n]);
}


int MST(vector<edge>& node){
    int cost = 0;
    int sz = node.size();
    for(int i=0; i<sz; i++){ //O(E)
        int e1 = node[i].u;
        int e2 = node[i].v;
        if(findRep(e1) != findRep(e2)){
            rep[e1] = rep[e2]; //updating representator
            cost += node[i].w;
            path.push_back({e1, e2});
        }
    }
    return cost;
}


int main()
{
    int e; cin>>e; //total number of edges in the undirected graph
    vector<edge> nodes(e);

    cout<<"Enter two nodes and their weights:\n";
    for(int i=0; i<e; i++){
        cin>>nodes[i].u>>nodes[i].v>>nodes[i].w;
    }

    sort(nodes.begin(), nodes.end(), cmp); //O(E logE)
    setRepresentator();
    int ans = MST(nodes);

    cout<<"Minimum cost of MST = "<<ans<<endl;

    //printing path(edges included in MST)
    int sz = path.size();
    cout<<"Path::\n";
    for(int i=0; i<sz; i++){
        cout<<path[i].first<<" "<<path[i].second<<endl;
    }

    return 0;
}
