#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<int> adj_1[MAX]; //for DFS_1
vector<int> adj_2[MAX]; //for DFS_2
stack<int> st; //storing nodes according to descending order of finishing time in DFS_1
vector<bool> check_1(MAX, false); //checking nodes if it is discovered for DFS_1
vector<bool> check_2(MAX, false); //checking nodes if it is discovered for DFS_2
vector<int> component_head; //storing the nodes for which DFS_2 will run and create a component
vector<int> components[MAX]; //in this 2D array, all visited nodes for DFS_2 is to be stored and all are in same component

void DFS_1(int source){
    check_1[source] = true;
    int sz = adj_1[source].size();

    for(int i=0; i<sz; i++){
        int u = adj_1[source][i];
        if(!check_1[u]){
            DFS_1(u);
        }
    }
    st.push(source);
}

void DFS_2(int source, int head){
    check_2[source] = true;
    components[head].push_back(source);
    int sz = adj_2[source].size();

    for(int i=0; i<sz; i++){
        int u = adj_2[source][i];
        if(!check_2[u]) DFS_2(u, head);
    }
}

int main()
{
    int n; cin>>n; //number of edges in the directed graph
    int u, v;
    set<int> s;

    for(int i=0; i<n; i++){
        cin>>u>>v;
        adj_1[u].push_back(v);
        adj_2[v].push_back(u);
        s.insert(u);
        s.insert(v);
    }

    vector<int> nodes(s.begin(), s.end());
    int sz = nodes.size();

    for(int i=0; i<sz; i++){
        int u = nodes[i];
        if(!check_1[u]) DFS_1(u);
    }

    while(!st.empty()){
        int u = st.top();
        st.pop();
        if(!check_2[u]){
            component_head.push_back(u);
            DFS_2(u, u);
        }
    }

    sz = component_head.size();

    cout<<sz<<" components are present in the given graph.\n";

    for(int i=0; i<sz; i++){
        int u = component_head[i];
        int z = components[u].size();

        cout<<"Component "<<i+1<<":";
        for(int j=0; j<z; j++){
            cout<<" "<<components[u][j];
        }
        cout<<endl;
    }

    return 0;
}
